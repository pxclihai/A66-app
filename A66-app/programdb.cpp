#include "programdb.h"
#include "ui_programdb.h"
#include <QDebug>
#include "global.h"
#include "qsoftkeyboard.h"
#include "qsoftkeyvalue.h"
#include "programname.h"
#include "step.h"
#include "chooselowermolddialog.h"
#include "chooseupmolddialog.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "runstate.h"

Programdb::Programdb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Programdb)
{
    ui->setupUi(this);

    initProgram();

    //******NEW********//
    ui->tableWidget_Programdb->setColumnWidth(Program_Id,80);
    ui->tableWidget_Programdb->setColumnWidth(Program_Name,300);
    ui->tableWidget_Programdb->setColumnWidth(Program_BoardThick,100);
    ui->tableWidget_Programdb->setColumnWidth(Program_Material,70);
    ui->tableWidget_Programdb->setColumnWidth(Program_LowerMold,70);
    ui->tableWidget_Programdb->setColumnWidth(Program_UpMold,70);

   // ui->tableWidget_Programdb->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui->tableWidget_Programdb->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_Programdb->horizontalHeader()->setClickable(false);    //******NEW********//



}

Programdb::~Programdb()
{
    delete ui;
}

void Programdb::openProgramWin()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
    this->move(0,WIDGET_Y);
    ui->tableWidget_Programdb->selectRow(CurrentReg.Current_ProgramLibRow);
    Display_ProgramItem();
}

void Programdb::initProgram(void)
{
    qDebug()<<"Enter Program data base initial Window!"<<endl;

    Display_ProgramItem();
    CurrentReg.Current_ProgramLibRow=0;
    ui->tableWidget_Programdb->selectRow(CurrentReg.Current_ProgramLibRow);

    CurrentReg.CurrentProgramName = ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Name)->text();
//初始化lineEdit


    ui->lineEdit_P_boardThickness->setText(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_BoardThick)->text());
    ui->lineEdit_P_UpMolds->setText(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_UpMold)->text());
    ui->lineEdit_P_LowerMolds->setText(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_LowerMold)->text());
    ui->lineEdit_P_Total->setText(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_ProcessNum)->text());

    ui->comboBox_P_material->addItem(trUtf8("铝"));
    ui->comboBox_P_material->addItem(trUtf8("铁"));
    ui->comboBox_P_material->addItem(trUtf8("不绣钢"));


}

void Programdb::ReflashProgramWrokedNum(int Num)
{
    qDebug("-sw-----------------------------------------------------------------------------");
    qDebug("WorkedTotal %d ", Num);
    qDebug("CurrentReg.Current_ProgramLibRow %d ", CurrentReg.Current_ProgramLibRow);

  // ui->tableWidget_Programdb->setItem(CurrentReg.Current_ProgramLibRow,Program_ProcessNum,new QTableWidgetItem(QString::number(Num,10)));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_ProcessNum,QString::number( Num,10));

}


void Programdb::Display_ProgramItem()
{
    bool ok;

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Error"),
                              db.lastError().text());//打开数据库连接
    }
    QSqlTableModel modelStep_temp;
    QSqlTableModel model_temp;
    QSqlTableModel model;
    model.setTable("ProgramLib");
    //model.setFilter("ID > 0");
    model.select();

    if(model.rowCount()!=0)
    {
        ui->tableWidget_Programdb->setRowCount(model.rowCount());
    }
    else
    {
        ui->tableWidget_Programdb->setRowCount(1);
        ui->tableWidget_Programdb->clear();
    }

    for(int i=0;i<model.rowCount();i++)
    {
            QSqlRecord record = model.record(i);

            ui->tableWidget_Programdb->setItem(i,Program_Id,new QTableWidgetItem(record.value("Id").toString()));
            ui->tableWidget_Programdb->setItem(i,Program_Name,new QTableWidgetItem(record.value("Name").toString()));
            ui->tableWidget_Programdb->setItem(i,Program_BoardThick,new QTableWidgetItem(QString::number(record.value("BoardThick").toDouble(&ok),10,2)));//******NEW********//
            if(record.value("Material") == 1)
            {
                ui->tableWidget_Programdb->setItem(i,Program_Material,new QTableWidgetItem(trUtf8("铝")));
            }else if(record.value("Material") == 2)
            {
              ui->tableWidget_Programdb->setItem(i,Program_Material,new QTableWidgetItem(trUtf8("铁")));
            }else if(record.value("Material") == 3)
            {
               ui->tableWidget_Programdb->setItem(i,Program_Material,new QTableWidgetItem(trUtf8("不绣钢")));
            }
            ui->tableWidget_Programdb->setItem(i,Program_LowerMold,new QTableWidgetItem(record.value("LowerMold").toString() ));//+ "/" + record.value("UpMold").toString()
            ui->tableWidget_Programdb->setItem(i,Program_UpMold,new QTableWidgetItem(record.value("UpMold").toString()));
            ui->tableWidget_Programdb->setItem(i,Program_ProcessNum,new QTableWidgetItem(record.value("WorkedTotal").toString()));

            model_temp.setTable(record.value("Name").toString());
            //model_temp.setFilter();
            model_temp.select();
            ui->tableWidget_Programdb->setItem(i,Program_StepNum,new QTableWidgetItem(QString::number( model_temp.rowCount(),10)));
            QString StepNum_str = QString::number( model_temp.rowCount(),10);
            modelStep_temp.setTable("ProgramLib");
            modelStep_temp.setFilter("ID = " + QString::number(i+1,10));
            modelStep_temp.select();
            if(modelStep_temp.rowCount() == 1)
            {
                QSqlRecord record = modelStep_temp.record(0);
                record.setValue("StepTotal",StepNum_str);
                modelStep_temp.setRecord(0,record);
                modelStep_temp.submitAll();
            }
            qDebug()<<"StepNum_str"<<StepNum_str;
    }
    db.close();//释放数据库

}


bool  Programdb::NewProgramLib(QString str)
{
   if(!db.open())
   {
       QMessageBox::critical(0,QObject::tr("Error"),
                             db.lastError().text());//打开数据库连接
   }

   if(str == "")    //输入不能为空
   {
       emit sig_NewisEmpty();
       return 0;
   }

   QSqlTableModel model;
   model.setTable("ProgramLib");
  // model.setFilter("Name" + str);
   model.select();


   for(int i=0;i<model.rowCount();i++)
   {
       QSqlRecord record = model.record(i);
       if(record.value("Name").toString().compare(str) == 0 )
       {
           emit sig_MulName();    //输入不能重复
           return 0;
       }
   }


   QSqlQuery query;

   query.exec("CREATE TABLE "+ str +"("  \
              "ID INTEGER PRIMARY KEY    ," \
              "Angle               NUMERIC    ," \
              "AngleCompensate     NUMERIC    ," \
              "Yaxis               NUMERIC    ," \
              "Xaxis               NUMERIC    ," \
              "XaxisCorrect        NUMERIC    ," \
              "Distance            NUMERIC    ," \
              "Pressure            NUMERIC    ," \
              "ReturnTime          NUMERIC    ," \
              "Holding             NUMERIC    ," \
              "Raxis               NUMERIC    );");

    query.exec(" INSERT  INTO "+ str +"(ID,Angle,AngleCompensate,Yaxis,Xaxis,XaxisCorrect,Distance,Pressure,ReturnTime,Holding,Raxis) VALUES ( 1,90,10,10,20,1,20,30,1,1,20)");

   //QSqlTableModel model;
   model.setTable("ProgramLib");
   int row = 0;
   model.insertRows(row,1);
   model.setData(model.index(row,Program_Name),str);
   model.setData(model.index(row,Program_StepNum),"1");
   model.setData(model.index(row,Program_BoardThick),ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_BoardThick)->text());
   model.setData(model.index(row,Program_Material),ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Material)->text());
   model.setData(model.index(row,Program_UpMold),ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_UpMold)->text());
   model.setData(model.index(row,Program_LowerMold),ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_LowerMold)->text());
   model.setData(model.index(row,Program_ProcessNum),"0");

   model.submitAll();
   db.close();//释放数据库

   emit sig_NewClose();
   Display_ProgramItem();
   ui->tableWidget_Programdb->selectRow(ui->tableWidget_Programdb->rowCount()-1);


}


void  Programdb::DeleteProgramLib()
{
    QString CurrentProgramId = ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text();
   if(!db.open())
   {
       QMessageBox::critical(0,QObject::tr("Error"),
                             db.lastError().text());//打开数据库连接
   }

   QSqlTableModel model;
   model.setTable("ProgramLib");
   model.setFilter("ID ="+ CurrentProgramId);
   model.select();
   if(model.rowCount() == 1)
   {
       model.removeRows(0,1);
       model.submitAll();
   }

   QSqlQuery query;

   query.exec("DROP TABLE " + ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Name)->text());

   query.exec("UPDATE ProgramLib SET ID = ID - 1 WHERE ID > " + QString::number(CurrentReg.Current_ProgramLibRow,10));
   db.close();//释放数据库

}


void Programdb::Update_ProgramLibItem(int Id,int Col,QString Value)
{
    QString Str_Id=QString::number(Id,10);

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Error"),
                              db.lastError().text());//打开数据库连接
    }


    QSqlTableModel model;
    model.setTable("ProgramLib");
    model.setFilter("ID = " + Str_Id);
    model.select();
    if(model.rowCount() == 1)
    {
        QSqlRecord record = model.record(0);
        switch(Col)
        {
        case Program_Name:record.setValue("Name",Value);
            break;
        case Program_StepNum:record.setValue("StepTotal",Value);
            break;
        case Program_BoardThick:record.setValue("BoardThick",Value);
            break;
        case Program_Material:record.setValue("Material",Value);
            break;
        case Program_UpMold:record.setValue("LowerMold",Value);
            break;
        case Program_LowerMold:record.setValue("UpMold",Value);
            break;
        case Program_ProcessNum:record.setValue("WorkedTotal",Value);
            break;

        default :break;
        }

        model.setRecord(0,record);
        model.submitAll();
    }

    db.close();//释放数据库
}


void Programdb::on_tableWidget_Programdb_itemSelectionChanged()
{

   QString CurrentProgramMoldId = ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text();
   CurrentReg.CurrentProgramName = ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Name)->text();

   if(!db.open())
   {
       QMessageBox::critical(0,QObject::tr("Error"),
                             db.lastError().text());//打开数据库连接
   }

   QSqlTableModel model;
   model.setTable("ProgramLib");
   model.setFilter("ID = " +CurrentProgramMoldId);
   model.select();

   for(int i=0;i<model.rowCount();i++)
   {
           QSqlRecord record = model.record(i);

           ui->lineEdit_P_boardThickness->setText(record.value("BoardThick").toString());
           ui->lineEdit_P_UpMolds->setText(record.value("LowerMold").toString());
           ui->lineEdit_P_LowerMolds->setText(record.value("UpMold").toString());
           ui->lineEdit_P_Total->setText(record.value("WorkedTotal").toString());
           //qDebug()<<"record.value().toString()"<<record.value("Id").toString();
   }
   CurrentReg.Current_ProgramLibRow = ui->tableWidget_Programdb->currentRow();


   QPixmap pix;
   pix.load("PIC/P01.jpg");

   ui->label_pic->setPixmap(pix);

   db.close();//释放数据库

   emit ReflashProgram();

}

//工步编程tableWidget_Programdb和lineEdit_P建立链接
void Programdb::on_lineEdit_P_boardThickness_returnPressed()
{
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(), Program_BoardThick, new QTableWidgetItem(ui->lineEdit_P_boardThickness->text()));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_BoardThick,ui->lineEdit_P_boardThickness->text());
}
void Programdb::on_comboBox_P_material_currentIndexChanged(const QString &arg1)
{
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(), Program_Material, new QTableWidgetItem(ui->comboBox_P_material->currentText()));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_Material,QString::number(ui->comboBox_P_material->currentIndex(),10));
}
void Programdb::on_lineEdit_P_UpMolds_returnPressed()
{
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(), Program_UpMold, new QTableWidgetItem(ui->lineEdit_P_UpMolds->text()));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_UpMold,ui->lineEdit_P_UpMolds->text());
}
void Programdb::on_lineEdit_P_LowerMolds_returnPressed()
{
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(), Program_LowerMold, new QTableWidgetItem(ui->lineEdit_P_LowerMolds->text()));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_LowerMold,ui->lineEdit_P_LowerMolds->text());
}
void Programdb::on_lineEdit_P_Total_returnPressed()
{
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(), Program_ProcessNum, new QTableWidgetItem(ui->lineEdit_P_Total->text()));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_ProcessNum,ui->lineEdit_P_Total->text());
}

void Programdb::on_pushButton_clicked()
{
    chooseUpMoldDialog *UM = new chooseUpMoldDialog;
    UM->move(200,200);
    connect(UM, SIGNAL(sig_sndUpMold(int)), this, SLOT(UpMoldDialog(int)));
    UM->exec();

}

void Programdb::on_pushButton_2_clicked()
{
    chooseLowerMoldDialog *LM =new chooseLowerMoldDialog;
    LM->move(200,200);
    connect(LM, SIGNAL(sig_sndLowerMold(int)), this, SLOT(LowerMoldDialog(int)));
    LM->exec();
}

void Programdb::LowerMoldDialog(int num)
{
    qDebug("num: %d,num");
    ui->lineEdit_P_LowerMolds->setText(QString::number(num,10));
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(),Program_LowerMold,new QTableWidgetItem(QString::number(num,10)));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_LowerMold,ui->lineEdit_P_LowerMolds->text());

}

void Programdb::UpMoldDialog(int num)
{
    qDebug("num: %d,num");
    ui->lineEdit_P_UpMolds->setText(QString::number(num,10));
    ui->tableWidget_Programdb->setItem(ui->tableWidget_Programdb->currentRow(),Program_UpMold,new QTableWidgetItem(QString::number(num,10)));
    Update_ProgramLibItem(ui->tableWidget_Programdb->item(ui->tableWidget_Programdb->currentRow(),Program_Id)->text().toInt(),Program_UpMold,ui->lineEdit_P_UpMolds->text());
}


void Programdb::on_pushButton_Left_4_clicked()//程序库向下按钮
{
    if(ui->tableWidget_Programdb->currentRow()==ui->tableWidget_Programdb->rowCount()-1)
    {
       ui->tableWidget_Programdb->selectRow(0);
    }
    else
    {
       ui->tableWidget_Programdb->selectRow(ui->tableWidget_Programdb->currentRow()+1);
    }
}

void Programdb::on_pushButton_Left_1_clicked()//程序库向上按钮
{
    if(ui->tableWidget_Programdb->currentRow()==0)
    {
       ui->tableWidget_Programdb->selectRow(ui->tableWidget_Programdb->rowCount()-1);
    }
    else
    {
       ui->tableWidget_Programdb->selectRow(ui->tableWidget_Programdb->currentRow()-1);
    }
}

void Programdb::on_pushButton_Left_2_clicked()
{
    ProgramName  *ProgramName1=new ProgramName;
//    ProgramName1->setWindowFlags(Qt::FramelessWindowHint);
    ProgramName1->move(200,250);
    connect(ProgramName1, SIGNAL(sig_sndNewName(QString)), this, SLOT(NewProgramLib(QString)));
    connect(this, SIGNAL(sig_NewisEmpty()), ProgramName1, SLOT(ProNewisEmpty()));
    connect(this, SIGNAL(sig_NewClose()), ProgramName1, SLOT(ProNewClose()));
    connect(this, SIGNAL(sig_MulName()), ProgramName1, SLOT(ProNewMulName()));
    ProgramName1->exec();
}


void Programdb::on_pushButton_Left_3_clicked()
{
    if(ui->tableWidget_Programdb->rowCount()>1)
    {
        DeleteProgramLib();
        Display_ProgramItem();
    }
}
