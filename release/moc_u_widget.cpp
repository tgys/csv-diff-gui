/****************************************************************************
** Meta object code from reading C++ file 'u_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../u_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'u_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_u_widget_t {
    QByteArrayData data[12];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_u_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_u_widget_t qt_meta_stringdata_u_widget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "u_widget"
QT_MOC_LITERAL(1, 9, 9), // "newOkKeys"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "onNewBoxActivated"
QT_MOC_LITERAL(4, 38, 4), // "text"
QT_MOC_LITERAL(5, 43, 14), // "onNewKeyUpdate"
QT_MOC_LITERAL(6, 58, 14), // "onNewKeyRemove"
QT_MOC_LITERAL(7, 73, 13), // "onNewExUpdate"
QT_MOC_LITERAL(8, 87, 13), // "onNewExRemove"
QT_MOC_LITERAL(9, 101, 20), // "onNewBoxTwoActivated"
QT_MOC_LITERAL(10, 122, 14), // "onNewOkPressed"
QT_MOC_LITERAL(11, 137, 22) // "onNewCancelKeysPressed"

    },
    "u_widget\0newOkKeys\0\0onNewBoxActivated\0"
    "text\0onNewKeyUpdate\0onNewKeyRemove\0"
    "onNewExUpdate\0onNewExRemove\0"
    "onNewBoxTwoActivated\0onNewOkPressed\0"
    "onNewCancelKeysPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_u_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void u_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<u_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newOkKeys(); break;
        case 1: _t->onNewBoxActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onNewKeyUpdate(); break;
        case 3: _t->onNewKeyRemove(); break;
        case 4: _t->onNewExUpdate(); break;
        case 5: _t->onNewExRemove(); break;
        case 6: _t->onNewBoxTwoActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onNewOkPressed(); break;
        case 8: _t->onNewCancelKeysPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (u_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&u_widget::newOkKeys)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject u_widget::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_u_widget.data,
    qt_meta_data_u_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *u_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *u_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_u_widget.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int u_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void u_widget::newOkKeys()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
