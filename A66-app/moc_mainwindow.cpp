/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Aug 25 19:18:43 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,
      49,   11,   11,   11, 0x05,
      68,   11,   11,   11, 0x05,
      87,   11,   11,   11, 0x05,
     108,   11,   11,   11, 0x05,
     134,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     155,   11,   11,   11, 0x0a,
     173,   11,   11,   11, 0x0a,
     191,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     245,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     299,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     353,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openStepWidget()\0"
    "openProgramWidget()\0openMouldsWidget()\0"
    "openManualWidget()\0openRunStateWidget()\0"
    "openSystemSettingWidget()\0"
    "openEasyBendWidget()\0ReturnProgramdb()\0"
    "ReFlashProgName()\0on_pushButton_T3_clicked()\0"
    "on_pushButton_T2_clicked()\0"
    "on_toolButton_B0_clicked()\0"
    "on_toolButton_B1_clicked()\0"
    "on_toolButton_B2_clicked()\0"
    "on_toolButton_B3_clicked()\0"
    "on_toolButton_B4_clicked()\0"
    "on_toolButton_B5_clicked()\0"
    "on_toolButton_Start_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openStepWidget(); break;
        case 1: openProgramWidget(); break;
        case 2: openMouldsWidget(); break;
        case 3: openManualWidget(); break;
        case 4: openRunStateWidget(); break;
        case 5: openSystemSettingWidget(); break;
        case 6: openEasyBendWidget(); break;
        case 7: ReturnProgramdb(); break;
        case 8: ReFlashProgName(); break;
        case 9: on_pushButton_T3_clicked(); break;
        case 10: on_pushButton_T2_clicked(); break;
        case 11: on_toolButton_B0_clicked(); break;
        case 12: on_toolButton_B1_clicked(); break;
        case 13: on_toolButton_B2_clicked(); break;
        case 14: on_toolButton_B3_clicked(); break;
        case 15: on_toolButton_B4_clicked(); break;
        case 16: on_toolButton_B5_clicked(); break;
        case 17: on_toolButton_Start_clicked(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openStepWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainWindow::openProgramWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::openMouldsWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::openManualWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::openRunStateWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainWindow::openSystemSettingWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainWindow::openEasyBendWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
