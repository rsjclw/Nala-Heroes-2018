#include "imgproc.h"
#include <qmessagebox.h>

using namespace std;

ImgProc::ImgProc(QObject *parent)
	: QObject(parent)
{
	missionState = 0;
	nearestRed.first = nearestRed.second = 0;
	nearestGreen.first = nearestGreen.second = 0;
	for (int i = 0; i < 7; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
	thresHolded = false;
	rudder = 1480;
	prev_error = 0;
	prev_error = 0;
	leftCoordinate[0].first = 220;
	leftCoordinate[0].second = 140;
	leftCoordinate[1].first = -60;
	leftCoordinate[1].second = 480;

	gradient[0] = (leftCoordinate[1].second - leftCoordinate[0].second) / (leftCoordinate[1].first - leftCoordinate[0].first);

	rightCoordinate[0].first = 420;
	rightCoordinate[0].second = 140;
	rightCoordinate[1].first = 700;
	rightCoordinate[1].second = 480;
	gradient[1] = (rightCoordinate[1].second - rightCoordinate[0].second) / (rightCoordinate[1].first - rightCoordinate[0].first);
	motorKanan = motorKiri = 1650;
	p[0] = 4;
	i[0] = 0.1;
	d[0] = 2;
	p[1] = 4;
	i[1] = 0.1;
	d[1] = 2;
	p[2] = 0.02;
	i[2] = 0.0005;
	d[2] = 0.01;
	motorOut = 1500;
	starting = 1;
}

ImgProc::ImgProc() {
	missionState = 0;
	nearestRed.first = nearestRed.second = 0;
	nearestGreen.first = nearestGreen.second = 0;
	for (int i = 0; i < 7; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
	thresHolded = false;
	rudder = 1480;
	prev_error = 0;
	prev_error = 0;
	leftCoordinate[0].first = 220;
	leftCoordinate[0].second = 140;
	leftCoordinate[1].first = -60;
	leftCoordinate[1].second = 480;

	gradient[0] = (leftCoordinate[1].second - leftCoordinate[0].second) / (leftCoordinate[1].first - leftCoordinate[0].first);

	rightCoordinate[0].first = 420;
	rightCoordinate[0].second = 140;
	rightCoordinate[1].first = 700;
	rightCoordinate[1].second = 480;
	gradient[1] = (rightCoordinate[1].second - rightCoordinate[0].second) / (rightCoordinate[1].first - rightCoordinate[0].first);
	motorKanan = motorKiri = 1650;
	p[0] = 4;
	i[0] = 0.1;
	d[0] = 2;
	p[1] = 4;
	i[1] = 0.1;
	d[1] = 2;
	p[2] = 0.02;
	i[2] = 0.0005;
	d[2] = 0.01;
	motorOut = 1500;
	starting = 1;
}

ImgProc::~ImgProc()
{
}

void ImgProc::openCamera() {
	camera.open(0);
	if (camera.isOpened() == false) {                 // if unsuccessful
		qDebug() << "Error no camera";	// and exit program
		return;                                 //
	}
	thresHolded = false;
	QThread::msleep(50);
	grabFrame();
}

void ImgProc::grabFrame() {
	qDebug() << "Masuk Grab frame\n";
	QMutex mtx;
	while (status) {
		// get next frame
		bool blnFrameReadSuccessfully = camera.read(ori);              
		// check if successfully read frame
		if (!blnFrameReadSuccessfully || ori.empty()) {
			// fail and stop
			qDebug() << "No camera detected";
			qDebug() << ori.empty();
			return;                                                                                     //
		}
		mtx.lock();
		// convert to hsv
		cv::cvtColor(ori, hsv, CV_BGR2HSV);

		// threshold image to detect color
		for (int i = 0; i < 7;i++) {
			cv::inRange(hsv, cv::Scalar(hMin[i], sMin[i], vMin[i]), cv::Scalar(hMax[i], sMax[i], vMax[i]), warna[i]);
			morphOps(warna[i], erode[i], dilate[i]);
			trackFilteredObject(i+1);
			cv::resize(warna[i], warna[i], cv::Size(0, 0), 0.75, 0.75, 1);
			imgWarna[i] = matToQImage(warna[i]);
		}
		mission();
		mtx.unlock();
		drawLines();
		cv::resize(ori, ori, cv::Size(0, 0), 0.75, 0.75, 1);
		imgOri = matToQImage(ori);
		emit sendImage();
		emit sendDataKontrol((int)pid_out);
		QThread::msleep(100);
	}
	camera.release();
}

QImage ImgProc::matToQImage(cv::Mat &mat)
{
	if (mat.channels() == 1) {                           // if 1 channel (grayscale or black and white) image

		//qDebug() << "sgvudhbkjxn\n";
		return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
	}
	else if (mat.channels() == 3) {                    // if 3 channel color image
		cv::cvtColor(mat, mat, CV_BGR2RGB);             // flip colors
		return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
	}
	else {
		qDebug() << "in openCVMatToQImage, image was not 1 channel or 3 channel, should never get here";
	}
	return QImage();        // return a blank QImage if the above did not work
}

/*int ImgProc::control(cv::Mat camera, target sp, bool abang, bool ijo) {
	int x, y;
	float pid_out;
	double eror;
	//cout<<"x,y jauh="<<unyu.terjauh_banget.first<<","<<unyu.terjauh_banget.second<<endl;
	//cout<<"x,y deket="<<unyu.deket.first<<","<<unyu.deket.second<<endl;
	if (sp.furthest.second == 6969) {
		//p = 0.8, d = 0.1;
		cv::Rect qwer = cv::boundingRect(sp.contour);
		rectangle(camera, qwer, cv::Scalar(255, 0, 255));
		if (abang || sp.close.first<320) {
			x = qwer.x + qwer.width;
			y = qwer.y + qwer.height;
			// set poin kiri
			eror = ((y - leftCoordinate[0].second )*( leftCoordinate[1].first - leftCoordinate[0].first ) / (leftCoordinate[1].second - leftCoordinate[0].second)) + leftCoordinate[0].first;
			eror -= x;
			pid_out = 1500 + p*eror + d*(eror - prev_error) + i*(eror + prev_error);
			prev_error = eror;
		}
		else if (ijo || sp.close.first >= 320) {
			x = qwer.x;
			y = qwer.y + qwer.height;
			// set poin kanan
			eror = ((y - rightCoordinate[0].second)*(rightCoordinate[1].first - rightCoordinate[0].first) / (rightCoordinate[1].second - rightCoordinate[0].second)) + rightCoordinate[0].first;
			eror -= x;
			pid_out = 1500 + p*eror + d*(eror - prev_error) + i*(eror + prev_error);
			prev_error = eror;
		}
	}
	else if (sp.furthest.second != 6969 && sp.close.second<240) {
		//p = 1, d = 0.3;
		int x_target = (sp.furthest.first + sp.far.first) / 2; 
		int y_target = (sp.furthest.second + sp.far.second) / 2;
		circle(camera, cv::Point(x_target, y_target), 7, cv::Scalar(255, 0, 255), 2);
		putText(camera, to_string(x_target) + "," + to_string(y_target), cv::Point(x_target, y_target + 30), 1, 1, cv::Scalar(0, 255, 0), 2);
		eror = 320 - x_target;
		pid_out = 1500 + (p*eror + d*(eror - prev_error) + i*(eror + prev_error));
		if (x_target>640)pid_out = 1500;
	}
	else if (sp.far.second != 6969 && sp.close.second>240) {
		cv::Rect qwer = cv::boundingRect(sp.contour);
		rectangle(camera, qwer, cv::Scalar(255, 0, 255));
		if (sp.close.first<320) {
			x = qwer.x + qwer.width; //pojok kanan bawah
			y = qwer.y + qwer.height; //pojok kanan bawah
			// set poin kiri
			eror = ((y - leftCoordinate[0].second)*(leftCoordinate[1].first - leftCoordinate[0].first) / (leftCoordinate[1].second - leftCoordinate[0].second)) + leftCoordinate[0].first;
			eror -= x;
			pid_out = 1500 + p*eror + d*(eror - prev_error) + i*(eror + prev_error);
			prev_error = eror;
		}
		else if (sp.close.first >= 320) {
			x = qwer.x; //pojok kiri bawah
			y = qwer.y + qwer.height; //pojok kiri bawah
			// set poin kanan
			eror = ((y - rightCoordinate[0].second)*(rightCoordinate[1].first - rightCoordinate[0].first) / (rightCoordinate[1].second - rightCoordinate[0].second)) + rightCoordinate[0].first;
			eror -= x;
			pid_out = 1500 + p*eror + d*(eror - prev_error) + i*(eror + prev_error);
			prev_error = eror;
		}
	}
	if (pid_out < 1380) {
		pid_out = 1380;
	}
	else if (pid_out > 1580) {
		pid_out = 1580;
	}
	printf("x:%d, y:%d, pid out:%d, eror:%3d\r", x, y, (int)pid_out, (int)eror);
	prev_error = eror;
	return pid_out;
}*/

void ImgProc::receiveHSV(int hmin, int smin, int vmin,
						int hmax, int smax, int vmax, 
						int erode, int dilate, int id) {
	//qDebug() << hmin << smin << vmin << id << "\n";
	// recive hsv and update thresholded image
	hMin[id] = hmin;
	sMin[id] = smin;
	vMin[id] = vmin;
	hMax[id] = hmax;
	sMax[id] = smax;
	vMax[id] = vmax;
	this->erode[id] = erode;
	this->dilate[id] = dilate;
	if (thresHolded) {
		cv::inRange(hsv, cv::Scalar(hMin[id], sMin[id], vMin[id]), cv::Scalar(hMax[id], sMax[id], vMax[id]), warna[id]);
		morphOps(warna[id], erode, dilate);
		//qDebug() << hMin[0] << sMin[0] << vMin[0] << "2\n";
		//qDebug() << "thresholded";
	}
}

void ImgProc::morphOps(cv::Mat &thresh, int erodex, int dilatex) {
	if (erodex > 0) {
		cv::Mat erodeElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erodex, erodex));
		cv::erode(thresh, thresh, erodeElement);
		cv::erode(thresh, thresh, erodeElement);
	}
	if (dilatex > 0) {
		//dilate with larger element so make sure object is nicely visible
		cv::Mat dilateElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilatex, dilatex));
		cv::dilate(thresh, thresh, dilateElement);
		cv::dilate(thresh, thresh, dilateElement);
	}
}

void ImgProc::trackFilteredObject(int colorIdx) {
	vector<pair<int, int>> posistions;
	pair<int, int> position;
	cv::Mat temp;
	warna[colorIdx-1].copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<cv::Point> > contours;
	vector<cv::Point> lowest;
	vector<cv::Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if (numObjects<MAX_NUM_OBJECTS) {
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				cv::Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;
				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
				if ((area>MIN_OBJECT_AREA)&(area<MAX_OBJECT_AREA)) {
					position = make_pair((moment.m10 / area), (moment.m01 / area)); // x first y second
					posistions.push_back(position);
					mission(colorIdx, position, contours[index]);
					objectFound = true;
				}
				else {
					objectFound = false;
				}
			}
			//let user know you found an object
			if (objectFound == true) {
				//draw object location on screen
				drawObject(posistions, colorIdx);
			}
		}
		else putText(ori, "TOO MUCH NOISE! ADJUST FILTER", cv::Point(0, 50), 1, 2, cv::Scalar(0, 0, 255), 2);
	}
}

void ImgProc::drawLines() {
	cv::line(ori, cv::Point(leftCoordinate[0].first, leftCoordinate[0].second), cv::Point(leftCoordinate[1].first, leftCoordinate[1].second), 1, 4, 0);
	cv::line(ori, cv::Point(rightCoordinate[0].first, rightCoordinate[0].second), cv::Point(rightCoordinate[1].first, rightCoordinate[1].second), 1, 4, 0);
	cv::line(ori, cv::Point(0, batasY), cv::Point(640, batasY),255,3, 0);
}
void ImgProc::drawObject(vector <pair< int, int> > &positions, int colorIdx) {

	//use some of the openCV drawing functions to draw crosshairs
	//on your tracked image!


	//'if' and 'else' statements to prevent
	//memory errors from writing off the screen (ie. (-25,-25) is not within the window)
	for (int i = 0;i<positions.size();i++) {
		circle(ori, cv::Point(positions[i].first, positions[i].second), 25, cv::Scalar(0, 255, 0), 2);
		if (positions[i].second - 25>0)
			line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first, positions[i].second - 25), cv::Scalar(0, 255, 0), 2);
		else line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first, 0), cv::Scalar(0, 255, 0), 2);
		if (positions[i].second + 25<FRAME_HEIGHT)
			line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first, positions[i].second + 25), cv::Scalar(0, 255, 0), 2);
		else line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first, FRAME_HEIGHT), cv::Scalar(0, 255, 0), 2);
		if (positions[i].first - 25>0)
			line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first - 25, positions[i].second), cv::Scalar(0, 255, 0), 2);
		else line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(0, positions[i].second), cv::Scalar(0, 255, 0), 2);
		if (positions[i].first + 25<FRAME_WIDTH)
			line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(positions[i].first + 25, positions[i].second), cv::Scalar(0, 255, 0), 2);
		else line(ori, cv::Point(positions[i].first, positions[i].second), cv::Point(FRAME_WIDTH, positions[i].second), cv::Scalar(0, 255, 0), 2);

		putText(ori, to_string(positions[i].first)+","+ to_string(positions[i].second), cv::Point(positions[i].first, positions[i].second + 30), 1, 1, cv::Scalar(0, 255, 0), 2);
		putText(ori, to_string(colorIdx), cv::Point(positions[i].first, positions[i].second - 30), 1, 1, cv::Scalar(0, 255, 0), 2);
	}
}

void ImgProc::reciveSpeed(int speed) {
	qDebug() << "Speed baru: " << speed;
	this->motorKiri = this->motorKanan = speed;
}

void ImgProc::recivePID(float p, float i, float d) {
	this->p[0] = p;
	this->i[0] = i;
	this->d[0] = d;

	qDebug() << "img" << this->p[0] << this->i[0] << this->d[0] << endl;
}

void ImgProc::recivePID_2(float p, float i, float d) {
	this->p[1] = p;
	this->i[1] = i;
	this->d[1] = d;

	qDebug() << "img2" << this->p[1] << this->i[1] << this->d[1] << endl;
}

void ImgProc::recivePID_3(float p, float i, float d) {
	this->p[2] = p;
	this->i[2] = i;
	this->d[2] = d;
}

void ImgProc::reciveColorId(int id){
	colorId = id;
}

void ImgProc::reciveMousePos(QPoint p) {
	int tmpHSVMin[3], tmpHSVMax[3];
	currentPos = cv::Point((int)((float)(p.x()*1.3333)), ((int)((float)p.y()*1.3333)));
	cv::rectangle(ori, initialPos, currentPos, cv::Scalar(0, 255, 0), 1, 8, 0); // draw rectangle
}

void ImgProc::reciveInitialPos(QPoint p) {
	initialPos = cv::Point(((float)p.x()*1.3333), ((float)p.y()*1.3333));
}

void ImgProc::thresholding(QPoint p) {
	currentPos = cv::Point((int)((float)(p.x()*1.3333)), ((int)((float)p.y()*1.3333)));
	if ((currentPos.x == initialPos.x)|(currentPos.y==initialPos.y))return;
	int X, x, Y, y;
	int tmpMin[3], tmpMax[3];
	QMutex mtx;
	memset(tmpMin, 255, sizeof(tmpMin));
	memset(tmpMax, 0, sizeof(tmpMax));
	if (initialPos.x>currentPos.x) {
		x = currentPos.x;
		X = initialPos.x;
	}
	else if (initialPos.x<currentPos.x) {
		x = initialPos.x;
		X = currentPos.x;
	}
	if (initialPos.y>currentPos.y) {
		y = currentPos.y;
		Y = initialPos.y;
	}
	else if (initialPos.y<currentPos.y) {
		y = initialPos.y;
		Y = currentPos.y;
	}
	mtx.lock();
	for (int i = x; i < X; i++) {
		for (int j = y; j < Y; j++) {
			
			for (int k = 0; k < 3; k++) {
				if (tmpMin[k] > hsv.at<cv::Vec3b>(j,i)[k]) {
					tmpMin[k] = hsv.at<cv::Vec3b>(j,i)[k];
				}
				if (tmpMax[k] < hsv.at<cv::Vec3b>(j,i)[k]) {
					tmpMax[k] = hsv.at<cv::Vec3b>(j,i)[k];
				}
			}
			
		}
	}
	hMin[colorId] = tmpMin[0];
	sMin[colorId] = tmpMin[1];
	vMin[colorId] = tmpMin[2];
	hMax[colorId] = tmpMax[0];
	sMax[colorId] = tmpMax[1];
	vMax[colorId] = tmpMax[2];

	mtx.unlock();
	
}

void ImgProc::control2Obj(int batas) {
	int x_target = ((nearestRed.first + nearestGreen.first) / 2);
	int y_target = ((nearestRed.second + nearestGreen.second) / 2);
	error = x_target - batas;
	pid_out = 1500 + p[0] * error + d[0] * (error - prev_error) + i[0] * (error + prev_error);
	circle(ori, cv::Point(x_target, y_target), 7, cv::Scalar(255, 0, 255), 2);
	putText(ori, to_string(x_target) + "," + to_string(y_target), cv::Point(x_target, y_target + 30), 1, 1, cv::Scalar(0, 255, 0), 2);
	prev_error = error;
}

void ImgProc::control1Obj(bool right) {	// 0 control right
	cv::Rect qwer = cv::boundingRect(singleObjContour);
	cv::rectangle(ori, qwer, cv::Scalar(255, 0, 255));
	if(right) {
		int x = qwer.x + qwer.width;
		int y = qwer.y + qwer.height;
		error = ((y - leftCoordinate[0].second)*(leftCoordinate[1].first - leftCoordinate[0].first) / (leftCoordinate[1].second - leftCoordinate[0].second)) + leftCoordinate[0].first;
		error -= x;
		pid_out = 1500 - (p[1] * error + d[1] * (error - prev_error) + i[1] * (error + prev_error));
		prev_error = error;
	}
	else {
		int x = qwer.x;
		int y = qwer.y + qwer.height;
		error = ((y - rightCoordinate[0].second)*(rightCoordinate[1].first - rightCoordinate[0].first) / (rightCoordinate[1].second - rightCoordinate[0].second)) + rightCoordinate[0].first;
		error -= x;
		pid_out = 1500 - (p[1] * error + d[1] * (error - prev_error) + i[1] * (error + prev_error));
		prev_error = error;
	}
}

void ImgProc::mission(int colorIdx, pair<int,int> position, vector<cv::Point> &cntr) {
	if (missionState == 1) { // Gate
		cv::Rect qwer = cv::boundingRect(cntr);
		position.second = qwer.y + qwer.height;
		if (colorIdx == 1) {
			if (nearestRed.second < position.second)nearestRed = position;
		}
		else if (colorIdx == 2) {
			if (nearestGreen.second < position.second)nearestGreen = position;
		}
	}
	else if (missionState == 2) { // Speed Challenge
		if (colorIdx == 3) {
			if (singleObj.second < position.second)
			{
				singleObj = position;
				singleObjContour = cntr;
			}
			
		}
	}
	else if (missionState == 3) { 
		cv::Rect qwer = cv::boundingRect(cntr);
		position.second = qwer.y + qwer.height;
		if (colorIdx == 6) {
			if (nearestRed.second < position.second)nearestRed = position;
		}
		else if (colorIdx == 7) {
			if (nearestGreen.second < position.second)nearestGreen = position;
		}
	}

	else if (missionState == 5) {
		if (colorIdx == 4) {
			cv::Rect qwer = cv::boundingRect(cntr);
			nearestRed.first = qwer.x + qwer.width;
			nearestRed.second = qwer.y;
			nearestGreen = nearestRed;
			singleObj.second = qwer.y;
		}
	}
	else if (missionState == 6) { // slalom
		cv::Rect qwer = cv::boundingRect(cntr);
		position.second = qwer.y + qwer.height;
		if (colorIdx == 1 || colorIdx == 2) {
			if (singleObj.second < position.second) {
				singleObjContour = cntr;
				singleObj = position;
				lr = colorIdx - 1;
			}
		}
		else if (colorIdx == 5) {
			if (position.second < 180)return;
			if (singleObj.second < position.second) {
				singleObjContour = cntr;
				singleObj = position;
				lr = 0;
			}
		}
	}
}

void ImgProc::state_imgproc(int state)
{
	missionState = state;
}

void ImgProc::ubah_batasY(int batas)
{
	batasY = batas; 
}

void ImgProc::mission() {
	
	pid_out = 0;

	if (missionState == 1) { // Gate
		if (nearestRed.first && nearestGreen.first) control2Obj(320);
		nearestRed.first = nearestRed.second = 0;
		nearestGreen.first = nearestGreen.second = 0;
	}
	else if (missionState == 2) { // Speed Challenge
		if (singleObj.first) {
			control1Obj(1);
		}
		//else if (nearestRed.first && nearestGreen.first) control2Obj();
		
		//qDebug() << pid_out << endl;
		singleObj.first = singleObj.second = 0;
		//nearestGreen.first = nearestGreen.second = 0;
		//qDebug() << pid_out;
	}
	else if (missionState == 3) { // Docking

		if (nearestRed.first && !nearestGreen.first) 
		{
			if (singleObj.second > batasY) {
				pid_out = -2; //kalo ada merah doang
			}
		}
		else if (!nearestRed.first && nearestGreen.first) 
		{
			if (singleObj.second > batasY) {
				pid_out = -1; //kalo ada hijau doang
			}
		}
		else if (nearestRed.first && nearestGreen.first) 
		{
			control2Obj(320); //
		}
		qDebug() << pid_out;
		nearestRed.first = nearestRed.second = 0;
		nearestGreen.first = nearestGreen.second = 0;	
	}
	else if (missionState == 5) 
	{ // Follow The Leader
		if (nearestRed.first) {
			control2Obj(200);
			if (singleObj.second > batasY) { //ngejar
				motorOut = 1700;
			}
			else { //deket
				motorOut = 1560;
			}
			nearestRed.first = nearestRed.second = 0;
			nearestGreen.first = nearestGreen.second = 0;
			singleObj.second = 0;
		}
		else 
		{
			motorOut = 1800; //ilang
			pid_out = 1200;
		}
		emit sendDataKontrol2(motorOut, pid_out);

	}
	else if (missionState == 6) {
		if (singleObj.second < 100 ) {
			qDebug() << lr << endl;
			if (lr == 0)
			{
				pid_out = 1900;
			}
			else if (lr == 1 )
			{
				pid_out = 1100;
			}
		}
		else if(singleObj.second >= 100){
			control1Obj(lr);
		}
		singleObj.first = singleObj.second = 0;
	}
	emit sendDataKontrol(pid_out);
}

void qimage_to_mat(const QImage& image, cv::OutputArray out) {

	switch (image.format()) {
	case QImage::Format_Invalid:
	{
		cv::Mat empty;
		empty.copyTo(out);
		break;
	}
	case QImage::Format_RGB32:
	{
		cv::Mat view(image.height(), image.width(), CV_8UC4, (void *)image.constBits(), image.bytesPerLine());
		view.copyTo(out);
		break;
	}
	case QImage::Format_RGB888:
	{
		cv::Mat view(image.height(), image.width(), CV_8UC3, (void *)image.constBits(), image.bytesPerLine());
		cvtColor(view, out, cv::COLOR_RGB2BGR);
		break;
	}
	default:
	{
		QImage conv = image.convertToFormat(QImage::Format_ARGB32);
		cv::Mat view(conv.height(), conv.width(), CV_8UC4, (void *)conv.constBits(), conv.bytesPerLine());
		view.copyTo(out);
		break;
	}
	}
}
void ravel_mat(cv::Mat &mat) {

}

void ImgProc::predictImageDrone(QImage qim) {
	qDebug() << "Qim dim" << qim.height() << " " << qim.width() << " " << qim.height()* qim.width();
	cv::Mat img;
	qimage_to_mat(qim, img);
	cv::resize(img, img, cv::Size(225, 225), 0, 0, CV_INTER_LINEAR);
	cv::cvtColor(img, img, CV_BGR2HSV);
	cv::inRange(img, cv::Scalar(24, 0, 231), cv::Scalar(47, 71, 255), img);
	morphOps(img, 3, 1);
	cv::Mat feature(1, img.rows*img.cols, CV_32FC1);
	int ii = 0;
	for (int i = 0; i<img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			feature.at<float>(0, ii++) = img.at<uchar>(i, j);
		}
	}
	/*
	try {
		cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
		svm = cv::ml::SVM::load<cv::ml::SVM>("svm_data.dat");
		int pred = svm->predict(feature);
		qDebug() << "Hasil prediksi gambar drone : " << pred;
		emit dronePrediction(pred);
	}
	catch (const std::exception& e) {
		e.what();
		qDebug() << "Fuck error gak gelem predict";

	}
	*/
	qDebug() << "Feature dim" << feature.rows << " " << feature.cols ;
	cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
	svm = cv::ml::SVM::load<cv::ml::SVM>("svm_data.dat");
	int pred = svm->predict(feature);
	qDebug() << "Hasil prediksi gambar drone : " << pred;
	emit dronePrediction(pred);
}