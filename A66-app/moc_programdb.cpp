/****************************************************************************
** Meta object code from reading C++ file 'programdb.h'
**
** Created: Thu Aug 25 17:44:36 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "programdb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'programdb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Programdb[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      28,   10,   10,   10, 0x05,
      43,   10,   10,   10, 0x05,
      57,   10,   10,   10, 0x05,
      75,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   10,   10,   10, 0x0a,
     118,  114,  109,   10, 0x0a,
     145,  141,   10,   10, 0x0a,
     178,  174,   10,   10, 0x0a,
     199,  174,   10,   10, 0x0a,
     217,   10,   10,   10, 0x08,
     262,   10,   10,   10, 0x08,
     300,   10,   10,   10, 0x08,
     341,   10,   10,   10, 0x08,
     382,  377,   10,   10, 0x08,
     434,   10,   10,   10, 0x08,
     482,   10,   10,   10, 0x08,
     506,   10,   10,   10, 0x08,
     532,   10,   10,   10, 0x08,
     563,   10,   10,   10, 0x08,
     594,   10,   10,   10, 0x08,
     625,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Programdb[] = {
    "Programdb\0\0sig_NewisEmpty()\0sig_NewClose()\0"
    "sig_MulName()\0Sig_NewStepData()\0"
    "ReflashProgram()\0openProgramWin()\0"
    "bool\0str\0NewProgramLib(QString)\0Num\0"
    "ReflashProgramWrokedNum(int)\0num\0"
    "LowerMoldDialog(int)\0UpMoldDialog(int)\0"
    "on_lineEdit_P_boardThickness_returnPressed()\0"
    "on_lineEdit_P_UpMolds_returnPressed()\0"
    "on_lineEdit_P_LowerMolds_returnPressed()\0"
    "on_lineEdit_P_Total_returnPressed()\0"
    "arg1\0on_comboBox_P_material_currentIndexChanged(QString)\0"
    "on_tableWidget_Programdb_itemSelectionChanged()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_Left_4_clicked()\0"
    "on_pushButton_Left_1_clicked()\0"
    "on_pushButton_Left_2_clicked()\0"
    "on_pushButton_Left_3_clicked()\0"
};

const QMetaObject Programdb::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Programdb,
      qt_meta_data_Programdb, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Programdb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Programdb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Programdb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Programdb))
        return static_cast<void*>(const_cast< Programdb*>(this));
    return QWidget::qt_metacast(_clname);
}

int Programdb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sig_NewisEmpty(); break;
        case 1: sig_NewClose(); break;
        case 2: sig_MulName(); break;
        case 3: Sig_NewStepData(); break;
        case 4: ReflashProgram(); break;
        case 5: openProgramWin(); break;
        case 6: { bool _r = NewProgramLib((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: ReflashProgramWrokedNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: LowerMoldDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: UpMoldDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_lineEdit_P_boardThickness_returnPressed(); break;
        case 11: on_lineEdit_P_UpMolds_returnPressed(); break;
        case 12: on_lineEdit_P_LowerMolds_returnPressed(); break;
        case 13: on_lineEdit_P_Total_returnPressed(); break;
        case 14: on_comboBox_P_material_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: on_tableWidget_Programdb_itemSelectionChanged(); break;
        case 16: on_pushButton_clicked(); break;
        case 17: on_pushButton_2_clicked(); break;
        case 18: on_pushButton_Left_4_clicked(); break;
        case 19: on_pushButton_Left_1_clicked(); break;
        case 20: on_pushButton_Left_2_clicked(); break;
        case 21: on_pushButton_Left_3_clicked(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Programdb::sig_NewisEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Programdb::sig_NewClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Programdb::sig_MulName()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Programdb::Sig_NewStepData()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Programdb::ReflashProgram()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
