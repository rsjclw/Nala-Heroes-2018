#include "DroneConnection.h"



DroneConnection::DroneConnection(QObject *parent) :
	QObject(parent) {
	status = false;
	writerThread = new QThread();
	sock = new QTcpSocket(this);
	dataSize = 0;
	in.setDevice(sock);
	connect(sock, SIGNAL(connected()), this, SLOT(connected()));
	connect(sock, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(sock, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
	//connect(sock, &QIODevice::readyRead, this, &DroneConnection::readyRead);
	connect(sock, SIGNAL(readyRead()), this, SLOT(readyRead()));
}



DroneConnection::~DroneConnection() {
	delete sock;
	delete writerThread;
}

void DroneConnection::doConnect(QString serverIp, quint16 serverPort) {

	//connect(sock, SIGNAL(connected()), this, )
	qDebug() << "Connecting...\n";
	QHostAddress *serverAddress = new QHostAddress(serverIp);
	sock->connectToHost(*serverAddress, serverPort);

	// wait connection for 10 sec
	if (!sock->waitForConnected(10000)) {
		qDebug() << "Error failed to connect: " << sock->errorString();
	}
	status = true;
	//write();
}

void DroneConnection::doDisconnect() {
	sock->disconnectFromHost();
	qDebug() << "Disconnecting...\n";
	// wait to disconnect
	//if (!sock->waitForDisconnected()) {
	//	qDebug() << "Error failed to disconnect: " << sock->errorString();
	//}
	qDebug() << "Disconnected\n";

}

void DroneConnection::connected()
{
	qDebug() << "connected";

	// Hey server, tell me about you.
	sock->write("woi kirim\n");
}

void DroneConnection::write() {
	qDebug() << "Masuk write";
	int i = 0;
	while (status) {
		if (i == 10) break;
		sock->write("woi kirim\n");
		i += 1;
	}
}

void DroneConnection::disconnected()
{
	qDebug() << "disconnected...";
}

void DroneConnection::bytesWritten(qint64 bytes)
{
	qDebug() << bytes << " bytes written...";
}

void DroneConnection::readyRead() {
	qDebug() << "reading...";

	// pertama baca pajang data
	if (dataSize == 0)
	{
		//qDebug() << " masuk\n";

		if (sock->bytesAvailable() < sizeof(quint32))
			return;

		in >> dataSize;
		qDebug() << "#####\n" << "Data size: " << dataSize << endl << "#####\n";
	}

	// read data sampe selesai
	if (dataSize > sock->bytesAvailable())
		return;

	// convert jd QImage
	QByteArray array = sock->read(dataSize);
	QBuffer buffer(&array);
	buffer.open(QIODevice::ReadOnly);

	QImageReader reader(&buffer, "PNG");
	QImage image = reader.read();

	if (!image.isNull()) {
		//image.save("D:/BARUNASTRA/AUVSI/AUVSI2018/temp1.png"); // ini buat testing
		qDebug() << "image written";
		emit imageRecieved(image);
		dataSize = 0;
	}
	else
	{
		qDebug() << "Invalid image received!";
		dataSize = 0;
	}



}


