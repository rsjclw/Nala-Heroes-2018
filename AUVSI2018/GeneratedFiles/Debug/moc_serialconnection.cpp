/****************************************************************************
** Meta object code from reading C++ file 'serialconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serialconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialConnection_t {
    QByteArrayData data[24];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialConnection_t qt_meta_stringdata_SerialConnection = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialConnection"
QT_MOC_LITERAL(1, 17, 21), // "serial_kirim_data_SRF"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 21), // "serial_kirim_data_GPS"
QT_MOC_LITERAL(4, 62, 23), // "serial_kirim_data_Hydro"
QT_MOC_LITERAL(5, 86, 23), // "serial_kirim_data_Drone"
QT_MOC_LITERAL(6, 110, 20), // "drone_status_changed"
QT_MOC_LITERAL(7, 131, 14), // "initSerPortGPS"
QT_MOC_LITERAL(8, 146, 14), // "initSerPortSRF"
QT_MOC_LITERAL(9, 161, 16), // "initSerPortHydro"
QT_MOC_LITERAL(10, 178, 16), // "initSerPortDrone"
QT_MOC_LITERAL(11, 195, 18), // "initSerPortCompass"
QT_MOC_LITERAL(12, 214, 7), // "readGPS"
QT_MOC_LITERAL(13, 222, 7), // "readSRF"
QT_MOC_LITERAL(14, 230, 9), // "readHydro"
QT_MOC_LITERAL(15, 240, 9), // "readDrone"
QT_MOC_LITERAL(16, 250, 11), // "readCompass"
QT_MOC_LITERAL(17, 262, 13), // "sendDatatoSTM"
QT_MOC_LITERAL(18, 276, 15), // "sendDatatoDrone"
QT_MOC_LITERAL(19, 292, 5), // "close"
QT_MOC_LITERAL(20, 298, 14), // "terima_kontrol"
QT_MOC_LITERAL(21, 313, 17), // "ubah_status_drone"
QT_MOC_LITERAL(22, 331, 22), // "retry_serialConnection"
QT_MOC_LITERAL(23, 354, 20) // "terima_offset_serial"

    },
    "SerialConnection\0serial_kirim_data_SRF\0"
    "\0serial_kirim_data_GPS\0serial_kirim_data_Hydro\0"
    "serial_kirim_data_Drone\0drone_status_changed\0"
    "initSerPortGPS\0initSerPortSRF\0"
    "initSerPortHydro\0initSerPortDrone\0"
    "initSerPortCompass\0readGPS\0readSRF\0"
    "readHydro\0readDrone\0readCompass\0"
    "sendDatatoSTM\0sendDatatoDrone\0close\0"
    "terima_kontrol\0ubah_status_drone\0"
    "retry_serialConnection\0terima_offset_serial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  124,    2, 0x06 /* Public */,
       3,    3,  135,    2, 0x06 /* Public */,
       4,    2,  142,    2, 0x06 /* Public */,
       5,    2,  147,    2, 0x06 /* Public */,
       6,    1,  152,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  155,    2, 0x0a /* Public */,
       8,    0,  156,    2, 0x0a /* Public */,
       9,    0,  157,    2, 0x0a /* Public */,
      10,    0,  158,    2, 0x0a /* Public */,
      11,    0,  159,    2, 0x0a /* Public */,
      12,    0,  160,    2, 0x0a /* Public */,
      13,    0,  161,    2, 0x0a /* Public */,
      14,    0,  162,    2, 0x0a /* Public */,
      15,    0,  163,    2, 0x0a /* Public */,
      16,    0,  164,    2, 0x0a /* Public */,
      17,    0,  165,    2, 0x0a /* Public */,
      18,    0,  166,    2, 0x0a /* Public */,
      19,    0,  167,    2, 0x0a /* Public */,
      20,    5,  168,    2, 0x0a /* Public */,
      21,    1,  179,    2, 0x0a /* Public */,
      22,    0,  182,    2, 0x0a /* Public */,
      23,    1,  183,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void SerialConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialConnection *_t = static_cast<SerialConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serial_kirim_data_SRF((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->serial_kirim_data_GPS((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->serial_kirim_data_Hydro((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->serial_kirim_data_Drone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->drone_status_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->initSerPortGPS(); break;
        case 6: _t->initSerPortSRF(); break;
        case 7: _t->initSerPortHydro(); break;
        case 8: _t->initSerPortDrone(); break;
        case 9: _t->initSerPortCompass(); break;
        case 10: _t->readGPS(); break;
        case 11: _t->readSRF(); break;
        case 12: _t->readHydro(); break;
        case 13: _t->readDrone(); break;
        case 14: _t->readCompass(); break;
        case 15: _t->sendDatatoSTM(); break;
        case 16: _t->sendDatatoDrone(); break;
        case 17: _t->close(); break;
        case 18: _t->terima_kontrol((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 19: _t->ubah_status_drone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->retry_serialConnection(); break;
        case 21: _t->terima_offset_serial((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialConnection::*_t)(int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialConnection::serial_kirim_data_SRF)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialConnection::*_t)(double , double , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialConnection::serial_kirim_data_GPS)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialConnection::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialConnection::serial_kirim_data_Hydro)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialConnection::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialConnection::serial_kirim_data_Drone)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SerialConnection::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialConnection::drone_status_changed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject SerialConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialConnection.data,
      qt_meta_data_SerialConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialConnection.stringdata0))
        return static_cast<void*>(const_cast< SerialConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void SerialConnection::serial_kirim_data_SRF(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialConnection::serial_kirim_data_GPS(double _t1, double _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialConnection::serial_kirim_data_Hydro(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialConnection::serial_kirim_data_Drone(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialConnection::drone_status_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
