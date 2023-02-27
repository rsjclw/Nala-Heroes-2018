#include "serialconnection.h"
#include <qdebug.h>
#include <qmutex.h>


SerialConnection::SerialConnection(QObject *parent)
	: QObject(parent) {

	serportGPS = nullptr;
	serportSRF = nullptr;
	serportHydro = nullptr;
	serportDrone = nullptr;
	serportCompass = nullptr;
}


SerialConnection::~SerialConnection()
{
	if (serportGPS != nullptr && serportGPS->isOpen()) {
		serportGPS->close();
	}
	if (serportSRF != nullptr && serportSRF->isOpen()) {
		serportSRF->close();
	}
	if (serportHydro != nullptr && serportHydro->isOpen()) {
		serportHydro->close();
	}
	if (serportDrone != nullptr && serportDrone->isOpen()) {
		serportDrone->close();
	}
	if (serportCompass != nullptr && serportCompass->isOpen()) {
		serportCompass->close();
	}
	delete serportGPS;
	delete serportSRF;
	delete serportHydro;
	delete serportDrone;
	delete serportCompass;
}

int serial_offset = 0;

void SerialConnection::terima_offset_serial(int offt)
{
	serial_offset = offt;
	qDebug() << "offset masuk" << serial_offset << endl;
}

void SerialConnection::retry_serialConnection()
{
	status_drone = 0;
	status_ambil_gambar = 0;
	status_mendarat = 0;
}

void SerialConnection::close()
{
	if (serportGPS->isOpen()) {
		serportGPS->close();
	}
	delete serportGPS;
}

void SerialConnection::initSerPortGPS()
{
	serportGPS = new QSerialPort();
	serportGPS->setPortName("COM8");
	serportGPS->setParity(QSerialPort::NoParity);
	serportGPS->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
	serportGPS->setStopBits(QSerialPort::OneStop);
	serportGPS->setFlowControl(QSerialPort::NoFlowControl);

	if (serportGPS->open(QIODevice::ReadWrite))
	{
		qDebug() << "open";
	}
	else
	{
		qDebug() << "error";
	}

	connect(serportGPS, SIGNAL(readyRead()), this, SLOT(sendDatatoSTM()));
	connect(serportGPS, SIGNAL(readyRead()), this, SLOT(readGPS()));
}

void SerialConnection::initSerPortSRF()
{
	serportSRF = new QSerialPort();
	serportSRF->setPortName("COM9");
	serportSRF->setParity(QSerialPort::NoParity);
	serportSRF->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
	serportSRF->setStopBits(QSerialPort::OneStop);
	serportSRF->setFlowControl(QSerialPort::NoFlowControl);

	if (serportSRF->open(QIODevice::ReadWrite))
	{
		qDebug() << "open";
	}
	else
	{
		qDebug() << "error";
	}
	connect(serportSRF, SIGNAL(readyRead()), this, SLOT(readSRF()));
}

void SerialConnection::initSerPortHydro()
{
	serportHydro = new QSerialPort();
	serportHydro->setPortName("COM15");
	serportHydro->setParity(QSerialPort::NoParity);
	serportHydro->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
	serportHydro->setStopBits(QSerialPort::OneStop);
	serportHydro->setFlowControl(QSerialPort::NoFlowControl);

	if (serportHydro->open(QIODevice::ReadWrite))
	{
		qDebug() << "open";
	}
	else
	{
		qDebug() << "error";
	}
	connect(serportHydro, SIGNAL(readyRead()), this, SLOT(readHydro()));
}

void SerialConnection::initSerPortDrone()
{
	connect(timer_kirim_drone, SIGNAL(timeout()), this, SLOT(sendDatatoDrone()));
	timer_kirim_drone->start(100);

	serportDrone = new QSerialPort();
	serportDrone->setPortName("COM5");
	serportDrone->setParity(QSerialPort::NoParity);
	serportDrone->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
	serportDrone->setStopBits(QSerialPort::OneStop);
	serportDrone->setFlowControl(QSerialPort::NoFlowControl);

	if (serportDrone->open(QIODevice::ReadWrite))
	{
		qDebug() << "open";
	}
	else
	{
		qDebug() << "error";
	}
	connect(serportDrone, SIGNAL(readyRead()), this, SLOT(readDrone()));
}

void SerialConnection::initSerPortCompass()
{
	serportCompass = new QSerialPort();
	serportCompass->setPortName("COM3");
	serportCompass->setParity(QSerialPort::NoParity);
	serportCompass->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
	serportCompass->setStopBits(QSerialPort::OneStop);
	serportCompass->setFlowControl(QSerialPort::NoFlowControl);

	if (serportCompass->open(QIODevice::ReadWrite))
	{
		qDebug() << "open";
	}
	else
	{
		qDebug() << "error";
	}
	connect(serportCompass, SIGNAL(readyRead()), this, SLOT(readCompass()));
}

void SerialConnection::readCompass()
{
	static int i = 0;

	static int penanda = 0;

	QByteArray dataCompass = serportCompass->readAll();

	for (int ii = 0; ii < dataCompass.length(); ii++)
	{

		if (dataCompass.at(ii) == 'A')
		{
			penanda = 0;
		}
		else if (dataCompass.at(ii) == 'B')
		{
			penanda = 1;
		}
		else if (dataCompass.at(ii) == 'C')
		{
			penanda = 2;
		}

		switch (penanda)
		{
		case 0:
			compass1_kirim[0] = dataCompass.at(ii);
			break;
		case 1:
			if (dataCompass.at(ii) == 'B')
			{
				i = 0;
			}
			else if (dataCompass.at(ii) != 'B')
			{
				compass2_kirim[i++] = dataCompass.at(ii);
			}

			break;
		case 2:
			compass3_kirim[0] = dataCompass.at(ii);
			break;
		}
	}
	compassOlah = atof(compass2_kirim);
	compassOlah = compassOlah + (float)serial_offset;
}

void SerialConnection::readDrone()
{
	static int i = 0;
	static int j = 0;

	static int penanda = 0;

	QByteArray dataDrone = serportDrone->readAll();

	for (int ii = 0; ii<dataDrone.length(); ii++)
	{
		if (dataDrone.at(ii) == 'A')
		{
			penanda = 0;
		}
		else if (dataDrone.at(ii) == 'B')
		{
			penanda = 1;
		}


		switch (penanda)
		{
		case 0:
			if (dataDrone.at(ii) != 'A' && penanda == 0)
			{
				drone1_kirim[i++] = dataDrone.at(ii);
			}
			else
			{
				i = 0;
			}
			break;
		case 1:
			if (dataDrone.at(ii) != 'B' && penanda == 1)
			{
				drone2_kirim[j++] = dataDrone.at(ii);
			}
			else
			{
				j = 0;
			}
			break;
		}

	}

	status_ambil_gambar = atoi(drone1_kirim);
	status_mendarat = atoi(drone2_kirim);
	if (status_ambil_gambar == 1 && prev_status_ambil_gambar == 0) {
		emit drone_status_changed(status_ambil_gambar);
		qDebug() << "triger ambil gambar";
	}
	emit serial_kirim_data_Drone(status_ambil_gambar, status_mendarat);
	prev_status_ambil_gambar = status_ambil_gambar;
}


int frequency = 0;
int amplitude = 0;


void SerialConnection::readHydro()
{
	static int i = 0;
	static int j = 0;

	static int penanda = 0;

	QByteArray dataHydro = serportHydro->readAll();

	for (int ii = 0; ii<dataHydro.length(); ii++)
	{
		if (dataHydro.at(ii) == 'A')
		{
			penanda = 0;
		}
		else if (dataHydro.at(ii) == 'B')
		{
			penanda = 1;
		}


		switch (penanda)
		{
		case 0:
			if (dataHydro.at(ii) != 'A' && penanda == 0)
			{
				hydro1_kirim[i++] = dataHydro.at(ii);
			}
			else
			{
				i = 0;
			}
			break;
		case 1:
			if (dataHydro.at(ii) != 'B' && penanda == 1)
			{
				hydro2_kirim[j++] = dataHydro.at(ii);
			}
			else
			{
				j = 0;
			}
			break;
		}

	}

	amplitude = atoi(hydro2_kirim);
	frequency = atoi(hydro1_kirim);

	emit serial_kirim_data_Hydro(frequency, amplitude);
}
void SerialConnection::readSRF()
{
	QMutex mutex;
	mutex.lock();

	static int i = 0;
	static int j = 0;
	static int k = 0;
	static int l = 0;
	static int m = 0;

	static int penanda = 0;

	QByteArray dataSRF = serportSRF->readAll();

	for (int ii = 0; ii<dataSRF.length(); ii++)
	{
		if (dataSRF.at(ii) == 'V')
		{
			penanda = 0;
		}
		else if (dataSRF.at(ii) == 'W')
		{
			penanda = 1;
		}
		else if (dataSRF.at(ii) == 'X')
		{
			penanda = 2;
		}
		else if (dataSRF.at(ii) == 'Y')
		{
			penanda = 3;
		}
		else if (dataSRF.at(ii) == 'Z')
		{
			penanda = 4;
		}


		switch (penanda)
		{
		case 0:
			if (dataSRF.at(ii) != 'V')
			{
				srf1_kirim[i++] = dataSRF.at(ii);
			}
			else
			{
				i = 0;
			}
			break;
		case 1:
			if (dataSRF.at(ii) != 'W')
			{
				srf2_kirim[j++] = dataSRF.at(ii);
			}
			else
			{
				j = 0;
			}
			break;
		case 2:
			if (dataSRF.at(ii) != 'X')
			{
				srf3_kirim[k++] = dataSRF.at(ii);

			}
			else
			{
				k = 0;
			}
			break;

		case 3:
			if (dataSRF.at(ii) != 'Y')
			{
				srf4_kirim[l++] = dataSRF.at(ii);

			}
			else
			{
				l = 0;
			}
			break;

		case 4:
			if (dataSRF.at(ii) != 'Z')
			{
				srf5_kirim[m++] = dataSRF.at(ii);

			}
			else
			{
				m = 0;
			}
			break;
		}

	}

	SRF1 = atoi(srf1_kirim);
	SRF2 = atoi(srf2_kirim);
	SRF3 = atoi(srf3_kirim);
	SRF4 = atoi(srf4_kirim);
	SRF5 = atoi(srf5_kirim);

	mutex.unlock();

	emit serial_kirim_data_SRF(SRF1, SRF3, SRF4, SRF2, SRF5);
}

void SerialConnection::readGPS()
{
	static int i = 0;
	static int j = 0;
	static int k = 0;
	static int penanda = 0;

	QByteArray data = serportGPS->readAll();

	for (int ii = 0; ii<data.length(); ii++)
	{
		if (data.at(ii) == 'A')
		{
			penanda = 0;
		}
		else if (data.at(ii) == 'B')
		{
			penanda = 1;
		}
		else if (data.at(ii) == 'C')
		{
			penanda = 2;
		}


		switch (penanda)
		{
		case 0:
			if (data.at(ii) != 'A')
			{
				lat_kirim[i++] = data.at(ii);
			}
			else
			{
				i = 0;
			}
			break;
		case 1:
			if (data.at(ii) != 'B')
			{
				long_kirim[j++] = data.at(ii);
			}
			else
			{
				j = 0;
			}
			break;
		case 2:
			if (data.at(ii) != 'C')
			{
				comp_kirim[k++] = data.at(ii);

			}
			else
			{
				k = 0;
			}
			break;
		}

	}

	lattDouble = atof(lat_kirim);
	longDouble = atof(long_kirim)*(-1);
	//compassOlah = atof(comp_kirim) / 10.0;
	//compassOlah = -0.0000000010*pow(compassOlah,4) + 0.0000140066*pow(compassOlah,3) - 0.0066588300*pow(compassOlah,2) + 1.6456441284*compassOlah - 1.8603693718;
	//compassOlah = -0.0000000319*pow(compassOlah, 4) + 0.0000168992*pow(compassOlah, 3) - 0.0014610177*pow(compassOlah, 2) + 0.8156075285*compassOlah - 0.7134848416;
	//compassOlah = 0.0000000279*pow(compassOlah, 4) - 0.0000240315*pow(compassOlah, 3) + 0.0061727801*pow(compassOlah, 2) + 0.5891490100*compassOlah + 0.7661040946;
	//compassOlah = compassOlah + (float)serial_offset;

	emit serial_kirim_data_GPS(lattDouble, longDouble, compassOlah);
}

void SerialConnection::terima_kontrol(int serv1,int serv2, int mot1, int mot2, int mot3)
{
	ServoKiri = serv1;
	ServoKanan = serv2;
	if (ServoKiri < 700)
	{
		ServoKiri = 700;
		ServoKanan = 700;
	}
	if (ServoKiri > 2300)
	{
		ServoKiri = 700;
		ServoKanan = 700;
	}

	MotorKiri = mot1;
	MotorKanan = mot2;
	MotorTengah = mot3;
}

void SerialConnection::sendDatatoSTM()
{
	QThread::usleep(10);
	sprintf(kirim, "AB%4d,%4d,%4d,%4d,%4d,%4d,%4dC", MotorKiri, MotorKanan, ServoKiri, ServoKanan, Servo_Camera, MotorTengah, Servo_Camera2);
	//sprintf(kirim, "AB1500,1500,1500,1500,1500C");
	serportGPS->write(kirim);
}

void SerialConnection::sendDatatoDrone()
{
	if (serportDrone->isOpen())
	{
		sprintf(kirim_drone, "%d", status_drone);
		serportDrone->write(kirim_drone);
	}
}

void SerialConnection::ubah_status_drone(int stat)
{
	status_drone = stat;
}
