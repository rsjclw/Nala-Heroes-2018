#ifndef SAVER_H
#define SAVER_H

#include <QObject>

class Saver : public QObject
{
	Q_OBJECT

public:
	explicit Saver(QObject *parent);
	~Saver();

private:
	
};

#endif // SAVER_H
