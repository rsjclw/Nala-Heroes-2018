/****************************************************************************
** Meta object code from reading C++ file 'networking.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../networking.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Networking_t {
    QByteArrayData data[28];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Networking_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Networking_t qt_meta_stringdata_Networking = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Networking"
QT_MOC_LITERAL(1, 11, 7), // "emitMsg"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "setBaseURL"
QT_MOC_LITERAL(4, 31, 16), // "setCurrentCourse"
QT_MOC_LITERAL(5, 48, 5), // "start"
QT_MOC_LITERAL(6, 54, 4), // "stop"
QT_MOC_LITERAL(7, 59, 16), // "requestDispacher"
QT_MOC_LITERAL(8, 76, 9), // "setCourse"
QT_MOC_LITERAL(9, 86, 20), // "sendRequestHeartbeat"
QT_MOC_LITERAL(10, 107, 19), // "sendRequestHearbeat"
QT_MOC_LITERAL(11, 127, 26), // "handleRequestDataHeartbeat"
QT_MOC_LITERAL(12, 154, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 169, 16), // "sendRequestStart"
QT_MOC_LITERAL(14, 186, 18), // "handleRequestStart"
QT_MOC_LITERAL(15, 205, 15), // "sendRequestStop"
QT_MOC_LITERAL(16, 221, 17), // "handleRequestStop"
QT_MOC_LITERAL(17, 239, 23), // "sendRequestFollowLeader"
QT_MOC_LITERAL(18, 263, 25), // "handleRequestFollowLeader"
QT_MOC_LITERAL(19, 289, 19), // "sendRequestAutoDock"
QT_MOC_LITERAL(20, 309, 14), // "handleAutoDock"
QT_MOC_LITERAL(21, 324, 17), // "sendRequestGoogle"
QT_MOC_LITERAL(22, 342, 10), // "updateTime"
QT_MOC_LITERAL(23, 353, 17), // "setCurrentMission"
QT_MOC_LITERAL(24, 371, 13), // "updatePayload"
QT_MOC_LITERAL(25, 385, 9), // "updateGPS"
QT_MOC_LITERAL(26, 395, 8), // "setImage"
QT_MOC_LITERAL(27, 404, 9) // "sendImage"

    },
    "Networking\0emitMsg\0\0setBaseURL\0"
    "setCurrentCourse\0start\0stop\0"
    "requestDispacher\0setCourse\0"
    "sendRequestHeartbeat\0sendRequestHearbeat\0"
    "handleRequestDataHeartbeat\0QNetworkReply*\0"
    "sendRequestStart\0handleRequestStart\0"
    "sendRequestStop\0handleRequestStop\0"
    "sendRequestFollowLeader\0"
    "handleRequestFollowLeader\0sendRequestAutoDock\0"
    "handleAutoDock\0sendRequestGoogle\0"
    "updateTime\0setCurrentMission\0updatePayload\0"
    "updateGPS\0setImage\0sendImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Networking[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  147,    2, 0x0a /* Public */,
       4,    1,  150,    2, 0x0a /* Public */,
       5,    0,  153,    2, 0x0a /* Public */,
       6,    0,  154,    2, 0x0a /* Public */,
       7,    0,  155,    2, 0x0a /* Public */,
       8,    1,  156,    2, 0x0a /* Public */,
       9,    0,  159,    2, 0x0a /* Public */,
      10,    1,  160,    2, 0x0a /* Public */,
      11,    1,  163,    2, 0x0a /* Public */,
      13,    0,  166,    2, 0x0a /* Public */,
      13,    1,  167,    2, 0x0a /* Public */,
      14,    1,  170,    2, 0x0a /* Public */,
      15,    1,  173,    2, 0x0a /* Public */,
      16,    1,  176,    2, 0x0a /* Public */,
      17,    1,  179,    2, 0x0a /* Public */,
      18,    1,  182,    2, 0x0a /* Public */,
      19,    1,  185,    2, 0x0a /* Public */,
      20,    1,  188,    2, 0x0a /* Public */,
      21,    0,  191,    2, 0x0a /* Public */,
      22,    0,  192,    2, 0x0a /* Public */,
      23,    1,  193,    2, 0x0a /* Public */,
      24,    7,  196,    2, 0x0a /* Public */,
      25,    3,  211,    2, 0x0a /* Public */,
      26,    1,  218,    2, 0x0a /* Public */,
      27,    1,  221,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Long, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    2,

       0        // eod
};

void Networking::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Networking *_t = static_cast<Networking *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setBaseURL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setCurrentCourse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        case 5: _t->requestDispacher(); break;
        case 6: _t->setCourse((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendRequestHeartbeat(); break;
        case 8: _t->sendRequestHearbeat((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 9: _t->handleRequestDataHeartbeat((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->sendRequestStart(); break;
        case 11: _t->sendRequestStart((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 12: _t->handleRequestStart((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->sendRequestStop((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 14: _t->handleRequestStop((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 15: _t->sendRequestFollowLeader((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 16: _t->handleRequestFollowLeader((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 17: _t->sendRequestAutoDock((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 18: _t->handleAutoDock((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 19: _t->sendRequestGoogle(); break;
        case 20: _t->updateTime(); break;
        case 21: _t->setCurrentMission((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->updatePayload((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< long(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 23: _t->updateGPS((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 24: _t->setImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 25: _t->sendImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Networking::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Networking::emitMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Networking::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Networking.data,
      qt_meta_data_Networking,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Networking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Networking::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Networking.stringdata0))
        return static_cast<void*>(const_cast< Networking*>(this));
    return QObject::qt_metacast(_clname);
}

int Networking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void Networking::emitMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
