#pragma once
#include <qobject.h>
#include <qwidget.h>
#include <QLabel>
#include <QMouseEvent>

class kliklabelmappping : public QLabel
{
	Q_OBJECT

public:
	kliklabelmappping(QWidget *parent = 0);
	~kliklabelmappping();

protected:
	void mouseMoveEvent(QMouseEvent *mouse_event);
	void mousePressEvent(QMouseEvent *mouse_event);

signals:
	void sendMousePosition(QPoint&);
	void klik_kiri();
	void klik_kanan();
};
