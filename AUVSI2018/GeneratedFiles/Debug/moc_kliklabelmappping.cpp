/****************************************************************************
** Meta object code from reading C++ file 'kliklabelmappping.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kliklabelmappping.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kliklabelmappping.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_kliklabelmappping_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_kliklabelmappping_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_kliklabelmappping_t qt_meta_stringdata_kliklabelmappping = {
    {
QT_MOC_LITERAL(0, 0, 17), // "kliklabelmappping"
QT_MOC_LITERAL(1, 18, 17), // "sendMousePosition"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 7), // "QPoint&"
QT_MOC_LITERAL(4, 45, 9), // "klik_kiri"
QT_MOC_LITERAL(5, 55, 10) // "klik_kanan"

    },
    "kliklabelmappping\0sendMousePosition\0"
    "\0QPoint&\0klik_kiri\0klik_kanan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_kliklabelmappping[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,
       5,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void kliklabelmappping::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        kliklabelmappping *_t = static_cast<kliklabelmappping *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->klik_kiri(); break;
        case 2: _t->klik_kanan(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (kliklabelmappping::*_t)(QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&kliklabelmappping::sendMousePosition)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (kliklabelmappping::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&kliklabelmappping::klik_kiri)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (kliklabelmappping::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&kliklabelmappping::klik_kanan)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject kliklabelmappping::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_kliklabelmappping.data,
      qt_meta_data_kliklabelmappping,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *kliklabelmappping::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *kliklabelmappping::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_kliklabelmappping.stringdata0))
        return static_cast<void*>(const_cast< kliklabelmappping*>(this));
    return QLabel::qt_metacast(_clname);
}

int kliklabelmappping::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void kliklabelmappping::sendMousePosition(QPoint & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void kliklabelmappping::klik_kiri()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void kliklabelmappping::klik_kanan()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
