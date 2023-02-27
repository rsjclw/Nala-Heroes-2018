/****************************************************************************
** Meta object code from reading C++ file 'kontrolkapal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kontrolkapal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kontrolkapal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KontrolKapal_t {
    QByteArrayData data[64];
    char stringdata0[1134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KontrolKapal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KontrolKapal_t qt_meta_stringdata_KontrolKapal = {
    {
QT_MOC_LITERAL(0, 0, 12), // "KontrolKapal"
QT_MOC_LITERAL(1, 13, 15), // "kirim_ke_serial"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "kirim_data_kontrol"
QT_MOC_LITERAL(4, 49, 18), // "ubah_state_imgproc"
QT_MOC_LITERAL(5, 68, 11), // "status_misi"
QT_MOC_LITERAL(6, 80, 15), // "mission_changed"
QT_MOC_LITERAL(7, 96, 13), // "drone_terbang"
QT_MOC_LITERAL(8, 110, 19), // "change_servo_camera"
QT_MOC_LITERAL(9, 130, 16), // "kontrol_waypoint"
QT_MOC_LITERAL(10, 147, 14), // "tujuanWaypoint"
QT_MOC_LITERAL(11, 162, 19), // "ambilDataKontrolGPS"
QT_MOC_LITERAL(12, 182, 12), // "terima_index"
QT_MOC_LITERAL(13, 195, 10), // "terima_SRF"
QT_MOC_LITERAL(14, 206, 12), // "terima_Hydro"
QT_MOC_LITERAL(15, 219, 12), // "terima_Drone"
QT_MOC_LITERAL(16, 232, 8), // "ubah_PID"
QT_MOC_LITERAL(17, 241, 21), // "terima_pidout_imgproc"
QT_MOC_LITERAL(18, 263, 22), // "terima_pidout_imgproc2"
QT_MOC_LITERAL(19, 286, 10), // "trim_motor"
QT_MOC_LITERAL(20, 297, 14), // "trim_serv_kiri"
QT_MOC_LITERAL(21, 312, 15), // "trim_serv_kanan"
QT_MOC_LITERAL(22, 328, 18), // "ubah_timeout_misi3"
QT_MOC_LITERAL(23, 347, 18), // "ubah_timeout_misi5"
QT_MOC_LITERAL(24, 366, 10), // "mulai_misi"
QT_MOC_LITERAL(25, 377, 9), // "stop_misi"
QT_MOC_LITERAL(26, 387, 17), // "change_stop_misi1"
QT_MOC_LITERAL(27, 405, 17), // "change_stop_misi2"
QT_MOC_LITERAL(28, 423, 17), // "change_stop_misi3"
QT_MOC_LITERAL(29, 441, 17), // "change_stop_misi4"
QT_MOC_LITERAL(30, 459, 17), // "change_stop_misi5"
QT_MOC_LITERAL(31, 477, 17), // "change_stop_misi6"
QT_MOC_LITERAL(32, 495, 18), // "change_stop_return"
QT_MOC_LITERAL(33, 514, 21), // "change_waypoint_misi1"
QT_MOC_LITERAL(34, 536, 21), // "change_waypoint_misi2"
QT_MOC_LITERAL(35, 558, 21), // "change_waypoint_misi3"
QT_MOC_LITERAL(36, 580, 23), // "change_waypoint_misi3_2"
QT_MOC_LITERAL(37, 604, 21), // "change_waypoint_misi4"
QT_MOC_LITERAL(38, 626, 21), // "change_waypoint_misi5"
QT_MOC_LITERAL(39, 648, 21), // "change_waypoint_misi6"
QT_MOC_LITERAL(40, 670, 22), // "change_waypoint_return"
QT_MOC_LITERAL(41, 693, 18), // "change_speed_misi1"
QT_MOC_LITERAL(42, 712, 18), // "change_speed_misi2"
QT_MOC_LITERAL(43, 731, 25), // "change_speed_tengah_misi2"
QT_MOC_LITERAL(44, 757, 18), // "change_speed_misi3"
QT_MOC_LITERAL(45, 776, 18), // "change_speed_misi4"
QT_MOC_LITERAL(46, 795, 18), // "change_speed_misi5"
QT_MOC_LITERAL(47, 814, 24), // "change_speed_misi5_bawah"
QT_MOC_LITERAL(48, 839, 23), // "change_speed_misi3_atas"
QT_MOC_LITERAL(49, 863, 18), // "change_speed_misi6"
QT_MOC_LITERAL(50, 882, 19), // "change_speed_return"
QT_MOC_LITERAL(51, 902, 23), // "change_speed_navigation"
QT_MOC_LITERAL(52, 926, 14), // "ubah_PID_misi3"
QT_MOC_LITERAL(53, 941, 20), // "ambil_setpoint_misi3"
QT_MOC_LITERAL(54, 962, 20), // "ambil_setpoint_misi5"
QT_MOC_LITERAL(55, 983, 17), // "ambil_sudut_misi3"
QT_MOC_LITERAL(56, 1001, 23), // "change_threshold_pinger"
QT_MOC_LITERAL(57, 1025, 22), // "change_frequency_misi3"
QT_MOC_LITERAL(58, 1048, 17), // "change_max_pinger"
QT_MOC_LITERAL(59, 1066, 12), // "tidak_mundur"
QT_MOC_LITERAL(60, 1079, 11), // "stop_rotate"
QT_MOC_LITERAL(61, 1091, 12), // "next_mission"
QT_MOC_LITERAL(62, 1104, 15), // "updateDockDrone"
QT_MOC_LITERAL(63, 1120, 13) // "retry_kontrol"

    },
    "KontrolKapal\0kirim_ke_serial\0\0"
    "kirim_data_kontrol\0ubah_state_imgproc\0"
    "status_misi\0mission_changed\0drone_terbang\0"
    "change_servo_camera\0kontrol_waypoint\0"
    "tujuanWaypoint\0ambilDataKontrolGPS\0"
    "terima_index\0terima_SRF\0terima_Hydro\0"
    "terima_Drone\0ubah_PID\0terima_pidout_imgproc\0"
    "terima_pidout_imgproc2\0trim_motor\0"
    "trim_serv_kiri\0trim_serv_kanan\0"
    "ubah_timeout_misi3\0ubah_timeout_misi5\0"
    "mulai_misi\0stop_misi\0change_stop_misi1\0"
    "change_stop_misi2\0change_stop_misi3\0"
    "change_stop_misi4\0change_stop_misi5\0"
    "change_stop_misi6\0change_stop_return\0"
    "change_waypoint_misi1\0change_waypoint_misi2\0"
    "change_waypoint_misi3\0change_waypoint_misi3_2\0"
    "change_waypoint_misi4\0change_waypoint_misi5\0"
    "change_waypoint_misi6\0change_waypoint_return\0"
    "change_speed_misi1\0change_speed_misi2\0"
    "change_speed_tengah_misi2\0change_speed_misi3\0"
    "change_speed_misi4\0change_speed_misi5\0"
    "change_speed_misi5_bawah\0"
    "change_speed_misi3_atas\0change_speed_misi6\0"
    "change_speed_return\0change_speed_navigation\0"
    "ubah_PID_misi3\0ambil_setpoint_misi3\0"
    "ambil_setpoint_misi5\0ambil_sudut_misi3\0"
    "change_threshold_pinger\0change_frequency_misi3\0"
    "change_max_pinger\0tidak_mundur\0"
    "stop_rotate\0next_mission\0updateDockDrone\0"
    "retry_kontrol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KontrolKapal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      62,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  324,    2, 0x06 /* Public */,
       3,    8,  335,    2, 0x06 /* Public */,
       4,    1,  352,    2, 0x06 /* Public */,
       5,    2,  355,    2, 0x06 /* Public */,
       6,    1,  360,    2, 0x06 /* Public */,
       7,    1,  363,    2, 0x06 /* Public */,
       8,    2,  366,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  371,    2, 0x0a /* Public */,
      10,    3,  372,    2, 0x0a /* Public */,
      11,    3,  379,    2, 0x0a /* Public */,
      12,    1,  386,    2, 0x0a /* Public */,
      13,    5,  389,    2, 0x0a /* Public */,
      14,    2,  400,    2, 0x0a /* Public */,
      15,    2,  405,    2, 0x0a /* Public */,
      16,    3,  410,    2, 0x0a /* Public */,
      17,    1,  417,    2, 0x0a /* Public */,
      18,    2,  420,    2, 0x0a /* Public */,
      19,    1,  425,    2, 0x0a /* Public */,
      20,    1,  428,    2, 0x0a /* Public */,
      21,    1,  431,    2, 0x0a /* Public */,
      22,    1,  434,    2, 0x0a /* Public */,
      23,    1,  437,    2, 0x0a /* Public */,
      24,    0,  440,    2, 0x0a /* Public */,
      25,    0,  441,    2, 0x0a /* Public */,
      26,    1,  442,    2, 0x0a /* Public */,
      27,    1,  445,    2, 0x0a /* Public */,
      28,    1,  448,    2, 0x0a /* Public */,
      29,    1,  451,    2, 0x0a /* Public */,
      30,    1,  454,    2, 0x0a /* Public */,
      31,    1,  457,    2, 0x0a /* Public */,
      32,    1,  460,    2, 0x0a /* Public */,
      33,    1,  463,    2, 0x0a /* Public */,
      34,    1,  466,    2, 0x0a /* Public */,
      35,    1,  469,    2, 0x0a /* Public */,
      36,    1,  472,    2, 0x0a /* Public */,
      37,    1,  475,    2, 0x0a /* Public */,
      38,    1,  478,    2, 0x0a /* Public */,
      39,    1,  481,    2, 0x0a /* Public */,
      40,    1,  484,    2, 0x0a /* Public */,
      41,    1,  487,    2, 0x0a /* Public */,
      42,    1,  490,    2, 0x0a /* Public */,
      43,    1,  493,    2, 0x0a /* Public */,
      44,    1,  496,    2, 0x0a /* Public */,
      45,    1,  499,    2, 0x0a /* Public */,
      46,    1,  502,    2, 0x0a /* Public */,
      47,    1,  505,    2, 0x0a /* Public */,
      48,    1,  508,    2, 0x0a /* Public */,
      49,    1,  511,    2, 0x0a /* Public */,
      50,    1,  514,    2, 0x0a /* Public */,
      51,    1,  517,    2, 0x0a /* Public */,
      52,    3,  520,    2, 0x0a /* Public */,
      53,    1,  527,    2, 0x0a /* Public */,
      54,    1,  530,    2, 0x0a /* Public */,
      55,    1,  533,    2, 0x0a /* Public */,
      56,    1,  536,    2, 0x0a /* Public */,
      57,    1,  539,    2, 0x0a /* Public */,
      58,    1,  542,    2, 0x0a /* Public */,
      59,    0,  545,    2, 0x0a /* Public */,
      60,    0,  546,    2, 0x0a /* Public */,
      61,    0,  547,    2, 0x0a /* Public */,
      62,    1,  548,    2, 0x0a /* Public */,
      63,    0,  551,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void KontrolKapal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KontrolKapal *_t = static_cast<KontrolKapal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->kirim_ke_serial((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->kirim_data_kontrol((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 2: _t->ubah_state_imgproc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->status_misi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->mission_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->drone_terbang((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->change_servo_camera((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->kontrol_waypoint(); break;
        case 8: _t->tujuanWaypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->ambilDataKontrolGPS((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 10: _t->terima_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->terima_SRF((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 12: _t->terima_Hydro((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->terima_Drone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->ubah_PID((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 15: _t->terima_pidout_imgproc((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 16: _t->terima_pidout_imgproc2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 17: _t->trim_motor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->trim_serv_kiri((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->trim_serv_kanan((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->ubah_timeout_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->ubah_timeout_misi5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->mulai_misi(); break;
        case 23: _t->stop_misi(); break;
        case 24: _t->change_stop_misi1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->change_stop_misi2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->change_stop_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->change_stop_misi4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->change_stop_misi5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->change_stop_misi6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->change_stop_return((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->change_waypoint_misi1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->change_waypoint_misi2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->change_waypoint_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->change_waypoint_misi3_2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->change_waypoint_misi4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->change_waypoint_misi5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->change_waypoint_misi6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->change_waypoint_return((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->change_speed_misi1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->change_speed_misi2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->change_speed_tengah_misi2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->change_speed_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->change_speed_misi4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->change_speed_misi5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->change_speed_misi5_bawah((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->change_speed_misi3_atas((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->change_speed_misi6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->change_speed_return((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->change_speed_navigation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->ubah_PID_misi3((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 51: _t->ambil_setpoint_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->ambil_setpoint_misi5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->ambil_sudut_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->change_threshold_pinger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->change_frequency_misi3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->change_max_pinger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->tidak_mundur(); break;
        case 58: _t->stop_rotate(); break;
        case 59: _t->next_mission(); break;
        case 60: _t->updateDockDrone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 61: _t->retry_kontrol(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KontrolKapal::*_t)(int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::kirim_ke_serial)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int , int , int , int , float , float , float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::kirim_data_kontrol)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::ubah_state_imgproc)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::status_misi)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::mission_changed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::drone_terbang)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (KontrolKapal::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KontrolKapal::change_servo_camera)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject KontrolKapal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KontrolKapal.data,
      qt_meta_data_KontrolKapal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KontrolKapal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KontrolKapal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KontrolKapal.stringdata0))
        return static_cast<void*>(const_cast< KontrolKapal*>(this));
    return QObject::qt_metacast(_clname);
}

int KontrolKapal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 62)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 62;
    }
    return _id;
}

// SIGNAL 0
void KontrolKapal::kirim_ke_serial(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KontrolKapal::kirim_data_kontrol(int _t1, int _t2, int _t3, int _t4, float _t5, float _t6, float _t7, int _t8)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KontrolKapal::ubah_state_imgproc(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KontrolKapal::status_misi(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KontrolKapal::mission_changed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void KontrolKapal::drone_terbang(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void KontrolKapal::change_servo_camera(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
