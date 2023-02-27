#include "networking.h"

Networking::Networking(QObject *parent) : QObject(parent) {
	currCourse = "";
	challenge = "gates";
	hostIp = getHost();
	latitude = "40.689249";
	longitude = "-74.044500";
}

QString Networking::getHost() {
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
	for (int i = 0; i<list.count(); i++) {
		if (!list[i].isLoopback()) {
			if (list[i].protocol() == QAbstractSocket::IPv4Protocol && list[i] != QHostAddress(QHostAddress::LocalHost)) {
				qDebug() << "Host ip: " << list[i].toString();
				return list[i].toString();
			}

		}
	}
	return QString("0.0.0.0");
}

void Networking::sendRequestHearbeat(QUrl url) {
	/*
	QJsonObject msg, pos;
	pos.insert("datum", QJsonValue("WGS84"));
	pos.insert("latitude", QJsonValue(latitude));
	pos.insert("longitude", QJsonValue(longitude));
	msg.insert("timestamp", QJsonValue(timestamp));
	msg.insert("challange", QJsonValue(challenge));
	msg.insert("position", QJsonValue(pos));
	qDebug() << "Masuk request heartbeat";
	QJsonDocument tmp = QJsonDocument(msg);
	QByteArray msgByte = tmp.toJson();
	QByteArray msgLengthByte;
	*/
	QNetworkRequest request(url);
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestDataHeartbeat(QNetworkReply*)));
	QString time = "\"" + timestamp + "\"";;
	QString challengeKirim = "\"" + challenge + "\"";
	QString latitudeKirim = latitude;
	QString longitudeKirim = longitude;
	QString heartBeatStr = QString("{\"timestamp\":%1,\"challenge\":%2,\"position\":{\"datum\":\"WGS84\",\"latitude\":%3,\"longitude\":%4}}").arg(time, challengeKirim, latitudeKirim, longitudeKirim);
	QByteArray msgByte = heartBeatStr.toUtf8();
	QByteArray msgLengthByte;
	msgLengthByte.setNum(msgByte.length());
	qDebug() << "Pesan kirim hearbeat: " << heartBeatStr;
	msgLengthByte.setNum(msgByte.length());
	request.setRawHeader("Host", hostIp.toUtf8());
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Content-Length", msgLengthByte);
	qDebug() << "Isi pesan heartbeat " << msgByte;
	QNetworkReply * reply = manager->post(request, msgByte);

	prevReq = qMakePair<QNetworkRequest, QByteArray>(request, msgByte);
}

void Networking::sendRequestHeartbeat() {
	QJsonObject msg, pos;
	QString getUrl = "http://192.168.66.2:8080/heartbeat/courseC/ITSN";
	QUrl url(getUrl);
	QString time = "\"" + timestamp + "\"";;
	QString challengeKirim = "\"" + challenge + "\"";
	QString latitudeKirim = "\"" + latitude + "\"";
	QString longitudeKirim = "\"" + longitude + "\"";
	//QString heartBeatStr = "{\"timestamp\":" + time + ",\"challenge\":" + challengeKirim + ",\"position{\"datum\":\"WGS84\",\"latitude\":" + latitudeKirim + ",\"longitude\":" + longitudeKirim + "}}";
	//QByteArray heartBeat = heartBeatStr.toUtf8();
	QByteArray heartBeat = "{\"timestamp\":\"20150306061030\",\"challenge\":\"gates\",\"position\":{\"datum\":\"WGS84\",\"latitude\":40.689249,\"longitude\":-74.044500}}";
	QByteArray msgLengthByte;
	msgLengthByte.setNum(heartBeat.length());
	qDebug() << "Pesan kirim hearbeat: " << "{\"timestamp\":\"20150306061030\",\"challenge\":\"gates\",\"position\":{\"datum\":\"WGS84\",\"latitude\":\"40.689249\",\"longitude\":\"-74.044500\"}}";
	QNetworkRequest request(url);


	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Host", hostIp.toUtf8());
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Content-Length", msgLengthByte);
	QNetworkReply * reply = manager->post(request, heartBeat);

	prevReq = qMakePair<QNetworkRequest, QByteArray>(request, heartBeat);
	//    reply->deleteLater();

}

void Networking::handleRequestDataHeartbeat(QNetworkReply * reply) {
	while (!reply->isFinished());
	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	QByteArray bytes = reply->readAll();
	QString strReply = QString::fromUtf8(bytes.data(), bytes.size());
	qDebug() << "Handle heartbeat";
	qDebug() << "Isi pesan : " << strReply;
	debugReply(reply);
	if (statusCode == 503) {
		QByteArray response_data = reply->readAll();
		QJsonObject jsonResp = QJsonDocument::fromJson(response_data).object();
		QNetworkRequest req = prevReq.first;
		QByteArray msg = prevReq.second;
		manager = new QNetworkAccessManager(this);
		connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestDataHeartbeat(QNetworkReply*)));
		QNetworkReply * reply = manager->post(req, msg);
		prevReq = qMakePair<QNetworkRequest, QByteArray>(req, msg);

	}
	reply->deleteLater();
}

void Networking::updateTime() {
	QDateTime currentTime = QDateTime::currentDateTimeUtc();
	//     ui->labelTime->setText(currentTime.toString());
	timestamp = currentTime.toString("yyyyMMddhhmmss");
}

void Networking::setCurrentMission(int i) {
	switch (i) {
	case 1:
		challenge = "gates";
		break;
	case 2:
		challenge = "speed";
		break;
	case 3:
		challenge = "docking";
		break;
	case 4:
		challenge = "path";
		break;
	case 5:
		challenge = "follow";
		sendRequestFollowLeader(QUrl("http://" + baseUrl + "/followLeader/" + currCourse + "/" + TEMANAME));
		break;
	case 6:
		//challenge = "slalom";
		break;
	case 7:
		challenge = "return";
		break;
	default:
		challenge = challenge;
		break;
	}
}

void Networking::sendRequestStart()
{
	//    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
	//    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestStart(QNetworkReply*)));

	//    QString getUrl = "http://localhost:8080/run/start/courseA/AUVSI";
	//    QUrl url(getUrl);

	//    QNetworkRequest request(url);
	//    QString startstr =  "";
	//    QByteArray start = startstr.toUtf8();
	//    request.setRawHeader("Content-Type", "application/json");


	//    QNetworkReply * reply = manager->post(request,start);

}

void Networking::sendRequestStart(QUrl url) {
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestStart(QNetworkReply*)));
	QNetworkRequest request(url);
	QString startstr = "";
	QByteArray start = startstr.toUtf8();
	request.setRawHeader("Host", hostIp.toUtf8());
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Content-Length", "0");
	QNetworkReply * reply = manager->post(request, start);

}

void Networking::handleRequestStart(QNetworkReply *reply) {
	QByteArray bytes = reply->readAll();
	QString strReply = QString::fromUtf8(bytes.data(), bytes.size());
	qDebug() << "Handle start";
	qDebug() << "Isi pesan: " << strReply;
	debugReply(reply);
	reply->deleteLater();
}

void Networking::sendRequestStop(QUrl url) {
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestStop(QNetworkReply*)));
	QNetworkRequest request(url);
	QString stopstr = "";
	QByteArray stop = stopstr.toUtf8();
	request.setRawHeader("Host", hostIp.toUtf8());
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Content-Length", "0");
	QNetworkReply * reply = manager->post(request, stop);
}

void Networking::handleRequestStop(QNetworkReply* reply) {
	QString str = (QString)reply->readAll();
	qDebug() << "Handle stop";
	debugReply(reply);
	reply->deleteLater();
}

void Networking::sendRequestFollowLeader(QUrl url) {
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestFollowLeader(QNetworkReply*)));
	QNetworkRequest req(url);
	req.setRawHeader("Host", hostIp.toUtf8());
	req.setRawHeader("Accept", "*/*");
	//req.setRawHeader("Content-Type", "application/json");
	//req.setRawHeader("Content-Length", "0");
	QNetworkReply *reply = manager->get(req);
}

void Networking::handleRequestFollowLeader(QNetworkReply *reply) {
	while (!reply->isFinished());
	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	QByteArray bytes = reply->readAll();
	QString strReply = QString::fromUtf8(bytes.data(), bytes.size());
	qDebug() << "Handle follow leader";
	qDebug() << "Isi pesan : " << QString(bytes);
	debugReply(reply);
	if (statusCode == 200) {
		QJsonObject jsonResp = QJsonDocument::fromJson(strReply.toUtf8()).object();
		QString code = jsonResp["code"].toString();
		qDebug() << "Resp data : " << strReply;
		qDebug() << "JSON resp : " << jsonResp;
		qDebug() << "code : " << code;
		emit(emitMsg(code));
	}
	reply->deleteLater();
}

void Networking::updatePayload(double lat, double longit, double komp, long spd, int srf, int srf2, int lidar) {
	latitude = QString::number(lat, 'g', 10);
	longitude = QString::number(longit, 'g', 10);
}

void Networking::sendRequestAutoDock(QUrl url) {
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleAutoDock(QNetworkReply*)));
	QNetworkRequest req(url);
	qDebug() << "Masuk request auto dock";
	// create unique boundary
	QString bound = QUuid::createUuid().toString().toUtf8();
	prevBoundary = bound;
	QString tmp = "multipart/form-data; boundary=" + bound;
	// convert QImage to byte array
	QByteArray arr;
	QBuffer buffer(&arr);
	currentImage.save(&buffer, "JPG");
	imgToSend = arr;
	req.setRawHeader("Host", hostIp.toUtf8());
	req.setRawHeader("Content-Type", tmp.toUtf8());
	req.setRawHeader("Content-Length", QString(arr.length()).toUtf8());
	req.setRawHeader("Expect", "100-continue");
	QString emptyStr = "";
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	QDateTime currentTime = QDateTime::currentDateTimeUtc();
	QString fname = "Image-Barunastra-ITS-" + currentTime.toString("yyyyMMddhhmmss") + ".JPG";
	QHttpPart dataPart;
	dataPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"" + fname + "\""));
	dataPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));
	QByteArray dataToSend = imgToSend;
	dataPart.setBody(dataToSend);
	multiPart->append(dataPart);
	multiPart->setBoundary(bound.toUtf8());
	manager = new QNetworkAccessManager(this);
	QNetworkReply *reply = manager->post(req, multiPart);
	multiPart->setParent(reply);
}

void Networking::handleAutoDock(QNetworkReply* reply) {
	while (!reply->isFinished());
	QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	bool status = status_code.isValid();
	qDebug() << "Handle Auto Dock";
	QByteArray response_data = reply->readAll();
	QString strReply = QString(response_data);
	qDebug() << "Ini balasannya: \n\r" << strReply;
	debugReply(reply);
	if (status && status_code.toInt() == 202) {
		QJsonObject jsonResp = QJsonDocument::fromJson(response_data).object();
		QString code = jsonResp["id"].toString();
		qDebug() << code;
		emit(emitMsg(code));
	}
	reply->deleteLater();
}


void Networking::requestDispacher() {
	sendRequestHearbeat(QUrl("http://" + baseUrl + "/heartbeat/" + currCourse + "/" + TEMANAME));
	qDebug() << "http://" + baseUrl + "/HeartBeat/" + currCourse + "/" + TEMANAME;
	//sendRequestFollowLeader(QUrl("http://" + baseUrl + "/followLeader/" + currCourse + "/" + TEMANAME));
	//sendRequestHeartbeat();
	/*if (challenge == "follow") {
	sendRequestFollowLeader(QUrl("http://" + baseUrl + "/followLeader/" + currCourse + "/" + TEMANAME));
	}
	else if (challenge == "docking") {
	sendRequestAutoDock(QUrl("http://" + baseUrl + "/docking/image/" + currCourse + "/" + TEMANAME));
	}*/
}

void Networking::start() {

	if (currCourse == "") {
		/*
		QMessageBox msgBox;
		msgBox.setText("Failed to start connection to server");
		msgBox.setInformativeText("Have not set the course!!!");
		msgBox.setStandardButtons(QMessageBox::Abort);
		msgBox.exec();
		return;
		*/
	}
	//qDebug() << baseUrl + "/run/start/" + currCourse + "/" + TEMANAME;
	sendRequestStart(QUrl("http://" + baseUrl + "/run/start/" + currCourse + "/" + TEMANAME));
	hearbeat = new QTimer();
	//sendRequestFollowLeader(QUrl("http://" + baseUrl + "/followLeader/" + currCourse + "/" + TEMANAME));
	//sendRequestAutoDock(QUrl("http://" + baseUrl + "/docking/image/" + currCourse + "/" + TEMANAME));
	connect(hearbeat, SIGNAL(timeout()), this, SLOT(updateTime()));
	connect(hearbeat, SIGNAL(timeout()), this, SLOT(requestDispacher()));
	//connect(hearbeat, SIGNAL(timeout()), this, SLOT(sendRequestGoogle())); // ini buat uji coba awal doang

	hearbeat->start(1000);
}

void Networking::stop() {
	hearbeat->stop();
	sendRequestStop(QUrl("http://" + baseUrl + "/run/end/" + currCourse + "/" + TEMANAME));
}

void Networking::setCourse(QString s) {
	currCourse = s;
}

void Networking::updateGPS(double lat, double longit, float comp) {
	latitude = QString::number(lat, 'g', 10);
	longitude = QString::number(longit, 'g', 10);
	//qDebug() << "Update gps di networking\n Latitude: " << latitude << "\nlongitude: " << longitude;
}

void Networking::setBaseURL(QString url) {
	this->baseUrl = url;
}

void Networking::setCurrentCourse(QString course) {
	currCourse = course;
}

// ini buat test get goole.com
void Networking::sendRequestGoogle() {
	QNetworkRequest request(QUrl("http://google.com"));
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleRequestDataHeartbeat(QNetworkReply*)));


	QNetworkReply * reply = manager->get(request);
}

void Networking::debugReply(QNetworkReply* reply) {
	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	QByteArray bytes = reply->readAll();
	QString strReply = QString::fromUtf8(bytes.data(), bytes.size());
	qDebug() << "Error code: " << reply->error();
	qDebug() << "Ini status code: " << statusCode;
}

void Networking::setImage(QImage img) {
	currentImage = img;
	QByteArray arr;
	QBuffer buffer(&arr);
	img.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer
	QString iconBase64 = QString::fromLatin1(arr.toBase64().data());
	qDebug() << "Image terkirim ke class networking";
	qDebug() << iconBase64;
	qDebug() << iconBase64.length();
	qDebug() << "lalala";
}

void Networking::sendImage(QImage qim) {
	setImage(qim);
	sendRequestAutoDock(QUrl("http://" + baseUrl + "/docking/image/" + currCourse + "/" + TEMANAME));
}