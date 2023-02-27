#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include <QTime>
#include <QTimer>
#include "mainwindow.h"

#define DEFAULT_BAUD_RATE QSerialPort::Baud38400
#define DEFAULT_PORT_NAME "COM8"

class SerialConnection : public QObject
{
	Q_OBJECT

public:
	explicit SerialConnection(QObject *parent = 0);
	~SerialConnection();

	QSerialPort *serportGPS;
	QSerialPort *serportSRF;
	QSerialPort *serportHydro;
	QSerialPort *serportDrone;
	QSerialPort *serportCompass;

	QTimer *timer_kirim_drone = new QTimer(this);

	void receiveGPS();

	float compassOlah;

	double lattDouble = 0.00000000000;
	double longDouble = 0.00000000000;
	int SRF1 = 0;
	int SRF2 = 0;
	int SRF3 = 0;
	int SRF4 = 0;
	int SRF5 = 0;

	int status_drone = 0;
	int status_ambil_gambar = 0;
	int status_mendarat = 0;
	int prev_status_ambil_gambar = 0;

	float sudutTujuan;
	float errorSudut;

#define PI 3.141532653589793

	char ambil_GPS[40];
	char lat_kirim[30];
	char long_kirim[30];
	char comp_kirim[10];
	char srf1_kirim[4];
	char srf2_kirim[4];
	char srf3_kirim[4];
	char srf4_kirim[4];
	char srf5_kirim[4];

	char compass1_kirim[2];
	char compass2_kirim[8];
	char compass3_kirim[2];
	char hydro1_kirim[6];
	char hydro2_kirim[4];
	char drone1_kirim[3];
	char drone2_kirim[3];
	char kirim[50];
	char kirim_drone[5];

	int MotorKiri = 1600;
	int MotorKanan = 1600;
	int MotorTengah = 1500;
	int ServoKiri = 1600;
	int ServoKanan = 1600;

	int Servo_Camera = 1450;
	int Servo_Camera2 = 1500;

	QByteArray data;
	QByteArray dataSRF;
	QString serialBuffer;

	float stof(const char* s);

signals:
	void serial_kirim_data_SRF(int, int, int, int, int);
	void serial_kirim_data_GPS(double, double,float);
	void serial_kirim_data_Hydro(int, int);
	void serial_kirim_data_Drone(int, int);
	void drone_status_changed(int);

protected:

private:


public slots :
	void initSerPortGPS();
	void initSerPortSRF();
	void initSerPortHydro();
	void initSerPortDrone();
	void initSerPortCompass();
	void readGPS();
	void readSRF();
	void readHydro();
	void readDrone();
	void readCompass();
	void sendDatatoSTM();
	void sendDatatoDrone();
	void close();
	void terima_kontrol(int, int, int, int, int);
	void ubah_status_drone(int);
	void retry_serialConnection();
	void terima_offset_serial(int);
};

#endif // !SERIALCONNECTION_H