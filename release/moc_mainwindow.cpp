/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "newUpdateResultsChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "QList<QStandardItem*>"
QT_MOC_LITERAL(4, 58, 8), // "itemsOne"
QT_MOC_LITERAL(5, 67, 8), // "itemsTwo"
QT_MOC_LITERAL(6, 76, 7), // "row_one"
QT_MOC_LITERAL(7, 84, 7), // "row_two"
QT_MOC_LITERAL(8, 92, 7), // "col_one"
QT_MOC_LITERAL(9, 100, 7), // "col_two"
QT_MOC_LITERAL(10, 108, 14), // "QStandardItem&"
QT_MOC_LITERAL(11, 123, 8), // "item_one"
QT_MOC_LITERAL(12, 132, 8), // "item_two"
QT_MOC_LITERAL(13, 141, 8), // "QString&"
QT_MOC_LITERAL(14, 150, 5), // "text1"
QT_MOC_LITERAL(15, 156, 5), // "text2"
QT_MOC_LITERAL(16, 162, 22), // "newUpdateResultsExtras"
QT_MOC_LITERAL(17, 185, 10), // "one_or_two"
QT_MOC_LITERAL(18, 196, 5), // "items"
QT_MOC_LITERAL(19, 202, 19), // "onNewTextOneEntered"
QT_MOC_LITERAL(20, 222, 4), // "text"
QT_MOC_LITERAL(21, 227, 19), // "onNewTextTwoEntered"
QT_MOC_LITERAL(22, 247, 18), // "onNewUpdatePressed"
QT_MOC_LITERAL(23, 266, 14), // "onNewOkColumns"
QT_MOC_LITERAL(24, 281, 11) // "onNewOkKeys"

    },
    "MainWindow\0newUpdateResultsChanged\0\0"
    "QList<QStandardItem*>\0itemsOne\0itemsTwo\0"
    "row_one\0row_two\0col_one\0col_two\0"
    "QStandardItem&\0item_one\0item_two\0"
    "QString&\0text1\0text2\0newUpdateResultsExtras\0"
    "one_or_two\0items\0onNewTextOneEntered\0"
    "text\0onNewTextTwoEntered\0onNewUpdatePressed\0"
    "onNewOkColumns\0onNewOkKeys"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   10,   49,    2, 0x06 /* Public */,
      16,    2,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,   75,    2, 0x0a /* Public */,
      21,    1,   78,    2, 0x0a /* Public */,
      22,    0,   81,    2, 0x0a /* Public */,
      23,    0,   82,    2, 0x0a /* Public */,
      24,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 13, 0x80000000 | 13,    4,    5,    6,    7,    8,    9,   11,   12,   14,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,   17,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newUpdateResultsChanged((*reinterpret_cast< QList<QStandardItem*>(*)>(_a[1])),(*reinterpret_cast< QList<QStandardItem*>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QStandardItem(*)>(_a[7])),(*reinterpret_cast< QStandardItem(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 1: _t->newUpdateResultsExtras((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QStandardItem*>(*)>(_a[2]))); break;
        case 2: _t->onNewTextOneEntered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onNewTextTwoEntered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onNewUpdatePressed(); break;
        case 5: _t->onNewOkColumns(); break;
        case 6: _t->onNewOkKeys(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QList<QStandardItem*> , QList<QStandardItem*> , int , int , int , int , QStandardItem & , QStandardItem & , QString & , QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newUpdateResultsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , QList<QStandardItem*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newUpdateResultsExtras)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::newUpdateResultsChanged(QList<QStandardItem*> _t1, QList<QStandardItem*> _t2, int _t3, int _t4, int _t5, int _t6, QStandardItem & _t7, QStandardItem & _t8, QString & _t9, QString & _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::newUpdateResultsExtras(int _t1, QList<QStandardItem*> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
