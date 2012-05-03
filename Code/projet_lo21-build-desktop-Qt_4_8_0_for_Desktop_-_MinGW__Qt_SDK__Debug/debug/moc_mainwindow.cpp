/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 2. May 02:09:18 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet_lo21/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      34,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,
     124,   11,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     174,   11,   11,   11, 0x0a,
     199,   11,   11,   11, 0x0a,
     224,   11,   11,   11, 0x0a,
     249,   11,   11,   11, 0x0a,
     274,   11,   11,   11, 0x0a,
     299,   11,   11,   11, 0x0a,
     324,   11,   11,   11, 0x0a,
     349,   11,   11,   11, 0x0a,
     367,   11,   11,   11, 0x0a,
     384,   11,   11,   11, 0x0a,
     402,   11,   11,   11, 0x0a,
     421,   11,   11,   11, 0x0a,
     438,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0ajouterStack(QString)\0"
    "nettoyerList()\0on_pushButton0_clicked()\0"
    "on_pushButton1_clicked()\0"
    "on_pushButton2_clicked()\0"
    "on_pushButton3_clicked()\0"
    "on_pushButton4_clicked()\0"
    "on_pushButton5_clicked()\0"
    "on_pushButton6_clicked()\0"
    "on_pushButton7_clicked()\0"
    "on_pushButton8_clicked()\0"
    "on_pushButton9_clicked()\0"
    "on_stackButton_clicked()\0"
    "on_affichePile_clicked()\0on_swap_clicked()\0"
    "on_sum_clicked()\0on_mean_clicked()\0"
    "on_clear_clicked()\0on_dup_clicked()\0"
    "on_drop_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->ajouterStack((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->nettoyerList(); break;
        case 2: _t->on_pushButton0_clicked(); break;
        case 3: _t->on_pushButton1_clicked(); break;
        case 4: _t->on_pushButton2_clicked(); break;
        case 5: _t->on_pushButton3_clicked(); break;
        case 6: _t->on_pushButton4_clicked(); break;
        case 7: _t->on_pushButton5_clicked(); break;
        case 8: _t->on_pushButton6_clicked(); break;
        case 9: _t->on_pushButton7_clicked(); break;
        case 10: _t->on_pushButton8_clicked(); break;
        case 11: _t->on_pushButton9_clicked(); break;
        case 12: _t->on_stackButton_clicked(); break;
        case 13: _t->on_affichePile_clicked(); break;
        case 14: _t->on_swap_clicked(); break;
        case 15: _t->on_sum_clicked(); break;
        case 16: _t->on_mean_clicked(); break;
        case 17: _t->on_clear_clicked(); break;
        case 18: _t->on_dup_clicked(); break;
        case 19: _t->on_drop_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::ajouterStack(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::nettoyerList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
