#pragma once


#include <QTimer>
#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonvalue.h>
#include <qpair.h>
#include <qvariant.h>
#include <qhttpmultipart.h>
#include <quuid.h>
#include <qbuffer.h>
#include <qimage.h>
#include <qstring.h>
#include <qmessagebox.h>
#include <qnetworkinterface.h>
#define	TEMANAME "ITSN"
class Networking : public QObject
{
	Q_OBJECT
public:
	explicit Networking(QObject *parent = 0);
private:
	QTimer *hearbeat;
	QString timestamp;
	QString challenge;
	QString latitude;
	QString longitude;
	QString currCourse;
	QByteArray imgToSend;
	QString hostIp;
	QString prevBoundary;
	QNetworkAccessManager *manager;
	QNetworkReply * replyHeartBeat;
	QString baseUrl;
	QPair<QNetworkRequest, QByteArray> prevReq;
	void debugReply(QNetworkReply*);
	QImage currentImage;
	QString getHost();
	//void uploadImage(QUrl);
	public slots:
	void setBaseURL(QString);
	void setCurrentCourse(QString);
	void start();
	void stop();

	void requestDispacher();

	void setCourse(QString);

	void sendRequestHeartbeat();
	void sendRequestHearbeat(QUrl);
	void handleRequestDataHeartbeat(QNetworkReply*);

	void sendRequestStart();
	void sendRequestStart(QUrl);
	void handleRequestStart(QNetworkReply*);

	void sendRequestStop(QUrl);
	void handleRequestStop(QNetworkReply*);

	void sendRequestFollowLeader(QUrl);
	void handleRequestFollowLeader(QNetworkReply*);

	void sendRequestAutoDock(QUrl);
	void handleAutoDock(QNetworkReply*);

	void sendRequestGoogle();

	void updateTime();
	void setCurrentMission(int);
	void updatePayload(double, double, double, long, int, int, int);
	void updateGPS(double, double, float);
	void setImage(QImage);
	void sendImage(QImage);
signals:
	void emitMsg(QString);
};


