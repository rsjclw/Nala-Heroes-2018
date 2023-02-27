/****************************************************************************
** Meta object code from reading C++ file 'bluetoothcomserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bluetoothcomserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothcomserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BluetoothComServer_t {
    QByteArrayData data[10];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BluetoothComServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BluetoothComServer_t qt_meta_stringdata_BluetoothComServer = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BluetoothComServer"
QT_MOC_LITERAL(1, 19, 15), // "messageReceived"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "sender"
QT_MOC_LITERAL(4, 43, 7), // "message"
QT_MOC_LITERAL(5, 51, 15), // "clientConnected"
QT_MOC_LITERAL(6, 67, 4), // "name"
QT_MOC_LITERAL(7, 72, 18), // "clientDisconnected"
QT_MOC_LITERAL(8, 91, 11), // "sendMessage"
QT_MOC_LITERAL(9, 103, 10) // "readSocket"

    },
    "BluetoothComServer\0messageReceived\0\0"
    "sender\0message\0clientConnected\0name\0"
    "clientDisconnected\0sendMessage\0"
    "readSocket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BluetoothComServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,
       7,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BluetoothComServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BluetoothComServer *_t = static_cast<BluetoothComServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->clientConnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->clientConnected(); break;
        case 5: _t->clientDisconnected(); break;
        case 6: _t->readSocket(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BluetoothComServer::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BluetoothComServer::messageReceived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BluetoothComServer::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BluetoothComServer::clientConnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BluetoothComServer::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BluetoothComServer::clientDisconnected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject BluetoothComServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BluetoothComServer.data,
      qt_meta_data_BluetoothComServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BluetoothComServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothComServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothComServer.stringdata0))
        return static_cast<void*>(const_cast< BluetoothComServer*>(this));
    return QObject::qt_metacast(_clname);
}

int BluetoothComServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void BluetoothComServer::messageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothComServer::clientConnected(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothComServer::clientDisconnected(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
