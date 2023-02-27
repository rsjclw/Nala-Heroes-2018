#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <qhostaddress.h>
#include <qmutex.h>
#include <qthread.h>
#include <qbuffer.h>
#include <qimage.h>
#include <qimagereader.h>
#include <qimagewriter.h>
class DroneConnection : public QObject {
	Q_OBJECT
public:
	explicit DroneConnection(QObject *parent = 0);
	~DroneConnection();
	bool status;
	QThread *writerThread;
private:
	QTcpSocket *sock;
	int dataSize;
	QDataStream in;
	QByteArray buffer;

	public slots:
	void doConnect(QString serverIp, quint16 serverPort);
	void connected();
	void disconnected();
	void bytesWritten(qint64 bytes);
	void readyRead();
	void doDisconnect();
	void write();
signals:
	void imageRecieved(QImage);
};

