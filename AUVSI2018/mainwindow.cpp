#include "mainwindow.h"

using namespace std;
SerialConnection *serialConnection;
KontrolKapal *kontrol;

///////////////Reed Canal Park//////////////////////
//unsigned int titik_awal_lat = 291520905;
//unsigned int titik_awal_long = 810173445;

//unsigned int titik_akhir_lat = 291502665;
//unsigned int titik_akhir_long = 810157455;
/////////////////////////////////////////////
unsigned int titik_awal_lat = 292139343; 
unsigned int titik_akhir_lat = 292129343;
unsigned int titik_awal_long = 810196053;
unsigned int titik_akhir_long =  810186053;

///////////////Danau 8///////////////////////
//unsigned int titik_awal_lat =		72862585;
//unsigned int titik_awal_long = 1127957235;

//unsigned int titik_akhir_lat =	72872555;
//unsigned int titik_akhir_long = 1127964815;
/////////////////////////////////////////////

void MainWindow::initConnection() {
	// connection to show hsv
	connect(ui->warnaSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(changeViewWarna()));
	connect(ui->hMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->hMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->sMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->sMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->vMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->vMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->erode1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->dilate1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate6, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate7, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	// show speed change
	//connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	//connect(ui->speedSlider, SIGNAL(valueChanged(int)), cam, SLOT(reciveSpeed(int)), Qt::DirectConnection);

	// save and load hsv connection
	connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(on_save_new()));
	connect(ui->actionSave_As, SIGNAL(triggered(bool)), this, SLOT(on_save_as_new()));
	connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(on_load_new()));
	connect(this, SIGNAL(updateHSV()), this, SLOT(loadHSV()));

	// camera thread connection
	connect(camThread, SIGNAL(started()), cam, SLOT(openCamera()));
	connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startCam()));
	connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopCam()));
	connect(cam, SIGNAL(sendImage()), this, SLOT(updateLabel()), Qt::DirectConnection);
	connect(this, SIGNAL(sendHSV(int, int, int, int, int, int, int, int, int)), cam, SLOT(receiveHSV(int, int, int, int, int, int, int, int, int)), Qt::DirectConnection);
	connect(this, SIGNAL(currentColorId(int)), cam, SLOT(reciveColorId(int)), Qt::DirectConnection);
	connect(ui->labelOri, SIGNAL(clickedPos(QPoint)), cam, SLOT(reciveInitialPos(QPoint)), Qt::DirectConnection);
	connect(ui->labelOri, SIGNAL(currentPos(QPoint)), cam, SLOT(reciveMousePos(QPoint)), Qt::DirectConnection);
	connect(ui->labelOri, SIGNAL(endPos(QPoint)), cam, SLOT(thresholding(QPoint)), Qt::DirectConnection);

	// serial connection
	connect(ui->pushButtonOpenPort, SIGNAL(clicked(bool)), this, SLOT(startSerial()));
	connect(ui->pushButtonClosePort, SIGNAL(clicked(bool)), this, SLOT(stopSerial()));
	connect(serialThread, SIGNAL(started()), serialConnection, SLOT(initSerPortGPS())); // mulai jalanin thread koneksi serial
	connect(serialThread, SIGNAL(started()), serialConnection, SLOT(initSerPortSRF()));
	connect(serialThread, SIGNAL(started()), serialConnection, SLOT(initSerPortHydro())); // mulai jalanin thread koneksi serial
	connect(serialThread, SIGNAL(started()), serialConnection, SLOT(initSerPortDrone()));
	connect(serialThread, SIGNAL(started()), serialConnection, SLOT(initSerPortCompass()));
	connect(serialConnection, SIGNAL(serial_kirim_data_SRF(int, int, int, int, int)), this, SLOT(showDataSRF(int, int, int, int, int))); // check masukan gps
	connect(serialConnection, SIGNAL(serial_kirim_data_SRF(int, int, int, int, int)), kontrol, SLOT(terima_SRF(int, int, int, int, int)), Qt::DirectConnection);
	connect(serialConnection, SIGNAL(serial_kirim_data_Hydro(int, int)), this, SLOT(showDataHydro(int, int)));
	connect(serialConnection, SIGNAL(serial_kirim_data_Hydro(int, int)), kontrol, SLOT(terima_Hydro(int, int)), Qt::DirectConnection);
	connect(serialConnection, SIGNAL(serial_kirim_data_Drone(int, int)), this, SLOT(showDataDrone(int, int)));
	connect(serialConnection, SIGNAL(serial_kirim_data_Drone(int, int)), kontrol, SLOT(terima_Drone(int, int)), Qt::DirectConnection);
	connect(serialConnection, SIGNAL(serial_kirim_data_GPS(double, double, float)), this, SLOT(showDataGPS(double, double, float)));
	connect(ui->pushButtonClosePort, SIGNAL(clicked(bool)), serialConnection, SLOT(close()));

	connect(kontrol, SIGNAL(kirim_ke_serial(int, int, int, int, int)), serialConnection, SLOT(terima_kontrol(int, int, int, int, int)), Qt::DirectConnection);

	//klikmapping
	connect(ui->labelMapping, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(showMousePosition(QPoint&)));
	connect(ui->labelMapping, SIGNAL(klik_kiri()), this, SLOT(left_clicked()));
	connect(ui->labelMapping, SIGNAL(klik_kanan()), this, SLOT(right_clicked()));

	// Waypoint
	connect(ui->spinBoxWaypoint, SIGNAL(valueChanged(int)), this, SLOT(setIndexWaypoint(int)));
	connect(ui->pushButtonSetWaypoint, SIGNAL(clicked(bool)), this, SLOT(setWaypoint()));
	connect(ui->pushButtonStartMission, SIGNAL(clicked(bool)), this, SLOT(startplot()));
	connect(ui->pushButtonStartMission, SIGNAL(clicked(bool)), kontrol, SLOT(mulai_misi()));
	connect(ui->pushButtonStopMission, SIGNAL(clicked(bool)), this, SLOT(stopplot()));
	connect(ui->pushButtonStopMission, SIGNAL(clicked(bool)), kontrol, SLOT(stop_misi()));
	connect(ui->pushButtonReset, SIGNAL(clicked(bool)), this, SLOT(reset()));
	connect(ui->pushButtonSaveAsWaypoint, SIGNAL(clicked(bool)), SLOT(on_save_waypoint()));
	connect(ui->pushButtonLoadWaypoint, SIGNAL(clicked(bool)), SLOT(on_load_waypoint()));
	connect(ui->pushButtonRetry, SIGNAL(clicked(bool)), this, SLOT(retry()), Qt::DirectConnection);
	connect(ui->pushButtonRetry2, SIGNAL(clicked(bool)), this, SLOT(retrytomisi2()), Qt::DirectConnection);
	connect(this, SIGNAL(reset_kontrol()), kontrol, SLOT(retry_kontrol()), Qt::DirectConnection);
	connect(this, SIGNAL(reset_serialConnection()), serialConnection, SLOT(retry_serialConnection()), Qt::DirectConnection);
	connect(ui->pushButtonInputWaypoint, SIGNAL(clicked(bool)), this, SLOT(input_waypoint()));
	connect(ui->pushButtonNorth, SIGNAL(clicked(bool)), this, SLOT(all_waypoint_geser_atas()));
	connect(ui->pushButtonWest, SIGNAL(clicked(bool)), this, SLOT(all_waypoint_geser_kiri()));
	connect(ui->pushButtonEast, SIGNAL(clicked(bool)), this, SLOT(all_waypoint_geser_kanan()));
	connect(ui->pushButtonSouth, SIGNAL(clicked(bool)), this, SLOT(all_waypoint_geser_bawah()));

	connect(ui->spinBoxOffset, SIGNAL(valueChanged(int)), this, SLOT(ubah_offset())); //check
	connect(this, SIGNAL(ubah_offset_serial(int)), serialConnection, SLOT(terima_offset_serial(int)));
	connect(ui->doubleSpinBoxRadiusNavigasi, SIGNAL(valueChanged(double)), this, SLOT(ubah_radius_navigasi()));
	connect(ui->doubleSpinBoxRadiusMisi4, SIGNAL(valueChanged(double)), this, SLOT(ubah_radius_misi4()));

	connect(ui->pushButtonSetFrame, SIGNAL(clicked(bool)), this, SLOT(set_frame()));
	connect(ui->comboBoxSetFrame, SIGNAL(currentIndexChanged(int)), this, SLOT(set_frame_2()));


	// change pid
	connect(ui->spinBoxP1, SIGNAL(valueChanged(int)), this, SLOT(pidChanged()));
	connect(ui->spinBoxI1, SIGNAL(valueChanged(int)), this, SLOT(pidChanged()));
	connect(ui->spinBoxD1, SIGNAL(valueChanged(int)), this, SLOT(pidChanged()));
	connect(this, SIGNAL(changePID(float, float, float)), cam, SLOT(recivePID(float, float, float)), Qt::DirectConnection);
	connect(ui->spinBoxP2, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_2()));
	connect(ui->spinBoxI2, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_2()));
	connect(ui->spinBoxD2, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_2()));
	connect(this, SIGNAL(changePID_2(float, float, float)), cam, SLOT(recivePID_2(float, float, float)), Qt::DirectConnection);
	connect(ui->spinBoxP3, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_3()));
	connect(ui->spinBoxI3, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_3()));
	connect(ui->spinBoxD3, SIGNAL(valueChanged(int)), this, SLOT(pidChanged_3()));
	connect(this, SIGNAL(changePID_3(float, float, float)), kontrol, SLOT(ubah_PID_misi3(float, float, float)), Qt::DirectConnection);
	connect(ui->spinBoxSetpointMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(ambil_setpoint_misi3(int)));
	connect(ui->spinBoxSetpointMisi5, SIGNAL(valueChanged(int)), kontrol, SLOT(ambil_setpoint_misi5(int)));

	connect(ui->spinBoxBatasY, SIGNAL(valueChanged(int)), cam, SLOT(ubah_batasY(int)), Qt::DirectConnection);

	// drone connection
	//connect(ui->buttonConnectDrone, SIGNAL(clicked(bool)), this, SLOT(connectDrone()));
	//connect(ui->buttonDisconnectDrone, SIGNAL(clicked(bool)), droneConnection, SLOT(doDisconnect()));
	connect(droneConnection, SIGNAL(imageRecieved(QImage)), this, SLOT(imageDrone(QImage)), Qt::DirectConnection);
	connect(droneConnection, SIGNAL(imageRecieved(QImage)), cam, SLOT(predictImageDrone(QImage)), Qt::DirectConnection);
	connect(serialConnection, SIGNAL(drone_status_changed(int)), this, SLOT(takePictOnWaypoint(int)));
	connect(this, SIGNAL(imageDroneRecieved()), droneConnection, SLOT(doDisconnect()));
	connect(ui->pushButtonTakePict, SIGNAL(clicked(bool)), this, SLOT(connectDrone()));
	connect(droneConnection, SIGNAL(imageRecieved(QImage)), net, SLOT(sendImage(QImage)), Qt::DirectConnection); // koneksi buat testing dan ambil data
	connect(cam, SIGNAL(dronePrediction(int)), kontrol, SLOT(updateDockDrone(int)), Qt::DirectConnection);



	//kontrol
	connect(this, SIGNAL(kontrol_waypoint(double, double, int)), kontrol, SLOT(tujuanWaypoint(double, double, int)));
	connect(serialConnection, SIGNAL(serial_kirim_data_GPS(double, double, float)), kontrol, SLOT(ambilDataKontrolGPS(double, double, float)));
	connect(this, SIGNAL(ubah_kontrol_PID(double, double, double)), kontrol, SLOT(ubah_PID(double, double, double)));
	connect(this, SIGNAL(send_index_plot_waypoint(int)), kontrol, SLOT(terima_index(int)));
	connect(kontrol, SIGNAL(kirim_data_kontrol(int, int, int, int, float, float, float, int)), this, SLOT(ambil_olah_kontrol(int, int, int, int, float, float, float, int)));
	connect(serialConnection, SIGNAL(serial_kirim_data_GPS(double, double, float)), kontrol, SLOT(kontrol_waypoint()));
	connect(kontrol, SIGNAL(ubah_state_imgproc(int)), cam, SLOT(state_imgproc(int)), Qt::DirectConnection);
	connect(kontrol, SIGNAL(drone_terbang(int)), serialConnection, SLOT(ubah_status_drone(int)), Qt::DirectConnection);

	//mission planner
	connect(ui->spinBoxStopMisi1, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi1(int)));
	connect(ui->spinBoxStopMisi2, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi2(int)));
	connect(ui->spinBoxStopMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi3(int)));
	connect(ui->spinBoxStopMisi4, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi4(int)));
	connect(ui->spinBoxStopMisi5, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi5(int)));
	connect(ui->spinBoxStopMisi6, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_misi6(int)));
	connect(ui->spinBoxStopReturn, SIGNAL(valueChanged(int)), kontrol, SLOT(change_stop_return(int)));
	connect(kontrol, SIGNAL(status_misi(int, int)), this, SLOT(tampil_status_misi(int, int)));

	connect(ui->spinBoxSpeedNav, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_navigation(int)));
	connect(ui->spinBoxSpeedMisi1, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi1(int)));
	connect(ui->spinBoxSpeedMisi2, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi2(int)));
	connect(ui->spinBoxSpeedTengahMisi2, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_tengah_misi2(int)));
	connect(ui->spinBoxSpeedMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi3(int)));
	connect(ui->spinBoxSpeedMisi4, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi4(int)));
	connect(ui->spinBoxSpeedMisi5, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi5(int)));
	connect(ui->spinBoxSpeedMisi6, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi6(int)));
	connect(ui->spinBoxSpeedMisi5Bawah, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi5_bawah(int)));
	connect(ui->spinBoxSpeedReturn, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_return(int)));

	connect(ui->spinBoxWaypointMisi1, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi1(int)));
	connect(ui->spinBoxWaypointMisi2, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi2(int)));
	connect(ui->spinBoxWaypointMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi3(int)));
	connect(ui->spinBoxWaypointMisi3_2, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi3_2(int)));
	connect(ui->spinBoxWaypointMisi4, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi4(int)));
	connect(ui->spinBoxWaypointMisi5, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi5(int)));
	connect(ui->spinBoxWaypointMisi6, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_misi6(int)));
	connect(ui->spinBoxWaypointReturn, SIGNAL(valueChanged(int)), kontrol, SLOT(change_waypoint_return(int)));
	connect(ui->spinBoxServoCamera, SIGNAL(valueChanged(int)), this, SLOT(ubah_posisi_camera(int)));
	connect(ui->spinBoxServoCamera2, SIGNAL(valueChanged(int)), this, SLOT(ubah_posisi_camera2(int)));
	connect(kontrol, SIGNAL(change_servo_camera(int, int)), this, SLOT(ubah_posisi_camera_misi(int, int)));
	connect(ui->spinBoxTrimMotor, SIGNAL(valueChanged(int)), kontrol, SLOT(trim_motor(int)), Qt::DirectConnection);
	connect(ui->spinBoxTrimServoKiri, SIGNAL(valueChanged(int)), kontrol, SLOT(trim_serv_kiri(int)), Qt::DirectConnection);
	connect(ui->spinBoxTrimServoKanan, SIGNAL(valueChanged(int)), kontrol, SLOT(trim_serv_kanan(int)), Qt::DirectConnection);
	connect(ui->spinBoxTimeOutMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(ubah_timeout_misi3(int)));
	connect(ui->spinBoxTimeOutMisi5, SIGNAL(valueChanged(int)), kontrol, SLOT(ubah_timeout_misi5(int)));

	connect(ui->spinBoxSpeedMisi3Atas, SIGNAL(valueChanged(int)), kontrol, SLOT(change_speed_misi3_atas(int)));
	connect(ui->spinBoxSudutMisi3, SIGNAL(valueChanged(int)), kontrol, SLOT(ambil_sudut_misi3(int)));
	connect(ui->spinBoxThresholdPinger, SIGNAL(valueChanged(int)), kontrol, SLOT(change_threshold_pinger(int)));
	connect(ui->spinBoxMaxPinger, SIGNAL(valueChanged(int)), kontrol, SLOT(change_max_pinger(int)));
	connect(ui->spinBoxThresholdFrequency, SIGNAL(valueChanged(int)), kontrol, SLOT(change_frequency_misi3(int)));

	//image processing
	connect(cam, SIGNAL(sendDataKontrol(float)), kontrol, SLOT(terima_pidout_imgproc(float)));
	connect(cam, SIGNAL(sendDataKontrol2(int, float)), kontrol, SLOT(terima_pidout_imgproc2(int, float)));

	//timer mapping
	QTimer *timer_mapping = new QTimer(this);
	connect(timer_mapping, SIGNAL(timeout()), this, SLOT(paintEvent()));
	timer_mapping->start(100);

	//timer 0 amplitude

	// server comunication 
	connect(ui->btnStartConnServer, SIGNAL(clicked(bool)), this, SLOT(startNet()));
	connect(ui->btnStopConnServer, SIGNAL(clicked(bool)), net, SLOT(stop()));
	connect(ui->btnStopConnServer, SIGNAL(clicked(bool)), this, SLOT(stopNet()));
	connect(netThread, SIGNAL(started()), net, SLOT(start()));
	connect(kontrol, SIGNAL(mission_changed(int)), net, SLOT(setCurrentMission(int)), Qt::DirectConnection);
	connect(serialConnection, SIGNAL(serial_kirim_data_GPS(double, double, float)), net, SLOT(updateGPS(double, double, float)), Qt::DirectConnection);
	connect(droneConnection, SIGNAL(imageRecieved(QImage)), net, SLOT(setImage(QImage)), Qt::DirectConnection);
}

void MainWindow::init()
{
	//skala danau 8
	//skala_latitude = (float)800 / (titik_akhir_lat - titik_awal_lat);
	//skala_longitude = (float)600 / (titik_akhir_long - titik_awal_long);

	//skala reed canal park
	skala_latitude = (float)(-1)*800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
	skala_longitude = (float)(-1)*600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia

	waypen_now.setWidth(2);
	waypen_now.setColor(Qt::black);
	waypen_now.setJoinStyle(Qt::RoundJoin);

	waypen_garis.setWidth(2);
	waypen_garis.setColor(Qt::yellow);
	waypen_garis.setJoinStyle(Qt::RoundJoin);



	// init all variable and all connection
	for (int i = 0; i < 7; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
	}
	//init thread kontrol
	//kontrolThread = new QThread();
	kontrol = new KontrolKapal();
	//kontrol->moveToThread(kontrolThread);

	// init thread cam
	camThread = new QThread();
	cam = new ImgProc();
	cam->moveToThread(camThread);

	// init thread serial connection
	serialThread = new QThread();
	serialConnection = new SerialConnection();
	serialConnection->moveToThread(serialThread);

	//init thread mapping

	// init thread drone connection
	// sementara belum bentuk tread
	droneConnection = new DroneConnection();


	// init thread communication
	net = new Networking();
	netThread = new QThread();
	net->moveToThread(netThread);

	// init all qt connection 
	initConnection();
	// set view in stacked widget
	ui->stackedWidget->setCurrentIndex(0);
	emit currentColorId(0);
	loadStatus = false;

	// init mission planer setting
	/*missionSetting["misi1"]["waypoint"] = (float) ui->spinBoxWaypointMisi1->value();
	missionSetting["misi1"]["sudut"] = (float) ui->spinBoxSudutMisi1->value();
	missionSetting["misi1"]["speed"] = (float) ui->spinBoxSpeedMisi1->value();
	missionSetting["misi2"]["speed"] = (float) ui->spinBoxSpeedMisi2->value();
	missionSetting["misi2"]["waypoint"] = (float) ui->spinBoxWaypointMisi2->value();
	missionSetting["misi3"]["speed"] = (float) ui->spinBoxSpeedMisi3->value();
	missionSetting["misi3"]["waypoint"] = (float)ui->spinBoxWaypointMisi3->value();
	missionSetting["misi3"]["sudut"] = (float)ui->spinBoxSudutMisi3->value();
	missionSetting["misi3"]["status"] = (float)ui->spinboxStatusMisi3->value();
	missionSetting["misi4"]["waypoint"] = (float)ui->spinBoxWaypointMisi4->value();
	missionSetting["misi4"]["speed"] = (float)ui->spinBoxSpeedMisi4->value();
	misisonSetting["misi5"]["speed"] = (float)ui->spinBoxSpeedMisi5->value();
	missionSetting["misi5"]["waypoint"] = (float)ui->spinBoxWaypointMisi5();
	missionSetting["return"]["preference"] = ui->comboBoxReturn->currentIndex();
	missionSetting["return"]["waypoint"] = (float) ui->spinBoxWaypointMisi5->value();
	missionSetting["return"]["waypoint"] = (float)ui->spinBoxSpeedReturn->value();
	missionSetting["navigation"]["speed"] = (float)ui->spinBoxSpeedNav->value();
	missionSetting["navigation"]["servo"] = (float)ui->spinBoxServoCamera->value();*/
}

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	init();
}

MainWindow::~MainWindow()
{
	stopCam();
	stopSerial();
	delete camThread;
	delete cam;
	delete ui;
	delete serialThread;
	delete serialConnection;
}

void MainWindow::startCam() {
	// starting camera
	cam->status = true;
	if (!camThread->isRunning())camThread->start();
	ui->startButton->setEnabled(false);
	ui->stopButton->setEnabled(true);
}

void MainWindow::stopCam() {
	// stopping camera
	cam->status = false;
	camThread->wait(100);
	if (camThread->isRunning())camThread->quit();
	ui->startButton->setEnabled(true);
	ui->stopButton->setEnabled(false);
	ui->labelOri->clear();
	ui->labelWarna1->clear();
	ui->labelWarna2->clear();
	ui->labelWarna3->clear();
	ui->labelWarna4->clear();
	ui->labelWarna5->clear();
	ui->labelWarna6->clear();
	ui->labelWarna7->clear();
}

void MainWindow::updateLabel() {
	// update label view
	ui->labelOri->setPixmap(QPixmap::fromImage(cam->imgOri));
	ui->labelWarna1->setPixmap(QPixmap::fromImage(cam->imgWarna[0]));
	ui->labelWarna2->setPixmap(QPixmap::fromImage(cam->imgWarna[1]));
	ui->labelWarna3->setPixmap(QPixmap::fromImage(cam->imgWarna[2]));
	ui->labelWarna4->setPixmap(QPixmap::fromImage(cam->imgWarna[3]));
	ui->labelWarna5->setPixmap(QPixmap::fromImage(cam->imgWarna[4]));
	ui->labelWarna6->setPixmap(QPixmap::fromImage(cam->imgWarna[5]));
	ui->labelWarna7->setPixmap(QPixmap::fromImage(cam->imgWarna[6]));
	//qDebug() << "Update cong";
	//qDebug() << cam->imgWarna[0];
}

void MainWindow::on_save() {
	if (fileName.isEmpty()) {
		fileName = QFileDialog::getSaveFileName(this,
			tr("Save HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	}
	if (fileName.isEmpty()) {
		return;
	}
	else {
		QFile file(fileName);
		// cek apa file kebacasss
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa membuka file"), file.errorString());
			return;
		}
		QTextStream out(&file);
		QString buff = "", delim = ",";
		for (int i = 0; i < 7; i++) {
			buff += QString::number(hMin[i]);
			buff += delim;
			buff += QString::number(sMin[i]);
			buff += delim;
			buff += QString::number(vMin[i]);
			buff += delim;
			buff += QString::number(hMax[i]);
			buff += delim;
			buff += QString::number(sMax[i]);
			buff += delim;
			buff += QString::number(vMax[i]);
			buff += delim;
			buff += QString::number(erode[i]);
			buff += delim;
			buff += QString::number(dilate[i]);
			buff += "\n";
		}

		out << buff;
	}
}

void MainWindow::on_save_as() {
	fileName = QFileDialog::getSaveFileName(this,
		tr("Save HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	on_save();
}

void MainWindow::on_load() {
	QString buffer;
	fileName = QFileDialog::getOpenFileName(this,
		tr("Load HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	if (fileName.isEmpty()) {
		//qDebug() << "kok empty??";
		return;
	}
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa memuat file."), file.errorString());
			return;
		}
		loadStatus = true;
		QTextStream in(&file);
		for (int i = 0; i < 5; i++) {
			in >> buffer;
			//qDebug() << "Buffer: " << buffer;

			QStringList wordList = buffer.split(",");
			//qDebug() << wordList;
			hMin[i] = wordList[0].toInt();
			sMin[i] = wordList[1].toInt();
			vMin[i] = wordList[2].toInt();
			hMax[i] = wordList[3].toInt();
			sMax[i] = wordList[4].toInt();
			vMax[i] = wordList[5].toInt();
			erode[i] = wordList[6].toInt();
			dilate[i] = wordList[7].toInt();
			qDebug() << hMin[i] << sMin[i] << vMin[i] << hMax[i] << sMax[i] << vMax[i] << erode[i] << dilate[i];
		}
		emit updateHSV();
		loadStatus = false;
	}

}

void MainWindow::changeSliderval() {
	if (!loadStatus) {
		//qDebug() << ui->speedSlider->value();
		dilate[0] = ui->dilate1->value();
		erode[0] = ui->erode1->value();
		hMin[0] = ui->hMin1->value();
		hMax[0] = ui->hMax1->value();
		sMax[0] = ui->sMax1->value();
		sMin[0] = ui->sMin1->value();
		vMin[0] = ui->vMin1->value();
		vMax[0] = ui->vMax1->value();

		dilate[1] = ui->dilate2->value();
		erode[1] = ui->erode2->value();
		hMin[1] = ui->hMin2->value();
		hMax[1] = ui->hMax2->value();
		sMax[1] = ui->sMax2->value();
		sMin[1] = ui->sMin2->value();
		vMin[1] = ui->vMin2->value();
		vMax[1] = ui->vMax2->value();

		dilate[2] = ui->dilate3->value();
		erode[2] = ui->erode3->value();
		hMin[2] = ui->hMin3->value();
		hMax[2] = ui->hMax3->value();
		sMax[2] = ui->sMax3->value();
		sMin[2] = ui->sMin3->value();
		vMin[2] = ui->vMin3->value();
		vMax[2] = ui->vMax3->value();

		dilate[3] = ui->dilate4->value();
		erode[3] = ui->erode4->value();
		hMin[3] = ui->hMin4->value();
		hMax[3] = ui->hMax4->value();
		sMax[3] = ui->sMax4->value();
		sMin[3] = ui->sMin4->value();
		vMin[3] = ui->vMin4->value();
		vMax[3] = ui->vMax4->value();

		dilate[4] = ui->dilate5->value();
		erode[4] = ui->erode5->value();
		hMin[4] = ui->hMin5->value();
		hMax[4] = ui->hMax5->value();
		sMax[4] = ui->sMax5->value();
		sMin[4] = ui->sMin5->value();
		vMin[4] = ui->vMin5->value();
		vMax[4] = ui->vMax5->value();

		dilate[5] = ui->dilate6->value();
		erode[5] = ui->erode6->value();
		hMin[5] = ui->hMin6->value();
		hMax[5] = ui->hMax6->value();
		sMax[5] = ui->sMax6->value();
		sMin[5] = ui->sMin6->value();
		vMin[5] = ui->vMin6->value();
		vMax[5] = ui->vMax6->value();

		dilate[6] = ui->dilate7->value();
		erode[6] = ui->erode7->value();
		hMin[6] = ui->hMin7->value();
		hMax[6] = ui->hMax7->value();
		sMax[6] = ui->sMax7->value();
		sMin[6] = ui->sMin7->value();
		vMin[6] = ui->vMin7->value();
		vMax[6] = ui->vMax7->value();

		ui->dilateVal1->setText(QString::number(dilate[0]));
		ui->erodeVal1->setText(QString::number(erode[0]));
		ui->hMinVal1->setText(QString::number(hMin[0]));
		ui->hMaxVal1->setText(QString::number(hMax[0]));
		ui->sMinVal1->setText(QString::number(sMin[0]));
		ui->sMaxVal1->setText(QString::number(sMax[0]));
		ui->vMinVal1->setText(QString::number(vMin[0]));
		ui->vMaxVal1->setText(QString::number(vMax[0]));

		ui->dilate1->setValue(dilate[0]);
		ui->erode1->setValue(erode[0]);
		ui->hMin1->setValue(hMin[0]);
		ui->hMax1->setValue(hMax[0]);
		ui->sMin1->setValue(sMin[0]);
		ui->sMax1->setValue(sMax[0]);
		ui->vMin1->setValue(vMin[0]);
		ui->vMax1->setValue(vMax[0]);

		ui->dilateVal2->setText(QString::number(dilate[1]));
		ui->erodeVal2->setText(QString::number(erode[1]));
		ui->hMinVal2->setText(QString::number(hMin[1]));
		ui->hMaxVal2->setText(QString::number(hMax[1]));
		ui->sMinVal2->setText(QString::number(sMin[1]));
		ui->sMaxVal2->setText(QString::number(sMax[1]));
		ui->vMinVal2->setText(QString::number(vMin[1]));
		ui->vMaxVal2->setText(QString::number(vMax[1]));

		ui->dilate2->setValue(dilate[1]);
		ui->erode2->setValue(erode[1]);
		ui->hMin2->setValue(hMin[1]);
		ui->hMax2->setValue(hMax[1]);
		ui->sMin2->setValue(sMin[1]);
		ui->sMax2->setValue(sMax[1]);
		ui->vMin2->setValue(vMin[1]);
		ui->vMax2->setValue(vMax[1]);

		ui->dilateVal3->setText(QString::number(dilate[2]));
		ui->erodeVal3->setText(QString::number(erode[2]));
		ui->hMinVal3->setText(QString::number(hMin[2]));
		ui->hMaxVal3->setText(QString::number(hMax[2]));
		ui->sMinVal3->setText(QString::number(sMin[2]));
		ui->sMaxVal3->setText(QString::number(sMax[2]));
		ui->vMinVal3->setText(QString::number(vMin[2]));
		ui->vMaxVal3->setText(QString::number(vMax[2]));

		ui->dilate3->setValue(dilate[2]);
		ui->erode3->setValue(erode[2]);
		ui->hMin3->setValue(hMin[2]);
		ui->hMax3->setValue(hMax[2]);
		ui->sMin3->setValue(sMin[2]);
		ui->sMax3->setValue(sMax[2]);
		ui->vMin3->setValue(vMin[2]);
		ui->vMax3->setValue(vMax[2]);

		ui->dilateVal4->setText(QString::number(dilate[3]));
		ui->erodeVal4->setText(QString::number(erode[3]));
		ui->hMinVal4->setText(QString::number(hMin[3]));
		ui->hMaxVal4->setText(QString::number(hMax[3]));
		ui->sMinVal4->setText(QString::number(sMin[3]));
		ui->sMaxVal4->setText(QString::number(sMax[3]));
		ui->vMinVal4->setText(QString::number(vMin[3]));
		ui->vMaxVal4->setText(QString::number(vMax[3]));

		ui->dilate4->setValue(dilate[3]);
		ui->erode4->setValue(erode[3]);
		ui->hMin4->setValue(hMin[3]);
		ui->hMax4->setValue(hMax[3]);
		ui->sMin4->setValue(sMin[3]);
		ui->sMax4->setValue(sMax[3]);
		ui->vMin4->setValue(vMin[3]);
		ui->vMax4->setValue(vMax[3]);

		ui->dilateVal5->setText(QString::number(dilate[4]));
		ui->erodeVal5->setText(QString::number(erode[4]));
		ui->hMinVal5->setText(QString::number(hMin[4]));
		ui->hMaxVal5->setText(QString::number(hMax[4]));
		ui->sMinVal5->setText(QString::number(sMin[4]));
		ui->sMaxVal5->setText(QString::number(sMax[4]));
		ui->vMinVal5->setText(QString::number(vMin[4]));
		ui->vMaxVal5->setText(QString::number(vMax[4]));

		ui->dilate5->setValue(dilate[4]);
		ui->erode5->setValue(erode[4]);
		ui->hMin5->setValue(hMin[4]);
		ui->hMax5->setValue(hMax[4]);
		ui->sMin5->setValue(sMin[4]);
		ui->sMax5->setValue(sMax[4]);
		ui->vMin5->setValue(vMin[4]);
		ui->vMax5->setValue(vMax[4]);

		ui->dilateVal6->setText(QString::number(dilate[5]));
		ui->erodeVal6->setText(QString::number(erode[5]));
		ui->hMinVal6->setText(QString::number(hMin[5]));
		ui->hMaxVal6->setText(QString::number(hMax[5]));
		ui->sMinVal6->setText(QString::number(sMin[5]));
		ui->sMaxVal6->setText(QString::number(sMax[5]));
		ui->vMinVal6->setText(QString::number(vMin[5]));
		ui->vMaxVal6->setText(QString::number(vMax[5]));

		ui->dilate6->setValue(dilate[5]);
		ui->erode6->setValue(erode[5]);
		ui->hMin6->setValue(hMin[5]);
		ui->hMax6->setValue(hMax[5]);
		ui->sMin6->setValue(sMin[5]);
		ui->sMax6->setValue(sMax[5]);
		ui->vMin6->setValue(vMin[5]);
		ui->vMax6->setValue(vMax[5]);

		ui->dilateVal7->setText(QString::number(dilate[6]));
		ui->erodeVal7->setText(QString::number(erode[6]));
		ui->hMinVal7->setText(QString::number(hMin[6]));
		ui->hMaxVal7->setText(QString::number(hMax[6]));
		ui->sMinVal7->setText(QString::number(sMin[6]));
		ui->sMaxVal7->setText(QString::number(sMax[6]));
		ui->vMinVal7->setText(QString::number(vMin[6]));
		ui->vMaxVal7->setText(QString::number(vMax[6]));

		ui->dilate7->setValue(dilate[6]);
		ui->erode7->setValue(erode[6]);
		ui->hMin7->setValue(hMin[6]);
		ui->hMax7->setValue(hMax[6]);
		ui->sMin7->setValue(sMin[6]);
		ui->sMax7->setValue(sMax[6]);
		ui->vMin7->setValue(vMin[6]);
		ui->vMax7->setValue(vMax[6]);
		
		// send hsv value to image processing thread
		emit sendHSV(
			ui->hMin1->value(),
			ui->sMin1->value(),
			ui->vMin1->value(),
			ui->hMax1->value(),
			ui->sMax1->value(),
			ui->vMax1->value(),
			ui->erode1->value(),
			ui->dilate1->value(),
			0
		);
		emit sendHSV(
			ui->hMin2->value(),
			ui->sMin2->value(),
			ui->vMin2->value(),
			ui->hMax2->value(),
			ui->sMax2->value(),
			ui->vMax2->value(),
			ui->erode2->value(),
			ui->dilate2->value(),
			1
		);
		emit sendHSV(
			ui->hMin3->value(),
			ui->sMin3->value(),
			ui->vMin3->value(),
			ui->hMax3->value(),
			ui->sMax3->value(),
			ui->vMax3->value(),
			ui->erode3->value(),
			ui->dilate3->value(),
			2
		);
		emit sendHSV(
			ui->hMin4->value(),
			ui->sMin4->value(),
			ui->vMin4->value(),
			ui->hMax4->value(),
			ui->sMax4->value(),
			ui->vMax4->value(),
			ui->erode4->value(),
			ui->dilate4->value(),
			3
		);
		emit sendHSV(
			ui->hMin5->value(),
			ui->sMin5->value(),
			ui->vMin5->value(),
			ui->hMax5->value(),
			ui->sMax5->value(),
			ui->vMax5->value(),
			ui->erode5->value(),
			ui->dilate5->value(),
			4
		);
		emit sendHSV(
			ui->hMin6->value(),
			ui->sMin6->value(),
			ui->vMin6->value(),
			ui->hMax6->value(),
			ui->sMax6->value(),
			ui->vMax6->value(),
			ui->erode6->value(),
			ui->dilate6->value(),
			5
		);

		emit sendHSV(
			ui->hMin7->value(),
			ui->sMin7->value(),
			ui->vMin7->value(),
			ui->hMax7->value(),
			ui->sMax7->value(),
			ui->vMax7->value(),
			ui->erode7->value(),
			ui->dilate7->value(),
			6
		);

		//speed = ui->speedSlider->value();
		emit changeSpeed(speed);
	}

}

void MainWindow::loadHSV() {
	loadStatus = true;
	for (int i = 0; i < 7; i++) {
		qDebug() << "emit hsv on loadHSV";
		emit sendHSV(hMin[i], sMin[i], vMin[i], hMax[i], sMax[i], vMax[i], erode[i], dilate[i], i);
	}

	ui->dilate1->setValue(dilate[0]);
	ui->erode1->setValue(erode[0]);
	ui->hMin1->setValue(hMin[0]);
	ui->hMax1->setValue(hMax[0]);
	ui->sMin1->setValue(sMin[0]);
	ui->sMax1->setValue(sMax[0]);
	ui->vMin1->setValue(vMin[0]);
	ui->vMax1->setValue(vMax[0]);

	ui->dilate2->setValue(dilate[1]);
	ui->erode2->setValue(erode[1]);
	ui->hMin2->setValue(hMin[1]);
	ui->hMax2->setValue(hMax[1]);
	ui->sMin2->setValue(sMin[1]);
	ui->sMax2->setValue(sMax[1]);
	ui->vMin2->setValue(vMin[1]);
	ui->vMax2->setValue(vMax[1]);

	ui->dilate3->setValue(dilate[2]);
	ui->erode3->setValue(erode[2]);
	ui->hMin3->setValue(hMin[2]);
	ui->hMax3->setValue(hMax[2]);
	ui->sMin3->setValue(sMin[2]);
	ui->sMax3->setValue(sMax[2]);
	ui->vMin3->setValue(vMin[2]);
	ui->vMax3->setValue(vMax[2]);

	ui->dilate4->setValue(dilate[3]);
	ui->erode4->setValue(erode[3]);
	ui->hMin4->setValue(hMin[3]);
	ui->hMax4->setValue(hMax[3]);
	ui->sMin4->setValue(sMin[3]);
	ui->sMax4->setValue(sMax[3]);
	ui->vMin4->setValue(vMin[3]);
	ui->vMax4->setValue(vMax[3]);

	ui->dilate5->setValue(dilate[4]);
	ui->erode5->setValue(erode[4]);
	ui->hMin5->setValue(hMin[4]);
	ui->hMax5->setValue(hMax[4]);
	ui->sMin5->setValue(sMin[4]);
	ui->sMax5->setValue(sMax[4]);
	ui->vMin5->setValue(vMin[4]);
	ui->vMax5->setValue(vMax[4]);

	ui->dilate6->setValue(dilate[5]);
	ui->erode6->setValue(erode[5]);
	ui->hMin6->setValue(hMin[5]);
	ui->hMax6->setValue(hMax[5]);
	ui->sMin6->setValue(sMin[5]);
	ui->sMax6->setValue(sMax[5]);
	ui->vMin6->setValue(vMin[5]);
	ui->vMax6->setValue(vMax[5]);

	ui->dilate7->setValue(dilate[6]);
	ui->erode7->setValue(erode[6]);
	ui->hMin7->setValue(hMin[6]);
	ui->hMax7->setValue(hMax[6]);
	ui->sMin7->setValue(sMin[6]);
	ui->sMax7->setValue(sMax[6]);
	ui->vMin7->setValue(vMin[6]);
	ui->vMax7->setValue(vMax[6]);

	ui->dilateVal1->setText(QString::number(dilate[0]));
	ui->erodeVal1->setText(QString::number(erode[0]));
	ui->hMinVal1->setText(QString::number(hMin[0]));
	ui->hMaxVal1->setText(QString::number(hMax[0]));
	ui->sMinVal1->setText(QString::number(sMin[0]));
	ui->sMaxVal1->setText(QString::number(sMax[0]));
	ui->vMinVal1->setText(QString::number(vMin[0]));
	ui->vMaxVal1->setText(QString::number(vMax[0]));

	ui->dilateVal2->setText(QString::number(dilate[1]));
	ui->erodeVal2->setText(QString::number(erode[1]));
	ui->hMinVal2->setText(QString::number(hMin[1]));
	ui->hMaxVal2->setText(QString::number(hMax[1]));
	ui->sMinVal2->setText(QString::number(sMin[1]));
	ui->sMaxVal2->setText(QString::number(sMax[1]));
	ui->vMinVal2->setText(QString::number(vMin[1]));
	ui->vMaxVal2->setText(QString::number(vMax[1]));

	ui->dilateVal3->setText(QString::number(dilate[2]));
	ui->erodeVal3->setText(QString::number(erode[2]));
	ui->hMinVal3->setText(QString::number(hMin[2]));
	ui->hMaxVal3->setText(QString::number(hMax[2]));
	ui->sMinVal3->setText(QString::number(sMin[2]));
	ui->sMaxVal3->setText(QString::number(sMax[2]));
	ui->vMinVal3->setText(QString::number(vMin[2]));
	ui->vMaxVal3->setText(QString::number(vMax[2]));

	ui->dilateVal4->setText(QString::number(dilate[3]));
	ui->erodeVal4->setText(QString::number(erode[3]));
	ui->hMinVal4->setText(QString::number(hMin[3]));
	ui->hMaxVal4->setText(QString::number(hMax[3]));
	ui->sMinVal4->setText(QString::number(sMin[3]));
	ui->sMaxVal4->setText(QString::number(sMax[3]));
	ui->vMinVal4->setText(QString::number(vMin[3]));
	ui->vMaxVal4->setText(QString::number(vMax[3]));

	ui->dilateVal5->setText(QString::number(dilate[4]));
	ui->erodeVal5->setText(QString::number(erode[4]));
	ui->hMinVal5->setText(QString::number(hMin[4]));
	ui->hMaxVal5->setText(QString::number(hMax[4]));
	ui->sMinVal5->setText(QString::number(sMin[4]));
	ui->sMaxVal5->setText(QString::number(sMax[4]));
	ui->vMinVal5->setText(QString::number(vMin[4]));
	ui->vMaxVal5->setText(QString::number(vMax[4]));
	loadStatus = false;
}

void MainWindow::pidChanged() {
	//if (!loadStatus) {
		pid[0] = (float)ui->spinBoxP1->value() / 100.0;
		pid[1] = (float)ui->spinBoxI1->value() / 100.0;
		pid[2] = (float)ui->spinBoxD1->value() / 100.0;
		//qDebug() << pid[0] << " " << pid[1] << " " << pid[2];
		qDebug() << pid[0] << pid[1] << pid[2] << endl;
		emit changePID(pid[0], pid[1], pid[2]);
	///}

	//loadStatus = false;
}

void MainWindow::pidChanged_2() {
	//if (!loadStatus) {
		pid[0] = (float)ui->spinBoxP2->value() / 100.0;
		pid[1] = (float)ui->spinBoxI2->value() / 100.0;
		pid[2] = (float)ui->spinBoxD2->value() / 100.0;
		//qDebug() << pid[0] << " " << pid[1] << " " << pid[2];
		qDebug() << pid[0] << pid[1] << pid[2] << endl;
		emit changePID_2(pid[0], pid[1], pid[2]);
	//}

}

void MainWindow::pidChanged_3() {
	//if (!loadStatus) {
		pid[0] = (float)ui->spinBoxP3->value() / 100.0;
		pid[1] = (float)ui->spinBoxI3->value() / 100.0;
		pid[2] = (float)ui->spinBoxD3->value() / 100.0;
		//qDebug() << pid[0] << pid[1] << pid[2] << endl;
		emit changePID_3(pid[0], pid[1], pid[2]);
	//}
}

void MainWindow::changeViewWarna() {
	ui->stackedWidget->setCurrentIndex(ui->warnaSelector->currentIndex());
	emit currentColorId(ui->warnaSelector->currentIndex());
}

void MainWindow::startSerial() {
	// handling is running condition
	if (!serialThread->isRunning()) serialThread->start();
	//if (!kontrolThread->isRunning()) kontrolThread->start();
	ui->pushButtonOpenPort->setEnabled(false);
	ui->pushButtonClosePort->setEnabled(true);
}

void MainWindow::stopSerial() {
	serialThread->wait(100);
	if (serialThread->isRunning()) serialThread->quit();
	//if (kontrolThread->isRunning()) kontrolThread->quit();
	ui->pushButtonOpenPort->setEnabled(true);
	ui->pushButtonClosePort->setEnabled(false);
}

float radius_navigasi = 1.8;
float radius_misi4 = 1.0;

void MainWindow::ubah_radius_navigasi()
{
	radius_navigasi = ui->doubleSpinBoxRadiusNavigasi->value();
}

void MainWindow::ubah_radius_misi4()
{
	radius_misi4 = ui->doubleSpinBoxRadiusMisi4->value();
}

void MainWindow::ubah_offset()
{
	offset = ui->spinBoxOffset->value();
	emit ubah_offset_serial(offset);
}

void MainWindow::showDataGPS(double latt, double lon, float comp)
{
	if (status_waypoint)
	{
		if (jarak < radius_navigasi && (kontrol->mission_state != 3 || kontrol->mission_state != 4))
		{
			index_plot_waypoint++;
			emit  send_index_plot_waypoint(index_plot_waypoint);
		}
		else if (jarak < radius_misi4)
		{
			index_plot_waypoint++;
			emit  send_index_plot_waypoint(index_plot_waypoint);
		}
	}
	latitude_sekarang = latt;
	longitude_sekarang = lon;
	compass_sekarang = comp;

	ui->lineEditLattitude->setText(QString::number(latt, 'g', 10));
	ui->lineEditLongitude->setText(QString::number(lon, 'g', 10));
	ui->lineEditCompass->setText(QString::number(comp));

	ui->lineEditTujuanLat->setText(QString::number(lattitudeWaypoint[index_plot_waypoint], 'g', 10));
	ui->lineEditTujuanLong->setText(QString::number(longitudeWaypoint[index_plot_waypoint], 'g', 10));

	ui->lcdNumberWaypoint->display(index_plot_waypoint);
}

void MainWindow::showDataSRF(int srf1, int srf2, int srf3, int srf4, int srf5)
{
	ui->lineEditSRFKiri->setText(QString::number(srf1));
	ui->lineEditSRFTengah1->setText(QString::number(srf2));
	ui->lineEditSRFTengah2->setText(QString::number(srf3));
	ui->lineEditSRFKanan->setText(QString::number(srf4));
	ui->lineEditSRFSamping->setText(QString::number(srf5));
}
void MainWindow::showDataHydro(int freq, int amp)
{
	ui->lineEditFrequency->setText(QString::number(freq));
	ui->lineEditAmplitudoKiri->setText(QString::number(amp));



}
void MainWindow::showDataDrone(int gambar, int mendarat)
{
	//qDebug() << "Status ambil gambar: " << gambar;
	//qDebug() << "Status mendarat: " << mendarat;
}

void MainWindow::updateDataKirim()
{
	//serialConnection->MotorKiri = ui->lineEditMotorKiri->text().toInt();
	//serialConnection->MotorKanan = ui->lineEditMotorKanan->text().toInt();
}

void MainWindow::showMousePosition(QPoint &pos)
{
	ui->lineEditXposition->setText(QString::number(pos.x()));
	ui->lineEditYposition->setText(QString::number(pos.y()));
}

void MainWindow::left_clicked()
{
	//posisi_kapal_sekarang.setY((abs(lattitudeWaypoint[index_plot_waypoint]) * 10000000 - titik_awal_lat) * skala_latitude);
	int s[2];
	double ss[2];
	s[0] = ui->lineEditYposition->text().toInt();
	ss[0] = ((s[0] / skala_latitude) + titik_awal_lat) / 10000000;
	s[1] = ui->lineEditXposition->text().toInt();
	ss[1] = ((s[1] / skala_longitude) + titik_awal_long) / (-10000000);
	latitude[index_waypoint] = QString::number(ss[0]);
	longitude[index_waypoint] = QString::number(ss[1]);

	QTableWidgetItem* latt = new QTableWidgetItem(latitude[index_waypoint]);
	QTableWidgetItem* longi = new QTableWidgetItem(longitude[index_waypoint]);

	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 0, latt);
	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 1, longi);

	lattitudeWaypoint[index_waypoint] = ss[0];
	longitudeWaypoint[index_waypoint] = ss[1];

	emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);
}

void MainWindow::right_clicked()
{
	int s[2];
	double ss[2];
	s[0] = ui->lineEditYposition->text().toInt();
	ss[0] = ((s[0] / skala_latitude) + titik_awal_lat) / 10000000;
	s[1] = ui->lineEditXposition->text().toInt();
	ss[1] = ((s[1] / skala_longitude) + titik_awal_long) / (-10000000);

	ui->lineEditInputLatt->setText(QString::number(ss[0], 'g', 10));
	ui->lineEditInputLong->setText(QString::number(ss[1], 'g', 10));
}

void MainWindow::connectDrone() {
	QString ip = ui->ipHP->text();
	quint16 port = ui->portHP->text().toShort();
	droneConnection->doConnect(ip, port);
}

void MainWindow::disconnectDrone() {
	droneConnection->disconnect();
}

void MainWindow::setIndexWaypoint(int index)
{
	index_waypoint = index;
	if (index_waypoint > max_waypoint)
	{
		max_waypoint = index_waypoint;
	}
}

void MainWindow::all_waypoint_geser_atas()
{
	if (ui->checkBoxMoveAllWaypoint->isChecked())
	{
		for (int zero = 1; zero <= max_waypoint; zero++)
		{
			lattitudeWaypoint[zero] = lattitudeWaypoint[zero] + 0.0000018;

			latitude[zero] = QString::number(lattitudeWaypoint[zero], 'g', 7);

			QTableWidgetItem* latt = new QTableWidgetItem(latitude[zero]);

			ui->tableWidgetWaypoint->setItem(zero - 1, 0, latt);

			emit kontrol_waypoint(lattitudeWaypoint[zero], longitudeWaypoint[zero], zero);
		}
	}
	else {
		lattitudeWaypoint[index_waypoint] = lattitudeWaypoint[index_waypoint] + 0.0000018;

		latitude[index_waypoint] = QString::number(lattitudeWaypoint[index_waypoint], 'g', 7);

		QTableWidgetItem* latt = new QTableWidgetItem(latitude[index_waypoint]);

		ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 0, latt);

		emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);
	}
}

void MainWindow::all_waypoint_geser_kiri()
{
	if (ui->checkBoxMoveAllWaypoint->isChecked())
	{
		for (int zero = 1; zero <= max_waypoint; zero++)
		{
			longitudeWaypoint[zero] = longitudeWaypoint[zero] - 0.0000018;

			longitude[zero] = QString::number(longitudeWaypoint[zero], 'g', 7);

			QTableWidgetItem* longi = new QTableWidgetItem(longitude[zero]);

			ui->tableWidgetWaypoint->setItem(zero - 1, 1, longi);

			emit kontrol_waypoint(lattitudeWaypoint[zero], longitudeWaypoint[zero], zero);
		}
	}
	else {
		longitudeWaypoint[index_waypoint] = longitudeWaypoint[index_waypoint] - 0.0000018;

		longitude[index_waypoint] = QString::number(longitudeWaypoint[index_waypoint], 'g', 7);

		QTableWidgetItem* longi = new QTableWidgetItem(longitude[index_waypoint]);

		ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 1, longi);

		emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);
	}
}

void MainWindow::all_waypoint_geser_kanan()
{
	if (ui->checkBoxMoveAllWaypoint->isChecked())
	{
		for (int zero = 1; zero <= max_waypoint; zero++)
		{
			longitudeWaypoint[zero] = longitudeWaypoint[zero] + 0.0000018;

			longitude[zero] = QString::number(longitudeWaypoint[zero], 'g', 7);

			QTableWidgetItem* longi = new QTableWidgetItem(longitude[zero]);

			ui->tableWidgetWaypoint->setItem(zero - 1, 1, longi);

			emit kontrol_waypoint(lattitudeWaypoint[zero], longitudeWaypoint[zero], zero);
		}
	}
	else {
		longitudeWaypoint[index_waypoint] = longitudeWaypoint[index_waypoint] + 0.0000018;

		longitude[index_waypoint] = QString::number(longitudeWaypoint[index_waypoint], 'g', 7);

		QTableWidgetItem* longi = new QTableWidgetItem(longitude[index_waypoint]);

		ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 1, longi);

		emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);
	}
}

void MainWindow::all_waypoint_geser_bawah()
{
	if (ui->checkBoxMoveAllWaypoint->isChecked())
	{
		for (int zero = 1; zero <= max_waypoint; zero++)
		{
			lattitudeWaypoint[zero] = lattitudeWaypoint[zero] - 0.0000018;

			latitude[zero] = QString::number(lattitudeWaypoint[zero], 'g', 7);

			QTableWidgetItem* latt = new QTableWidgetItem(latitude[zero]);

			ui->tableWidgetWaypoint->setItem(zero - 1, 0, latt);

			emit kontrol_waypoint(lattitudeWaypoint[zero], longitudeWaypoint[zero], zero);
		}
	}
	else {
		lattitudeWaypoint[index_waypoint] = lattitudeWaypoint[index_waypoint] - 0.0000018;

		latitude[index_waypoint] = QString::number(lattitudeWaypoint[index_waypoint], 'g', 7);

		QTableWidgetItem* latt = new QTableWidgetItem(latitude[index_waypoint]);

		ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 0, latt);

		emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);
	}
}

void MainWindow::setWaypoint()
{
	latitude[index_waypoint] = QString::number(latitude_sekarang, 'g', 7);
	longitude[index_waypoint] = QString::number(longitude_sekarang, 'g', 7);

	QTableWidgetItem* latt = new QTableWidgetItem(latitude[index_waypoint]);
	QTableWidgetItem* longi = new QTableWidgetItem(longitude[index_waypoint]);

	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 0, latt);
	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 1, longi);

	lattitudeWaypoint[index_waypoint] = ui->lineEditLattitude->text().toDouble();
	longitudeWaypoint[index_waypoint] = ui->lineEditLongitude->text().toDouble();

	emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);

	ui->spinBoxWaypoint->setValue(index_waypoint + 1);
}

void MainWindow::input_waypoint()
{
	lattitudeWaypoint[index_waypoint] = ui->lineEditInputLatt->text().toDouble();
	longitudeWaypoint[index_waypoint] = ui->lineEditInputLong->text().toDouble();

	latitude[index_waypoint] = QString::number(lattitudeWaypoint[index_waypoint], 'g', 7);
	longitude[index_waypoint] = QString::number(longitudeWaypoint[index_waypoint], 'g', 7);

	QTableWidgetItem* latt = new QTableWidgetItem(latitude[index_waypoint]);
	QTableWidgetItem* longi = new QTableWidgetItem(longitude[index_waypoint]);

	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 0, latt);
	ui->tableWidgetWaypoint->setItem(index_waypoint - 1, 1, longi);

	emit kontrol_waypoint(lattitudeWaypoint[index_waypoint], longitudeWaypoint[index_waypoint], index_waypoint);

}

QPoint posisi_kapal_sekarang;
QPoint posisi_tujuan_kapal;
QPoint posisi_waypoint;

float latitudePlot;
float longitudePlot;

void MainWindow::startplot()
{
	status_waypoint = true;
	ui->pushButtonStopMission->setEnabled(true);
	ui->pushButtonStartMission->setEnabled(false);
}

void MainWindow::stopplot()
{
	status_waypoint = false;
	ui->pushButtonStopMission->setEnabled(false);
	ui->pushButtonStartMission->setEnabled(true);
	index_plot_waypoint = 1;
	emit send_index_plot_waypoint(index_plot_waypoint);
}

void MainWindow::reset()
{
	memset(lattitudeWaypoint, NULLPOINT, sizeof(lattitudeWaypoint));
	memset(longitudeWaypoint, NULLPOINT, sizeof(longitudeWaypoint));
	ui->tableWidgetWaypoint->clear();
	ui->spinBoxWaypoint->setValue(0);
	index_plot_waypoint = 1;
	index_waypoint = 1;
	max_waypoint = 1;

	emit send_index_plot_waypoint(index_plot_waypoint);
}

void MainWindow::retry() {
	index_plot_waypoint = 1;
	emit send_index_plot_waypoint(index_plot_waypoint);

	emit reset_kontrol();
	emit reset_serialConnection();
}
void MainWindow::retrytomisi2() {
	index_plot_waypoint = 8;
	emit send_index_plot_waypoint(index_plot_waypoint);

	emit reset_kontrol();
	emit reset_serialConnection();
}

int tampil_misi = 0;

void MainWindow::tampil_status_misi(int misi, int misi3) {
	tampil_misi = misi;

	qDebug() << tampil_misi;

	if (tampil_misi == 0)
	{
		ui->lineEditMissionStatus->setText("Navigation");
	}
	else if (tampil_misi == 1)
	{
		ui->lineEditMissionStatus->setText("Misi 1 Gate");
	}
	else if (tampil_misi == 2)
	{
		ui->lineEditMissionStatus->setText("Misi 2 Speed Challenge");
	}
	else if (tampil_misi == 3)
	{
		ui->lineEditMissionStatus->setText("Misi 3 Docking + Drone");
		if (misi3 == 0)
		{
			ui->lineEditStatusMisi3->setText("Cari Waypoint Dock");
		}
		else if (misi3 == 1)
		{
			ui->lineEditStatusMisi3->setText("Find the First Dock");
		}
		else if (misi3 == 2)
		{
			ui->lineEditStatusMisi3->setText("Rotate");
		}
		else if (misi3 == 3)
		{
			ui->lineEditStatusMisi3->setText("Docking 1...");
		}
		else if (misi3 == 5)
		{
			ui->lineEditStatusMisi3->setText("Rotate");
		}
		else if (misi3 == 6)
		{
			ui->lineEditStatusMisi3->setText("Find the Second Dock");
		}
		else if (misi3 == 7)
		{
			ui->lineEditStatusMisi3->setText("Rotate");
		}
		else if (misi3 == 8)
		{
			ui->lineEditStatusMisi3->setText("Docking 2...");
		}
		else if (misi3 == 9)
		{
			ui->lineEditStatusMisi3->setText("Mundur");
		}
		else if (misi3 == 10)
		{
			ui->lineEditStatusMisi3->setText("Go to Next Waypoint");
		}
		else if (misi3 == 4)
		{
			ui->lineEditStatusMisi3->setText("Mundur");
		}
	}
	else if (tampil_misi == 4)
	{
		ui->lineEditMissionStatus->setText("Misi 4 Find the Path");
	}
	else if (tampil_misi == 5)
	{
		ui->lineEditMissionStatus->setText("Misi 5 Follow the Leader");
	}
	else if (tampil_misi == 6)
	{
		ui->lineEditMissionStatus->setText("Misi 6 Slalom");
	}
	else if (tampil_misi == 7)
	{
		ui->lineEditMissionStatus->setText("Return to Home");
	}
	else
	{
		ui->lineEditMissionStatus->setText("Navigation");
	}
}


QApplication app();
QPainter p;


void MainWindow::ambil_olah_kontrol(int serv1, int serv2, int mot1, int mot2, float sudut, float eror, float distance, int mot3) {
	ui->lineEditServoKiri->setText(QString::number(serv1));
	ui->lineEditServoKanan->setText(QString::number(serv2));
	ui->lineEditSudutTujuan->setText(QString::number(sudut));
	ui->lineEditErrorSudut->setText(QString::number(eror));
	ui->lineEditJarak->setText(QString::number(distance));
	ui->lineEditMotorKiri->setText(QString::number(mot1));
	ui->lineEditMotorKanan->setText(QString::number(mot2));
	ui->lineEditMotorTengah->setText(QString::number(mot3));
	ui->lcdNumberCounterMisi3->display(kontrol->counter_misi3);
	ui->lcdNumberPenandaMisi3->display(kontrol->penanda_misi3);
	ui->lineEditDock->setText(QString::number(kontrol->first_dock));

	jarak = distance;
}

void MainWindow::ubah_posisi_camera(int camera)
{
	serialConnection->Servo_Camera = camera;
}
void MainWindow::ubah_posisi_camera2(int camera2)
{
	serialConnection->Servo_Camera2 = camera2;
}
void MainWindow::ubah_posisi_camera_misi(int cam1, int cam2)
{
	ui->spinBoxServoCamera->setValue(cam1);
	ui->spinBoxServoCamera2->setValue(cam2);
}

void MainWindow::set_frame()
{
	titik_awal_lat = ui->lineEditLatAwal->text().toInt();
	titik_akhir_lat = ui->lineEditLatAkhir->text().toInt();
	titik_awal_long = ui->lineEditLongAwal->text().toInt();
	titik_akhir_long = ui->lineEditLongAkhir->text().toInt();

	skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
	skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia

}

void MainWindow::set_frame_2()
{
	switch (ui->comboBoxSetFrame->currentIndex())
	{
	case 0 : // Danau 8
		titik_awal_lat =	  72862585;
		titik_akhir_lat =	  72872555;
		titik_awal_long =	1127957235;
		titik_akhir_long =	1127964815;

		skala_latitude = (float)800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 1: // Danau Trial Daytona
		titik_awal_lat = 292138619;
		titik_akhir_lat = 292128619;
		titik_awal_long = 810195346;
		titik_akhir_long = 810185346;

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 2: // Robotika
		titik_awal_lat = ui->lineEditLatAwal->text().toInt();
		titik_akhir_lat = ui->lineEditLatAkhir->text().toInt();
		titik_awal_long = ui->lineEditLongAwal->text().toInt();
		titik_akhir_long = ui->lineEditLongAkhir->text().toInt();

		skala_latitude = (float)800 / (titik_akhir_lat - titik_awal_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)600 / (titik_akhir_long - titik_awal_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 3: // Reed Canal Park
		titik_awal_lat = 291520905;
		titik_akhir_lat = 291502665;
		titik_awal_long = 810173445;
		titik_akhir_long = 810157455;

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 4: // Course A

		titik_awal_lat =	291518596;
		titik_akhir_lat =	291508596;
		titik_awal_long =	810179959;
		titik_akhir_long =	810169959;

		/*titik_awal_lat = ui->lineEditLatAwal->text().toInt();
		titik_akhir_lat = ui->lineEditLatAkhir->text().toInt();
		titik_awal_long = ui->lineEditLongAwal->text().toInt();
		titik_akhir_long = ui->lineEditLongAkhir->text().toInt();*/

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 5: // Course B
		titik_awal_lat = 291524282;
		titik_akhir_lat = 291514282;
		titik_awal_long = 810168216;
		titik_akhir_long = 810158216;

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 6: // Course C
		titik_awal_lat = 291520563;
		titik_akhir_lat = 291510563;
		titik_awal_long = 810166507;
		titik_akhir_long = 810156507;

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 7: // Course D
		titik_awal_lat = ui->lineEditLatAwal->text().toInt();
		titik_akhir_lat = ui->lineEditLatAkhir->text().toInt();
		titik_awal_long = ui->lineEditLongAwal->text().toInt();
		titik_akhir_long = ui->lineEditLongAkhir->text().toInt();

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 8: // Final Course
		titik_awal_lat = ui->lineEditLatAwal->text().toInt();
		titik_akhir_lat = ui->lineEditLatAkhir->text().toInt();
		titik_awal_long = ui->lineEditLongAwal->text().toInt();
		titik_akhir_long = ui->lineEditLongAkhir->text().toInt();
		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	case 9: // Rumah Pak Henry
		titik_awal_lat = 292224033;
		titik_akhir_lat = 292212033;
		titik_awal_long = 810270253;
		titik_akhir_long = 810261253; 

		skala_latitude = (float)(-1) * 800 / (titik_awal_lat - titik_akhir_lat); // ngga pake minus 1 kalo di indonesia
		skala_longitude = (float)(-1) * 600 / (titik_awal_long - titik_akhir_long); // ngga pake minus 1 kalo di indonesia
		break;
	}
}

void MainWindow::paintEvent()
{
	// Original image
	QPixmap rocket("C:/Users/BARUNASTRA-ITS/Desktop/AUVSI2018/KapalIllustration-01.png");

	// Original rotated once to 30 degrees
	QPixmap gambar(rocket.size());
	gambar.fill(Qt::transparent);
	p.begin(&gambar);
	p.translate(rocket.width() / 2, rocket.height() / 2);
	p.rotate(compass_sekarang);
	p.translate(-rocket.width() / 2, -rocket.height() / 2);
	p.drawPixmap(0, 0, rocket);
	p.end();

	ui->labelArahKapal->setPixmap(gambar);

	if (lattitudeWaypoint[index_plot_waypoint] != NULLPOINT && longitudeWaypoint[index_plot_waypoint] != NULLPOINT) {
		posisi_kapal_sekarang.setY((abs(latitude_sekarang) * 10000000 - titik_awal_lat) * skala_latitude);
		posisi_kapal_sekarang.setX((abs(longitude_sekarang) * 10000000 - titik_awal_long) * skala_longitude);

		posisi_tujuan_kapal.setY((abs(lattitudeWaypoint[index_plot_waypoint]) * 10000000 - titik_awal_lat) * skala_latitude);
		posisi_tujuan_kapal.setX((abs(longitudeWaypoint[index_plot_waypoint]) * 10000000 - titik_awal_long) * skala_longitude);

		QPixmap pixmapWaypoint(600, 800);
		QPainter painterWaypoint(&pixmapWaypoint);
		pixmapWaypoint.fill(QColor(51, 51, 255, 255));
		painterWaypoint.setPen(Qt::black);
		// gambar grid
		for (int loops = 20; loops < 800; loops = loops + 20)
		{
			painterWaypoint.drawLine(0, loops, 600, loops);
		}
		for (int loops = 20; loops < 600; loops = loops + 20)
		{
			painterWaypoint.drawLine(loops, 0, loops, 800);
		}

		QFont font = painterWaypoint.font();
		font.setPixelSize(16);
		painterWaypoint.setFont(font);

		painterWaypoint.setPen(waypen_garis);
		painterWaypoint.drawLine(posisi_kapal_sekarang, posisi_tujuan_kapal);

		painterWaypoint.setPen(waypen_now);
		painterWaypoint.setBrush((Qt::red));
		painterWaypoint.drawEllipse(posisi_kapal_sekarang, 6, 6);



		//painterWaypoint.setPen(waypen_now);
		painterWaypoint.setBrush((Qt::green));
		painterWaypoint.drawEllipse(posisi_tujuan_kapal, 5, 5);
		painterWaypoint.drawText(posisi_tujuan_kapal, QString::number(index_plot_waypoint));



		for (int loop = 1; loop <= max_waypoint; loop++)
		{
			posisi_waypoint.setY((abs(lattitudeWaypoint[index_plot_waypoint + loop]) * 10000000 - titik_awal_lat) * skala_latitude);
			posisi_waypoint.setX((abs(longitudeWaypoint[index_plot_waypoint + loop]) * 10000000 - titik_awal_long) * skala_longitude);

			painterWaypoint.drawEllipse(posisi_waypoint, 5, 5);
			painterWaypoint.drawText(posisi_waypoint, QString::number(loop + index_plot_waypoint));
		}
		ui->labelMapping->setPixmap(pixmapWaypoint);
	}
	else {
		posisi_kapal_sekarang.setY((abs(latitude_sekarang) * 10000000 - titik_awal_lat) * skala_latitude);
		posisi_kapal_sekarang.setX((abs(longitude_sekarang) * 10000000 - titik_awal_long) * skala_longitude);
		QPixmap pixmapWaypoint(600, 800);
		QPainter painterWaypoint(&pixmapWaypoint);
		pixmapWaypoint.fill(QColor(51, 51, 255, 255));
		painterWaypoint.setPen(waypen_now);
		painterWaypoint.setBrush((Qt::red));
		painterWaypoint.drawEllipse(posisi_kapal_sekarang, 6, 6);
		ui->labelMapping->setPixmap(pixmapWaypoint);
	}
}

void MainWindow::imageDrone(QImage img) {
	qDebug() << "image resolution : " << img.width() << "x" << img.height() << endl;
	ui->imgDrone->setPixmap(QPixmap::fromImage(img));
	QByteArray byteArray;
	QBuffer buffer(&byteArray);
	img.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer
	QString iconBase64 = QString::fromLatin1(byteArray.toBase64().data());
	qDebug() << iconBase64;
	emit imageDroneRecieved();
}


void MainWindow::on_save_waypoint() {
	QString fName;
	if (fName.isEmpty()) {
		fName = QFileDialog::getSaveFileName(this,
			tr("Save waypoint"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	}
	if (fName.isEmpty()) {
		return;
	}
	else {
		QFile file(fName);
		// cek apa file kebacasss
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa membuka file"), file.errorString());
			return;
		}
		QTextStream out(&file);
		QString buff = "", delim = ",";
		for (int i = 1; i <= max_waypoint; i++) {
			buff += QString::number(longitudeWaypoint[i], 'g,', 10);
			buff += delim;
			buff += QString::number(lattitudeWaypoint[i], 'g,', 10);
			buff += "\n";
		}
		qDebug() << "Data waypoint yg disimpan\n" << buff;
		out << buff;
		file.close();
	}
}

void MainWindow::on_load_waypoint() {
	qDebug() << "Mauk load waypoint\n";
	QString fName;
	QString buffer;
	fName = QFileDialog::getOpenFileName(this,
		tr("Load Waypoint"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	if (fName.isEmpty()) {
		//qDebug() << "kok empty??";
		return;
	}
	else {
		QFile file(fName);
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::warning(this, tr("Tidak bisa memuat file."), file.errorString());
			return;
		}

		QTextStream in(&file);
		QTableWidgetItem *latt, *longi;
		int i = 1;
		qDebug() << "Masuk load waypoint";
		QStringList  allReaded = in.readAll().split("\n");
		qDebug() << allReaded.length() << allReaded.size();
		for (int j = 0; j < allReaded.length() - 1; j++) {
			qDebug() << index_waypoint << index_plot_waypoint;
			buffer = allReaded.at(j);
			qDebug() << "Buffer: " << buffer;
			QStringList wordList = buffer.split(",");
			//qDebug() << wordList;
			longitudeWaypoint[i] = wordList[0].toFloat();
			lattitudeWaypoint[i] = wordList[1].toFloat();
			//qDebug() << ui->tableWidgetWaypoint->currentIndex();
			qDebug() << longitudeWaypoint[i] << lattitudeWaypoint[i];
			latt = new QTableWidgetItem(QString::number(lattitudeWaypoint[i], 'g', 10));
			longi = new QTableWidgetItem(QString::number(longitudeWaypoint[i], 'g', 10));
			qDebug() << "sebelum insert: " << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(i - 1, 0)).toString() << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(i - 1, 1)).toString();
			ui->tableWidgetWaypoint->setItem(i - 1, 0, latt);
			ui->tableWidgetWaypoint->setItem(i - 1, 1, longi);
			qDebug() << "sesudah insert: " << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(i - 1, 0)).toString() << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(i - 1, 1)).toString();
			if (latt == NULL) {
				qDebug() << "Lat Nulll????";
			}
			if (longi == NULL) {
				qDebug() << "long Null????";
			}
			qDebug() << "Table widget updated";

			emit kontrol_waypoint(lattitudeWaypoint[i], longitudeWaypoint[i], i);
			emit send_index_plot_waypoint(i);
			//index_waypoint = i+1;
			index_plot_waypoint = i + 1;
			kontrol->tujuanWaypoint(lattitudeWaypoint[i], longitudeWaypoint[i], i);
			ui->spinBoxWaypoint->setValue(i + 1);
			i += 1;
			qDebug() << index_waypoint << index_plot_waypoint;
		}
		qDebug() << "Di Akhir: " << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(allReaded.length() - 1 - 1, 0)).toString() << ui->tableWidgetWaypoint->model()->data(ui->tableWidgetWaypoint->model()->index(allReaded.length() - 1 - 1, 1)).toString();
		for (int i = 1; i <= allReaded.length() - 1; i++) {
			qDebug() << longitudeWaypoint[i] << lattitudeWaypoint[i];
		}
	}
}

void MainWindow::on_save_new() {
	if (fileName.isEmpty()) {
		fileName = QFileDialog::getSaveFileName(this,
			tr("Save"), "", tr("JSON (*.json)"));
	}
	if (fileName.isEmpty()) {
		return;
	}
	else {
		QFile file(fileName);
		// cek apa file kebacasss
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa membuka file"), file.errorString());
			return;
		}
		// main Json object
		QJsonObject obj;
		// json object for each mission
		auto mission1 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi1->value())),
			qMakePair(QString("Sudut"), QJsonValue(ui->spinBoxSudutMisi1->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi1->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi1->value()))
		});
		auto mission2 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi2->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi2->value())),
			qMakePair(QString("SpeedTengah"), QJsonValue(ui->spinBoxSpeedTengahMisi2->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi2->value()))
		});
		auto mission3 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi3->value())),
			qMakePair(QString("Waypoint2"), QJsonValue(ui->spinBoxWaypointMisi3_2->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi3->value())),
			qMakePair(QString("SpeedAtas"), QJsonValue(ui->spinBoxSpeedMisi3Atas->value())),
			qMakePair(QString("Setpoint"), QJsonValue(ui->spinBoxSetpointMisi3->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi3->value())),
			qMakePair(QString("Frequency"), QJsonValue(ui->spinBoxThresholdFrequency->value())),
			qMakePair(QString("Sudut"), QJsonValue(ui->spinBoxSudutMisi3->value())),
			qMakePair(QString("ThresholdPinger"), QJsonValue(ui->spinBoxThresholdPinger->value())),
			qMakePair(QString("MaxPinger"), QJsonValue(ui->spinBoxMaxPinger->value())),
			qMakePair(QString("TimeOut"), QJsonValue(ui->spinBoxTimeOutMisi3->value()))

		});
		auto mission4 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi4->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi4->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi4->value()))
		});
		auto mission5 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi5->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi5->value())),
			qMakePair(QString("SpeedBawah"), QJsonValue(ui->spinBoxSpeedMisi5Bawah->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi5->value())),
			qMakePair(QString("BatasY"), QJsonValue(ui->spinBoxBatasY->value())),
			qMakePair(QString("TimeOut"), QJsonValue(ui->spinBoxTimeOutMisi5->value())),
			qMakePair(QString("Setpoint"), QJsonValue(ui->spinBoxSetpointMisi5->value()))
		});
		auto mission6 = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointMisi6->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedMisi6->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopMisi6->value())),
		});
		auto mReturn = QJsonObject({
			qMakePair(QString("Waypoint"), QJsonValue(ui->spinBoxWaypointReturn->value())),
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedReturn->value())),
			qMakePair(QString("Stop"), QJsonValue(ui->spinBoxStopReturn->value()))
			//qMakePair(QString("Option"), QJsonValue(ui->comboBoxReturn->currentIndex()))
		});
		auto nav = QJsonObject({
			qMakePair(QString("Speed"), QJsonValue(ui->spinBoxSpeedNav->value())),
			qMakePair(QString("Servo Camera"), QJsonValue(ui->spinBoxServoCamera->value())),
			qMakePair(QString("Servo Camera 2"), QJsonValue(ui->spinBoxServoCamera2->value())),
			qMakePair(QString("Trim Motor"), QJsonValue(ui->spinBoxTrimMotor->value())),
			qMakePair(QString("Trim Servo Kiri"), QJsonValue(ui->spinBoxTrimServoKiri->value())),
			qMakePair(QString("Trim Servo Kanan"), QJsonValue(ui->spinBoxTrimServoKanan->value())),
			qMakePair(QString("Offset Compass"), QJsonValue(ui->spinBoxOffset->value()))
		});

		auto pid = QJsonObject({
			qMakePair(QString("P"), QJsonValue(ui->spinBoxP1->value())),
			qMakePair(QString("I"), QJsonValue(ui->spinBoxI1->value())),
			qMakePair(QString("D"), QJsonValue(ui->spinBoxD1->value()))
		});

		auto pid2 = QJsonObject({
			qMakePair(QString("P"), QJsonValue(ui->spinBoxP2->value())),
			qMakePair(QString("I"), QJsonValue(ui->spinBoxI2->value())),
			qMakePair(QString("D"), QJsonValue(ui->spinBoxD2->value()))
		});

		auto pid3 = QJsonObject({
			qMakePair(QString("P"), QJsonValue(ui->spinBoxP3->value())),
			qMakePair(QString("I"), QJsonValue(ui->spinBoxI3->value())),
			qMakePair(QString("D"), QJsonValue(ui->spinBoxD3->value()))
		});

		QString imageId = "Image ";
		for (int i = 0; i < 7; i++) {
			QJsonObject imageObj;
			imageObj.insert(QString("H Min") + QString::number(i), QJsonValue(hMin[i]));
			imageObj.insert(QString("S Min") + QString::number(i), QJsonValue(sMin[i]));
			imageObj.insert(QString("V Min") + QString::number(i), QJsonValue(vMin[i]));
			imageObj.insert(QString("H Max") + QString::number(i), QJsonValue(hMax[i]));
			imageObj.insert(QString("S Max") + QString::number(i), QJsonValue(sMax[i]));
			imageObj.insert(QString("V Max") + QString::number(i), QJsonValue(vMax[i]));
			imageObj.insert(QString("Erode") + QString::number(i), QJsonValue(erode[i]));
			imageObj.insert(QString("Dilate") + QString::number(i), QJsonValue(dilate[i]));
			obj.insert(imageId + QString::number(i), QJsonValue(imageObj));
		}
		obj.insert(QString("Mission 1"), QJsonValue(mission1));
		obj.insert(QString("Mission 2"), QJsonValue(mission2));
		obj.insert(QString("Mission 3"), QJsonValue(mission3));
		obj.insert(QString("Mission 4"), QJsonValue(mission4));
		obj.insert(QString("Mission 5"), QJsonValue(mission5));
		obj.insert(QString("Mission 6"), QJsonValue(mission6));
		obj.insert(QString("Return"), QJsonValue(mReturn));
		obj.insert(QString("Nav"), QJsonValue(nav));
		obj.insert(QString("PID 1"), QJsonValue(pid));
		obj.insert(QString("PID 2"), QJsonValue(pid2));
		obj.insert(QString("PID 3"), QJsonValue(pid3));
		//obj.insert(QString("Speed"), QJsonValue(ui->speedSlider->value()));
		QJsonDocument doc;
		doc.setObject(obj);
		file.write(doc.toJson());

	}


}

void MainWindow::on_load_new() {
	QString buffer;
	fileName = QFileDialog::getOpenFileName(this,
		tr("Load"), "", tr("JSON (*.json)"));
	if (fileName.isEmpty()) {
		//qDebug() << "kok empty??";
		return;
	}
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa memuat file."), file.errorString());
			return;
		}
		loadStatus = true;
		QString in;
		in = file.readAll();
		file.close();
		QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());
		QJsonObject obj = doc.object();
		//qWarning() << obj;
		QString imgStr = "Image ", sHmin = "H Min", sHmax = "H Max", sSmin = "S Min", sSmax = "S Max", sVmin = "V Min", sVmax = "V Max";
		QString sErode = "Erode", sDilate = "Dilate";
		qWarning() << obj["Mission 1"].toObject()["Speed"].toDouble();

		// load mission setting
		ui->spinBoxSpeedMisi1->setValue(obj["Mission 1"].toObject()["Speed"].toInt());
		ui->spinBoxWaypointMisi1->setValue(obj["Mission 1"].toObject()["Waypoint"].toInt());
		ui->spinBoxSudutMisi1->setValue(obj["Mission 1"].toObject()["Sudut"].toInt());
		ui->spinBoxStopMisi1->setValue(obj["Mission 1"].toObject()["Stop"].toInt());

		ui->spinBoxSpeedMisi2->setValue(obj["Mission 2"].toObject()["Speed"].toInt());
		ui->spinBoxSpeedTengahMisi2->setValue(obj["Mission 2"].toObject()["SpeedTengah"].toInt());
		ui->spinBoxWaypointMisi2->setValue(obj["Mission 2"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopMisi2->setValue(obj["Mission 2"].toObject()["Stop"].toInt());

		ui->spinBoxSpeedMisi3->setValue(obj["Mission 3"].toObject()["Speed"].toInt());
		ui->spinBoxWaypointMisi3->setValue(obj["Mission 3"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopMisi3->setValue(obj["Mission 3"].toObject()["Stop"].toInt());
		ui->spinBoxWaypointMisi3_2->setValue(obj["Mission 3"].toObject()["Waypoint2"].toInt());
		ui->spinBoxSetpointMisi3->setValue(obj["Mission 3"].toObject()["Setpoint"].toInt());
		ui->spinBoxSpeedMisi3Atas->setValue(obj["Mission 3"].toObject()["SpeedAtas"].toInt());
		ui->spinBoxThresholdPinger->setValue(obj["Mission 3"].toObject()["ThresholdPinger"].toInt());
		ui->spinBoxSudutMisi3->setValue(obj["Mission 3"].toObject()["Sudut"].toInt());
		ui->spinBoxThresholdFrequency->setValue(obj["Mission 3"].toObject()["Frequency"].toInt());
		ui->spinBoxMaxPinger->setValue(obj["Mission 3"].toObject()["MaxPinger"].toInt());
		ui->spinBoxTimeOutMisi3->setValue(obj["Mission 3"].toObject()["TimeOut"].toInt());

		ui->spinBoxSpeedMisi4->setValue(obj["Mission 4"].toObject()["Speed"].toInt());
		ui->spinBoxWaypointMisi4->setValue(obj["Mission 4"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopMisi4->setValue(obj["Mission 4"].toObject()["Stop"].toInt());

		ui->spinBoxSpeedMisi5->setValue(obj["Mission 5"].toObject()["Speed"].toInt());
		ui->spinBoxSpeedMisi5Bawah->setValue(obj["Mission 5"].toObject()["SpeedBawah"].toInt());
		ui->spinBoxWaypointMisi5->setValue(obj["Mission 5"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopMisi5->setValue(obj["Mission 5"].toObject()["Stop"].toInt());
		ui->spinBoxBatasY->setValue(obj["Mission 5"].toObject()["BatasY"].toInt());
		ui->spinBoxSetpointMisi5->setValue(obj["Mission 5"].toObject()["Setpoint"].toInt());
		ui->spinBoxTimeOutMisi5->setValue(obj["Mission 5"].toObject()["TimeOut"].toInt());

		ui->spinBoxSpeedMisi6->setValue(obj["Mission 6"].toObject()["Speed"].toInt());
		ui->spinBoxWaypointMisi6->setValue(obj["Mission 6"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopMisi6->setValue(obj["Mission 6"].toObject()["Stop"].toInt());

		ui->spinBoxSpeedReturn->setValue(obj["Return"].toObject()["Speed"].toInt());
		ui->spinBoxWaypointReturn->setValue(obj["Return"].toObject()["Waypoint"].toInt());
		ui->spinBoxStopReturn->setValue(obj["Return"].toObject()["Stop"].toInt());
		//ui->comboBoxReturn->setCurrentIndex(obj["Return"].toObject()["Option"].toInt());

		ui->spinBoxSpeedNav->setValue(obj["Nav"].toObject()["Speed"].toInt());
		ui->spinBoxServoCamera->setValue(obj["Nav"].toObject()["Servo Camera"].toInt());
		ui->spinBoxServoCamera2->setValue(obj["Nav"].toObject()["Servo Camera 2"].toInt());
		ui->spinBoxTrimMotor->setValue(obj["Nav"].toObject()["Trim Motor"].toInt());
		ui->spinBoxTrimServoKiri->setValue(obj["Nav"].toObject()["Trim Servo Kiri"].toInt());
		ui->spinBoxTrimServoKanan->setValue(obj["Nav"].toObject()["Trim Servo Kanan"].toInt());
		ui->spinBoxOffset->setValue(obj["Nav"].toObject()["Offset Compass"].toInt());

		ui->spinBoxP1->setValue(obj["PID 1"].toObject()["P"].toInt());
		ui->spinBoxI1->setValue(obj["PID 1"].toObject()["I"].toInt());
		ui->spinBoxD1->setValue(obj["PID 1"].toObject()["D"].toInt());

		ui->spinBoxP2->setValue(obj["PID 2"].toObject()["P"].toInt());
		ui->spinBoxI2->setValue(obj["PID 2"].toObject()["I"].toInt());
		ui->spinBoxD2->setValue(obj["PID 2"].toObject()["D"].toInt());

		ui->spinBoxP3->setValue(obj["PID 3"].toObject()["P"].toInt());
		ui->spinBoxI3->setValue(obj["PID 3"].toObject()["I"].toInt());
		ui->spinBoxD3->setValue(obj["PID 3"].toObject()["D"].toInt());

		for (int i = 0; i < 7; i++) {
			hMin[i] = obj[imgStr + QString::number(i)].toObject()[sHmin + QString::number(i)].toInt();
			sMin[i] = obj[imgStr + QString::number(i)].toObject()[sSmin + QString::number(i)].toInt();
			vMin[i] = obj[imgStr + QString::number(i)].toObject()[sVmin + QString::number(i)].toInt();
			hMax[i] = obj[imgStr + QString::number(i)].toObject()[sHmax + QString::number(i)].toInt();
			sMax[i] = obj[imgStr + QString::number(i)].toObject()[sSmax + QString::number(i)].toInt();
			vMax[i] = obj[imgStr + QString::number(i)].toObject()[sVmax + QString::number(i)].toInt();
			erode[i] = obj[imgStr + QString::number(i)].toObject()[sErode + QString::number(i)].toInt();
			dilate[i] = obj[imgStr + QString::number(i)].toObject()[sDilate + QString::number(i)].toInt();
			qDebug() << hMin[i] << sMin[i] << vMin[i] << hMax[i] << sMax[i] << vMax[i] << erode[i] << dilate[i];
		}
		emit updateHSV();

		//emit updateHSV();
		loadStatus = false;
	}
}

void MainWindow::on_save_as_new() {
	fileName = QFileDialog::getSaveFileName(this,
		tr("Save"), "", tr("JSON (*.json)"));
	if (fileName == NULL)
		return;
	on_save_new();
}

void MainWindow::startNet() {
	QString baseUrl;
	if (ui->serverUrl->text() != "") {
		baseUrl = ui->serverUrl->text();
	}
	if (ui->serverIP->text() != "" && ui->serverPort->text() != "") {
		baseUrl = ui->serverIP->text() + ":" + ui->serverPort->text();
	}
	net->setBaseURL(baseUrl);
	net->setCourse(ui->course->text());
	if (!netThread->isRunning())netThread->start();
	ui->btnStartConnServer->setEnabled(false);
	ui->btnStopConnServer->setEnabled(true);
}

void MainWindow::stopNet() {
	netThread->wait(100);
	if (netThread->isRunning())netThread->quit();
	ui->btnStartConnServer->setEnabled(true);
	ui->btnStopConnServer->setEnabled(false);
}

void MainWindow::takePictOnWaypoint(int status) {
	if (status == 1) {
		connectDrone();
	}
}