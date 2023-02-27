#include "kliklabelmappping.h"

kliklabelmappping::kliklabelmappping(QWidget *parent)
	: QLabel(parent)
{
	this->setMouseTracking(true);
}

kliklabelmappping::~kliklabelmappping()
{
}

void kliklabelmappping::mouseMoveEvent(QMouseEvent *mouse_event) 
{
	QPoint mouse_pos = mouse_event->pos();
	if (mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height())
	{
		if (mouse_pos.x() >= 0 && mouse_pos.y() >= 0)
		{
			emit sendMousePosition(mouse_pos);
		}
	}
}

void kliklabelmappping::mousePressEvent(QMouseEvent *mouse_event)
{
	if (mouse_event->button() == Qt::LeftButton)
	{
		emit klik_kiri();
	}
	else if (mouse_event->button() == Qt::RightButton)
	{
		emit klik_kanan();
	}
}