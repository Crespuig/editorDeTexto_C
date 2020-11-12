/****************************************************************************
** Meta object code from reading C++ file 'DialogoElegirColor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DialogoElegirColor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogoElegirColor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogoElegirColor_t {
    QByteArrayData data[4];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogoElegirColor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogoElegirColor_t qt_meta_stringdata_DialogoElegirColor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DialogoElegirColor"
QT_MOC_LITERAL(1, 19, 20), // "slotBotonElegirColor"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 20) // "slotBotonProbarColor"

    },
    "DialogoElegirColor\0slotBotonElegirColor\0"
    "\0slotBotonProbarColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogoElegirColor[] = {

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
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogoElegirColor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogoElegirColor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotBotonElegirColor(); break;
        case 1: _t->slotBotonProbarColor(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogoElegirColor::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DialogoElegirColor.data,
    qt_meta_data_DialogoElegirColor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogoElegirColor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogoElegirColor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoElegirColor.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::DialogoElegirColor"))
        return static_cast< Ui::DialogoElegirColor*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogoElegirColor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
