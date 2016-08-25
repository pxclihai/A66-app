/****************************************************************************
** Meta object code from reading C++ file 'moulds.h'
**
** Created: Thu Aug 25 19:18:45 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "moulds.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moulds.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Moulds[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      31,   29,   24,    7, 0x0a,
      61,    7,    7,    7, 0x0a,
      90,    7,    7,    7, 0x0a,
     121,    7,    7,    7, 0x0a,
     151,    7,    7,    7, 0x0a,
     181,    7,    7,    7, 0x08,
     211,    7,    7,    7, 0x08,
     241,    7,    7,    7, 0x08,
     270,    7,    7,    7, 0x08,
     301,    7,    7,    7, 0x08,
     330,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x08,
     391,    7,    7,    7, 0x08,
     421,    7,    7,    7, 0x08,
     458,    7,    7,    7, 0x08,
     494,    7,    7,    7, 0x08,
     531,    7,    7,    7, 0x08,
     571,    7,    7,    7, 0x08,
     608,    7,    7,    7, 0x08,
     640,    7,    7,    7, 0x08,
     676,    7,    7,    7, 0x08,
     713,    7,    7,    7, 0x08,
     749,    7,    7,    7, 0x08,
     788,    7,    7,    7, 0x08,
     828,    7,    7,    7, 0x08,
     878,    7,    7,    7, 0x08,
     925,    7,    7,    7, 0x08,
     956,    7,    7,    7, 0x08,
     987,    7,    7,    7, 0x08,
    1018,    7,    7,    7, 0x08,
    1049,    7,    7,    7, 0x08,
    1081,    7,    7,    7, 0x08,
    1112,    7,    7,    7, 0x08,
    1143,    7,    7,    7, 0x08,
    1175,    7,    7,    7, 0x08,
    1222,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Moulds[] = {
    "Moulds\0\0openMouldsWin()\0bool\0,\0"
    "eventFilter(QObject*,QEvent*)\0"
    "on_pushButton_M_Up_clicked()\0"
    "on_pushButton_M_Down_clicked()\0"
    "on_pushButton_M_New_clicked()\0"
    "on_pushButton_M_Del_clicked()\0"
    "on_pushButton_U_New_clicked()\0"
    "on_pushButton_U_Del_clicked()\0"
    "on_pushButton_U_Up_clicked()\0"
    "on_pushButton_U_Down_clicked()\0"
    "on_pushButton_D_Up_clicked()\0"
    "on_pushButton_D_Down_clicked()\0"
    "on_pushButton_D_New_clicked()\0"
    "on_pushButton_D_Del_clicked()\0"
    "on_lineEdit_U_Height_returnPressed()\0"
    "on_lineEdit_U_Angle_returnPressed()\0"
    "on_lineEdit_U_Radius_returnPressed()\0"
    "on_lineEdit_U_Impedance_returnPressed()\0"
    "on_lineEdit_D_Height_returnPressed()\0"
    "on_lineEdit_D_V_returnPressed()\0"
    "on_lineEdit_D_Angle_returnPressed()\0"
    "on_lineEdit_D_Radius_returnPressed()\0"
    "on_lineEdit_D_Speed_returnPressed()\0"
    "on_lineEdit_D_XCorrect_returnPressed()\0"
    "on_lineEdit_D_Impedance_returnPressed()\0"
    "on_tableWidget_LowerMoulds_itemSelectionChanged()\0"
    "on_tableWidget_UpMoulds_itemSelectionChanged()\0"
    "on_pushButton_Left_1_clicked()\0"
    "on_pushButton_Left_4_clicked()\0"
    "on_pushButton_Left_2_clicked()\0"
    "on_pushButton_Left_3_clicked()\0"
    "on_pushButton_Left_12_clicked()\0"
    "on_pushButton_Left_9_clicked()\0"
    "on_pushButton_Left_8_clicked()\0"
    "on_pushButton_Left_10_clicked()\0"
    "on_tableWidget_Material_itemSelectionChanged()\0"
    "on_lineEdit_Strengrht_returnPressed()\0"
};

const QMetaObject Moulds::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Moulds,
      qt_meta_data_Moulds, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Moulds::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Moulds::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Moulds::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Moulds))
        return static_cast<void*>(const_cast< Moulds*>(this));
    return QWidget::qt_metacast(_clname);
}

int Moulds::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openMouldsWin(); break;
        case 1: { bool _r = eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: on_pushButton_M_Up_clicked(); break;
        case 3: on_pushButton_M_Down_clicked(); break;
        case 4: on_pushButton_M_New_clicked(); break;
        case 5: on_pushButton_M_Del_clicked(); break;
        case 6: on_pushButton_U_New_clicked(); break;
        case 7: on_pushButton_U_Del_clicked(); break;
        case 8: on_pushButton_U_Up_clicked(); break;
        case 9: on_pushButton_U_Down_clicked(); break;
        case 10: on_pushButton_D_Up_clicked(); break;
        case 11: on_pushButton_D_Down_clicked(); break;
        case 12: on_pushButton_D_New_clicked(); break;
        case 13: on_pushButton_D_Del_clicked(); break;
        case 14: on_lineEdit_U_Height_returnPressed(); break;
        case 15: on_lineEdit_U_Angle_returnPressed(); break;
        case 16: on_lineEdit_U_Radius_returnPressed(); break;
        case 17: on_lineEdit_U_Impedance_returnPressed(); break;
        case 18: on_lineEdit_D_Height_returnPressed(); break;
        case 19: on_lineEdit_D_V_returnPressed(); break;
        case 20: on_lineEdit_D_Angle_returnPressed(); break;
        case 21: on_lineEdit_D_Radius_returnPressed(); break;
        case 22: on_lineEdit_D_Speed_returnPressed(); break;
        case 23: on_lineEdit_D_XCorrect_returnPressed(); break;
        case 24: on_lineEdit_D_Impedance_returnPressed(); break;
        case 25: on_tableWidget_LowerMoulds_itemSelectionChanged(); break;
        case 26: on_tableWidget_UpMoulds_itemSelectionChanged(); break;
        case 27: on_pushButton_Left_1_clicked(); break;
        case 28: on_pushButton_Left_4_clicked(); break;
        case 29: on_pushButton_Left_2_clicked(); break;
        case 30: on_pushButton_Left_3_clicked(); break;
        case 31: on_pushButton_Left_12_clicked(); break;
        case 32: on_pushButton_Left_9_clicked(); break;
        case 33: on_pushButton_Left_8_clicked(); break;
        case 34: on_pushButton_Left_10_clicked(); break;
        case 35: on_tableWidget_Material_itemSelectionChanged(); break;
        case 36: on_lineEdit_Strengrht_returnPressed(); break;
        default: ;
        }
        _id -= 37;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
