/****************************************************************************
** Meta object code from reading C++ file 'DroneConnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DroneConnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DroneConnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DroneConnection_t {
    QByteArrayData data[13];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DroneConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DroneConnection_t qt_meta_stringdata_DroneConnection = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DroneConnection"
QT_MOC_LITERAL(1, 16, 13), // "imageRecieved"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "doConnect"
QT_MOC_LITERAL(4, 41, 8), // "serverIp"
QT_MOC_LITERAL(5, 50, 10), // "serverPort"
QT_MOC_LITERAL(6, 61, 9), // "connected"
QT_MOC_LITERAL(7, 71, 12), // "disconnected"
QT_MOC_LITERAL(8, 84, 12), // "bytesWritten"
QT_MOC_LITERAL(9, 97, 5), // "bytes"
QT_MOC_LITERAL(10, 103, 9), // "readyRead"
QT_MOC_LITERAL(11, 113, 12), // "doDisconnect"
QT_MOC_LITERAL(12, 126, 5) // "write"

    },
    "DroneConnection\0imageRecieved\0\0doConnect\0"
    "serverIp\0serverPort\0connected\0"
    "disconnected\0bytesWritten\0bytes\0"
    "readyRead\0doDisconnect\0write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DroneConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   57,    2, 0x0a /* Public */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DroneConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DroneConnection *_t = static_cast<DroneConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageRecieved((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->doConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->readyRead(); break;
        case 6: _t->doDisconnect(); break;
        case 7: _t->write(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DroneConnection::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DroneConnection::imageRecieved)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DroneConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DroneConnection.data,
      qt_meta_data_DroneConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DroneConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DroneConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DroneConnection.stringdata0))
        return static_cast<void*>(const_cast< DroneConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int DroneConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DroneConnection::imageRecieved(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
