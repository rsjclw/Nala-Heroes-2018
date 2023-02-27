#ifndef IMGPROC_H
#define IMGPROC_H

#include <QObject>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\ml\ml.hpp>
#include <qdebug.h>
#include <qthread.h>
#include <qmessagebox.h>
#include <qmutex.h>

#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480
//max number of objects to be detected in frame
#define MAX_NUM_OBJECTS 50
//minimum and maximum object area
#define MIN_OBJECT_AREA 100
#define MAX_OBJECT_AREA 10000
using namespace std;
namespace cv {
	using std::vector;
}

class ImgProc : public QObject
{
	Q_OBJECT

public:
	ImgProc(QObject *parent);
	explicit ImgProc();
	~ImgProc();
	bool status;
	bool thresHolded;
	int missionState;
	QImage imgOri;
	QImage imgWarna[7];
	float pid_out;
private:
	int hMin[7], sMin[7], vMin[7];
	int hMax[7], sMax[7], vMax[7];
	int dilate[7], erode[7];
	int x[7], y[7];
	int rudder;
	int motorKiri, motorKanan, motorOut;
	float prev_error, error, prev_error_flag;
	bool starting, lr;
	float gradient[2];
	float p[3], i[3], d[3];
	pair<int, int> leftCoordinate[2];
	pair<int, int> rightCoordinate[2];
	pair<int, int> nearestRed, nearestGreen;
	pair<int, int> singleObj;
	cv::vector<cv::Point> singleObjContour;
	cv::Mat ori;
	cv::Mat hsv;
	cv::Mat warna[7]; // detect colors
	//cv::vector<cv::vector <cv::Point> > contours[5]; // contour color that detected
	//cv::vector<cv::Vec4i> hierarchy[5];
	cv::VideoCapture camera; // camera to capture image
	QImage matToQImage(cv::Mat &mat); // turn mat into QImage
	void grabFrame();
	void morphOps(cv::Mat &thresh, int, int); // morpOps remove salt and pepper noise
	void drawObject(vector <pair< int, int> > &positions, int); // draw circle with cross hair
	void drawLines(); // draw lines for ship's safe zone
	void trackFilteredObject(int);
	void mission(int, pair<int,int>, vector<cv::Point> &cntr);
	void mission();
	void control2Obj(int);
	void control1Obj(bool);
	int colorId; // penanda index warna
	cv::Point currentPos, initialPos; // posisi mouse pada label gambar

	int batasY = 80;
public slots:
	void receiveHSV(int, int, int, int, int, int, int, int, int);
	void openCamera();
	void reciveSpeed(int);
	void recivePID(float, float, float);
	void recivePID_2(float, float, float);
	void recivePID_3(float, float, float);
	void ubah_batasY(int);
	void reciveColorId(int);
	void reciveMousePos(QPoint); // gambar kotak penanda posisi yang dipilih
	void reciveInitialPos(QPoint); // terima titik awal 
	void thresholding(QPoint); // auto thresholding
	void state_imgproc(int);
	void predictImageDrone(QImage);

signals:
	void sendImage();
	void sendDataKontrol(float);
	void sendDataKontrol2(int, float);
	void dronePrediction(int);
};

#endif // IMGPROC_H
