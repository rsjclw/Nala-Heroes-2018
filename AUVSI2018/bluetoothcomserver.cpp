#include "bluetoothcomserver.h"

static const QLatin1String serviceUuid("e8e10f95-1a70-4b27-9ccf-02010264e9c8");

BluetoothComServer::BluetoothComServer(QObject *parent)
	: QObject(parent)
{
}

BluetoothComServer::~BluetoothComServer()
{
	stopServer();
}

void BluetoothComServer::startServer(const QBluetoothAddress &localAdapter) {
	if (rfcommServer)
		return;

	rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
	connect(rfcommServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
	bool result = rfcommServer->listen(localAdapter);
	if (!result) {
		qWarning() << "Cannot bind chat server to" << localAdapter.toString();
		return;
	}

	//serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceRecordHandle, (uint)0x00010010);

	QBluetoothServiceInfo::Sequence classId;

	classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));
	serviceInfo.setAttribute(QBluetoothServiceInfo::BluetoothProfileDescriptorList,
		classId);

	classId.prepend(QVariant::fromValue(QBluetoothUuid(serviceUuid)));

	serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceClassIds, classId);

	serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceName, tr("Bt Chat Server"));
	serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceDescription,
		tr("Example bluetooth chat server"));
	serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceProvider, tr("qt-project.org"));

	serviceInfo.setServiceUuid(QBluetoothUuid(serviceUuid));

	QBluetoothServiceInfo::Sequence publicBrowse;
	publicBrowse << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::PublicBrowseGroup));
	serviceInfo.setAttribute(QBluetoothServiceInfo::BrowseGroupList,
		publicBrowse);

	QBluetoothServiceInfo::Sequence protocolDescriptorList;
	QBluetoothServiceInfo::Sequence protocol;
	protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::L2cap));
	protocolDescriptorList.append(QVariant::fromValue(protocol));
	protocol.clear();
	protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::Rfcomm))
		<< QVariant::fromValue(quint8(rfcommServer->serverPort()));
	protocolDescriptorList.append(QVariant::fromValue(protocol));
	serviceInfo.setAttribute(QBluetoothServiceInfo::ProtocolDescriptorList,
		protocolDescriptorList);

	serviceInfo.registerService(localAdapter);

}

void BluetoothComServer::stopServer() {
	// Unregister service
	serviceInfo.unregisterService();

	// Close sockets
	qDeleteAll(clientSockets);

	// Close server
	delete rfcommServer;
	rfcommServer = 0;

}

void BluetoothComServer::sendMessage(const QString &message)
{
	QByteArray text = message.toUtf8() + '\n';

	foreach(QBluetoothSocket *socket, clientSockets)
		socket->write(text);
}

void BluetoothComServer::clientConnected()
{
	QBluetoothSocket *socket = rfcommServer->nextPendingConnection();
	if (!socket)
		return;

	connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
	clientSockets.append(socket);
	emit clientConnected(socket->peerName());
}

void BluetoothComServer::clientDisconnected()
{
	QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
	if (!socket)
		return;

	emit clientDisconnected(socket->peerName());

	clientSockets.removeOne(socket);

	socket->deleteLater();
}

void BluetoothComServer::readSocket()
{
	QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
	if (!socket)
		return;

	while (socket->canReadLine()) {
		QByteArray line = socket->readLine().trimmed();
		emit messageReceived(socket->peerName(),
			QString::fromUtf8(line.constData(), line.length()));
	}
}