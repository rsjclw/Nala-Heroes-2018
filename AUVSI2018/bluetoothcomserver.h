#pragma once

#include <QObject>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothaddress.h>
#include <qbluetoothserver.h>

class BluetoothComServer : public QObject
{
	Q_OBJECT

public:
	explicit BluetoothComServer(QObject *parent=0);
	~BluetoothComServer();

	void startServer(const QBluetoothAddress &localAdapter = QBluetoothAddress());
	void stopServer();

	public slots:
	void sendMessage(const QString &message);

signals:
	void messageReceived(const QString &sender, const QString &message);
	void clientConnected(const QString &name);
	void clientDisconnected(const QString &name);

	private slots:
	void clientConnected();
	void clientDisconnected();
	void readSocket();

private:
	QBluetoothServer *rfcommServer;
	QBluetoothServiceInfo serviceInfo;
	QList<QBluetoothSocket *> clientSockets;

};
