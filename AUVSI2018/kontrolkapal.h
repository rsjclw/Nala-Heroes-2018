#ifndef KONTROLKAPAL_H
#define KONTROLKAPAL_H
#define NULLPOINT -1000

#include <QObject>
#include <QtSerialPort\qserialport.h>
#include "serialconnection.h"
#include "qtimer.h"

class KontrolKapal : public QObject
{
	Q_OBJECT

public:
	KontrolKapal(QObject *parent = Q_NULLPTR);
	~KontrolKapal();

	int mission_state = 0;
	int mission_state_sebelum = 0;

	int counter_misi3 = 0;
	int penanda_misi3 = 0;
	int first_dock = 0;
	int second_dock = 3;
	int status_misi3 = 0;
	int status_misi3_sebelum = 0;
	unsigned int penanda_docking_misi3 = 0;
	bool timer_misi3 = false;
	bool timer_misi5 = false;
	bool timeout_misi = false;

private:

	double latt_waypoint[40];
	double long_waypoint[40];

	double latt_kontrol;
	double long_kontrol;
	float comp_kontrol;
	QTimer *timer_mundur = new QTimer(this);
	QTimer *timer_rotate_misi3 = new QTimer(this);
	QTimer *timer_mission = new QTimer(this);
	//QTimer *timer_misi3 = new QTimer(this);
	bool state_mundur = false;
	void kontrol_mundur(int);

	int kontrol_navigasi();
	int kontrol_tembok(int);

signals:
	void kirim_ke_serial(int, int, int, int, int);
	void kirim_data_kontrol(int,int,int,int,float,float,float,int);
	void ubah_state_imgproc(int);
	void status_misi(int,int);
	void mission_changed(int);
	void drone_terbang(int);


	
public slots :
	void kontrol_waypoint();
	void tujuanWaypoint(double, double, int);
	void ambilDataKontrolGPS(double, double, float);
	void terima_index(int);
	void terima_SRF(int, int, int, int, int);
	void terima_Hydro(int, int);
	void terima_Drone(int,int);
	void ubah_PID(double, double, double);
	void terima_pidout_imgproc(float);
	void terima_pidout_imgproc2(int, float);
	void trim_motor(int);
	void trim_serv_kiri(int);
	void trim_serv_kanan(int);
	void ubah_timeout_misi3(int);
	void ubah_timeout_misi5(int);

	void mulai_misi();
	void stop_misi();

	void change_stop_misi1(int);
	void change_stop_misi2(int);
	void change_stop_misi3(int);
	void change_stop_misi4(int);
	void change_stop_misi5(int);
	void change_stop_misi6(int);
	void change_stop_return(int);

	void change_waypoint_misi1(int);
	void change_waypoint_misi2(int);
	void change_waypoint_misi3(int);
	void change_waypoint_misi3_2(int);
	void change_waypoint_misi4(int);
	void change_waypoint_misi5(int);
	void change_waypoint_misi6(int);
	void change_waypoint_return(int);

	void change_speed_misi1(int);
	void change_speed_misi2(int);
	void change_speed_tengah_misi2(int);
	void change_speed_misi3(int);
	void change_speed_misi4(int);
	void change_speed_misi5(int);
	void change_speed_misi5_bawah(int);
	void change_speed_misi3_atas(int);
	void change_speed_misi6(int);
	void change_speed_return(int);
	void change_speed_navigation(int);

	void ubah_PID_misi3(float, float, float);
	void ambil_setpoint_misi3(int);
	void ambil_setpoint_misi5(int);
	void ambil_sudut_misi3(int);
	void change_threshold_pinger(int);
	void change_frequency_misi3(int);
	void change_max_pinger(int);
	void tidak_mundur();
	void stop_rotate();
	void next_mission();
	void updateDockDrone(int);

	void retry_kontrol();
	//void timeout_misi3();
	
signals :
	void change_servo_camera(int,int);
};

#endif // KONTROLKAPAL_H
