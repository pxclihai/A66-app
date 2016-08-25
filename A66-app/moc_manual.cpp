/****************************************************************************
** Meta object code from reading C++ file 'manual.h'
**
** Created: Thu Aug 25 10:40:38 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manual.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manual.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Manual[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      24,    7,    7,    7, 0x0a,
      43,   39,    7,    7, 0x0a,
      74,   39,    7,    7, 0x0a,
     105,   39,    7,    7, 0x0a,
     136,    7,    7,    7, 0x08,
     161,    7,    7,    7, 0x08,
     193,    7,    7,    7, 0x08,
     226,    7,    7,    7, 0x08,
     261,    7,    7,    7, 0x08,
     297,    7,    7,    7, 0x08,
     329,    7,    7,    7, 0x08,
     362,    7,    7,    7, 0x08,
     397,    7,    7,    7, 0x08,
     433,    7,    7,    7, 0x08,
     464,    7,    7,    7, 0x08,
     493,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Manual[] = {
    "Manual\0\0openManualWin()\0XMotorThread()\0"
    "str\0ChangeXCurrentPostion(QString)\0"
    "ChangeYCurrentPostion(QString)\0"
    "ChangeRCurrentPostion(QString)\0"
    "timerEvent(QTimerEvent*)\0"
    "on_pushButton_M_XBack_pressed()\0"
    "on_pushButton_M_XBack_released()\0"
    "on_pushButton_M_XForWard_pressed()\0"
    "on_pushButton_M_XForWard_released()\0"
    "on_pushButton_M_YBack_pressed()\0"
    "on_pushButton_M_YBack_released()\0"
    "on_pushButton_M_YForWard_pressed()\0"
    "on_pushButton_M_YForWard_released()\0"
    "on_pushButton_Adjust_clicked()\0"
    "on_pushButton_B6_7_clicked()\0"
    "on_pushButton_B6_3_clicked()\0"
};

const QMetaObject Manual::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Manual,
      qt_meta_data_Manual, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Manual::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Manual::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Manual::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Manual))
        return static_cast<void*>(const_cast< Manual*>(this));
    return QWidget::qt_metacast(_clname);
}

int Manual::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openManualWin(); break;
        case 1: XMotorThread(); break;
        case 2: ChangeXCurrentPostion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: ChangeYCurrentPostion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: ChangeRCurrentPostion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 6: on_pushButton_M_XBack_pressed(); break;
        case 7: on_pushButton_M_XBack_released(); break;
        case 8: on_pushButton_M_XForWard_pressed(); break;
        case 9: on_pushButton_M_XForWard_released(); break;
        case 10: on_pushButton_M_YBack_pressed(); break;
        case 11: on_pushButton_M_YBack_released(); break;
        case 12: on_pushButton_M_YForWard_pressed(); break;
        case 13: on_pushButton_M_YForWard_released(); break;
        case 14: on_pushButton_Adjust_clicked(); break;
        case 15: on_pushButton_B6_7_clicked(); break;
        case 16: on_pushButton_B6_3_clicked(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
