#include "global.h"


#define DEV_PATH "/sys/class/gpio/"

int ProgIndex=0;
int ProgNameNum=1;
int StepIndex=0;
int CurrentStep=1;
int UpMoldIndex;
int LowerMoldIndex;

int UpMoldNum=1;
int LowerMoldNum=1;
int ManualSpeedValue = 10000;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  //采用QSQLITE数据库

struct Stepdata CurrentStepTemp;
struct ProgramFiles  CurrentProgramTemp;
struct UpMoldData CurrentUpMoldTemp;
struct LowerMoldData  CurrentLowerMoldTemp;
struct _CURRENTREG CurrentReg;
struct _VALUESTATE ValveReg;
struct MaterialData  CurrentMaterialTemp;

void openBeep()
{
    system("echo 113 >"DEV_PATH"export");
    system("echo out >"DEV_PATH"gpio113/direction");
    system("echo 1 >> "DEV_PATH"gpio113/value");
    system("echo 113 >"DEV_PATH"unexport");
}

void Sql_Init()
{
    db.setHostName("localhost"); //设置数据库主机名
    db.setDatabaseName("/opt/tetra/A66-app/A66-app.db"); //设置数据库名
    db.setUserName("root");//设置数据库登入用户名
    db.setPassword("123456");//设计数据库登入密码
}



Global::Global(QWidget *parent) :
    QWidget(parent)
{
}



