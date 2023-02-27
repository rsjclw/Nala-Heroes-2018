#pragma once

#include <qtimer.h>
#include <QtWidgets/QMainWindow>
#include <qthread.h>
#include <qobject.h>
#include <qdebug.h>
#include <qpainter.h>
#include <math.h>
#include <qtextstream.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qtablewidget.h>
#include <qlcdnumber.h>
#include <qscrollarea.h>
#include <qpixmap.h>
#include <QPaintEvent>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include "ui_MainWindow.h"
#include "serialconnection.h"
#include "DroneConnection.h"
#include "imgproc.h"
#include "saver.h"
#include "kontrolkapal.h"
#include "Mapping.h"
#include <unordered_map>
#include "networking.h"
#define PI 3.141532653589793
using namespace std;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();



private:
	// init stuff
	void init();
	void initConnection();

	//void paintEvent(QPaintEvent *e);
	float mission1[3];
	unordered_map<string, unordered_map<string, float > > missionSetting;
	Ui::MainWindow *ui;
	DroneConnection *droneConnection;
	//KontrolKapal *kontrol;
	ImgProc *cam;
	QThread *camThread, *serialThread, *kontrolThread, *netThread;
	QString fileName, portName;
	int hMin[7], sMin[7], vMin[7];
	int hMax[7], sMax[7], vMax[7];
	int dilate[7], erode[7];
	int speed;

	int offset;
	
	float pid[3];
	bool loadStatus;
	double latitude_sekarang;
	double longitude_sekarang;
	double compass_sekarang;

	double lattitudeWaypoint[40];
	double longitudeWaypoint[40];

	QString latitude[40];
	QString longitude[40];

	float skala_latitude;
	float skala_longitude;

	int index_waypoint = 1;
	int max_waypoint = 1;
	int index_plot_waypoint = 1;
	int satu = 1;
	bool status_waypoint = false;
	float jarak;
	QPixmap pixmapWaypoint();
	QPainter painterWaypoint();

	QPen waypen_now;
	QPen waypen_garis;


	bool started = 0;
	double kontrol_P;
	double kontrol_I;
	double kontrol_D;


	// communication with server
	Networking *net;

signals:
	void finished(bool);
	void statusCam(bool);
	void sendHSV(int, int, int, int, int, int, int, int, int);
	void updateHSV();
	void changeSpeed(int);
	void changePID(float, float, float);
	void changePID_2(float, float, float);
	void changePID_3(float, float, float);
	void currentColorId(int);
	void kontrol_waypoint(double, double, int);

	void send_index_plot_waypoint(int);
	void ubah_kontrol_PID(double, double, double);
	void kirim_ke_STM(int, int, int, int);
	void imageDroneRecieved();
	void reset_kontrol();
	void reset_serialConnection();
	void ubah_offset_serial(int);

public slots:
	void startCam();
	void stopCam();
	void changeSliderval();
	void updateLabel();
	void on_save();
	void on_save_as();
	void on_load();
	void loadHSV();
	void changeViewWarna();
	void pidChanged();
	void pidChanged_2();
	void pidChanged_3();
	void on_save_waypoint();
	void on_load_waypoint();
	void on_save_new();
	void on_load_new();
	void on_save_as_new();
	void startSerial();
	void stopSerial();

	void showDataGPS(double, double, float);
	void showDataSRF(int, int, int, int, int);
	void showDataHydro(int, int);
	void showDataDrone(int, int);
	void updateDataKirim();
	void takePictOnWaypoint(int);
	void connectDrone();
	void disconnectDrone();
	void imageDrone(QImage);

	void showMousePosition(QPoint& pos);

	void startplot();
	void stopplot();
	void setWaypoint();
	void reset();
	void retry();
	void retrytomisi2();
	void input_waypoint();

	void setIndexWaypoint(int);

	void left_clicked();
	void right_clicked();

	void ambil_olah_kontrol(int, int, int, int, float, float, float, int);
	void ubah_posisi_camera(int);
	void ubah_posisi_camera2(int);
	void ubah_posisi_camera_misi(int, int);
	void tampil_status_misi(int, int);
	void paintEvent();

	void startNet();
	void stopNet();
	void ubah_offset();
	void set_frame();
	void set_frame_2();

	void all_waypoint_geser_atas();
	void all_waypoint_geser_kiri();
	void all_waypoint_geser_kanan();
	void all_waypoint_geser_bawah();

	void ubah_radius_navigasi();
	void ubah_radius_misi4();


};