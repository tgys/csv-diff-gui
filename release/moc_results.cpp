/****************************************************************************
** Meta object code from reading C++ file 'results.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../results.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'results.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Results_t {
    QByteArrayData data[19];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Results_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Results_t qt_meta_stringdata_Results = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Results"
QT_MOC_LITERAL(1, 8, 25), // "onNewUpdateResultsChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "QList<QStandardItem*>"
QT_MOC_LITERAL(4, 57, 8), // "itemsOne"
QT_MOC_LITERAL(5, 66, 8), // "itemsTwo"
QT_MOC_LITERAL(6, 75, 7), // "row_one"
QT_MOC_LITERAL(7, 83, 7), // "row_two"
QT_MOC_LITERAL(8, 91, 7), // "col_one"
QT_MOC_LITERAL(9, 99, 7), // "col_two"
QT_MOC_LITERAL(10, 107, 14), // "QStandardItem&"
QT_MOC_LITERAL(11, 122, 8), // "item_one"
QT_MOC_LITERAL(12, 131, 8), // "item_two"
QT_MOC_LITERAL(13, 140, 8), // "QString&"
QT_MOC_LITERAL(14, 149, 5), // "text1"
QT_MOC_LITERAL(15, 155, 5), // "text2"
QT_MOC_LITERAL(16, 161, 24), // "onNewUpdateResultsExtras"
QT_MOC_LITERAL(17, 186, 10), // "one_or_two"
QT_MOC_LITERAL(18, 197, 5) // "items"

    },
    "Results\0onNewUpdateResultsChanged\0\0"
    "QList<QStandardItem*>\0itemsOne\0itemsTwo\0"
    "row_one\0row_two\0col_one\0col_two\0"
    "QStandardItem&\0item_one\0item_two\0"
    "QString&\0text1\0text2\0onNewUpdateResultsExtras\0"
    "one_or_two\0items"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Results[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,   10,   24,    2, 0x0a /* Public */,
      16,    2,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 13, 0x80000000 | 13,    4,    5,    6,    7,    8,    9,   11,   12,   14,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,   17,   18,

       0        // eod
};

void Results::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Results *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewUpdateResultsChanged((*reinterpret_cast< QList<QStandardItem*>(*)>(_a[1])),(*reinterpret_cast< QList<QStandardItem*>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QStandardItem(*)>(_a[7])),(*reinterpret_cast< QStandardItem(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10]))); break;
        case 1: _t->onNewUpdateResultsExtras((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QStandardItem*>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Results::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Results.data,
    qt_meta_data_Results,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Results::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Results::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Results.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Results::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
