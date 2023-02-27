/****************************************************************************
** Meta object code from reading C++ file 'imgproc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imgproc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgproc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImgProc_t {
    QByteArrayData data[19];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgProc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgProc_t qt_meta_stringdata_ImgProc = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ImgProc"
QT_MOC_LITERAL(1, 8, 9), // "sendImage"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 15), // "sendDataKontrol"
QT_MOC_LITERAL(4, 35, 16), // "sendDataKontrol2"
QT_MOC_LITERAL(5, 52, 15), // "dronePrediction"
QT_MOC_LITERAL(6, 68, 10), // "receiveHSV"
QT_MOC_LITERAL(7, 79, 10), // "openCamera"
QT_MOC_LITERAL(8, 90, 11), // "reciveSpeed"
QT_MOC_LITERAL(9, 102, 9), // "recivePID"
QT_MOC_LITERAL(10, 112, 11), // "recivePID_2"
QT_MOC_LITERAL(11, 124, 11), // "recivePID_3"
QT_MOC_LITERAL(12, 136, 11), // "ubah_batasY"
QT_MOC_LITERAL(13, 148, 13), // "reciveColorId"
QT_MOC_LITERAL(14, 162, 14), // "reciveMousePos"
QT_MOC_LITERAL(15, 177, 16), // "reciveInitialPos"
QT_MOC_LITERAL(16, 194, 12), // "thresholding"
QT_MOC_LITERAL(17, 207, 13), // "state_imgproc"
QT_MOC_LITERAL(18, 221, 17) // "predictImageDrone"

    },
    "ImgProc\0sendImage\0\0sendDataKontrol\0"
    "sendDataKontrol2\0dronePrediction\0"
    "receiveHSV\0openCamera\0reciveSpeed\0"
    "recivePID\0recivePID_2\0recivePID_3\0"
    "ubah_batasY\0reciveColorId\0reciveMousePos\0"
    "reciveInitialPos\0thresholding\0"
    "state_imgproc\0predictImageDrone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgProc[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    1,  100,    2, 0x06 /* Public */,
       4,    2,  103,    2, 0x06 /* Public */,
       5,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    9,  111,    2, 0x0a /* Public */,
       7,    0,  130,    2, 0x0a /* Public */,
       8,    1,  131,    2, 0x0a /* Public */,
       9,    3,  134,    2, 0x0a /* Public */,
      10,    3,  141,    2, 0x0a /* Public */,
      11,    3,  148,    2, 0x0a /* Public */,
      12,    1,  155,    2, 0x0a /* Public */,
      13,    1,  158,    2, 0x0a /* Public */,
      14,    1,  161,    2, 0x0a /* Public */,
      15,    1,  164,    2, 0x0a /* Public */,
      16,    1,  167,    2, 0x0a /* Public */,
      17,    1,  170,    2, 0x0a /* Public */,
      18,    1,  173,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QImage,    2,

       0        // eod
};

void ImgProc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImgProc *_t = static_cast<ImgProc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImage(); break;
        case 1: _t->sendDataKontrol((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->sendDataKontrol2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->dronePrediction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->receiveHSV((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        case 5: _t->openCamera(); break;
        case 6: _t->reciveSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->recivePID((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 8: _t->recivePID_2((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 9: _t->recivePID_3((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 10: _t->ubah_batasY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->reciveColorId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->reciveMousePos((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 13: _t->reciveInitialPos((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 14: _t->thresholding((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 15: _t->state_imgproc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->predictImageDrone((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImgProc::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgProc::sendImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImgProc::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgProc::sendDataKontrol)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ImgProc::*_t)(int , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgProc::sendDataKontrol2)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ImgProc::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImgProc::dronePrediction)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ImgProc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImgProc.data,
      qt_meta_data_ImgProc,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImgProc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgProc::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImgProc.stringdata0))
        return static_cast<void*>(const_cast< ImgProc*>(this));
    return QObject::qt_metacast(_clname);
}

int ImgProc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ImgProc::sendImage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ImgProc::sendDataKontrol(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImgProc::sendDataKontrol2(int _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImgProc::dronePrediction(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
