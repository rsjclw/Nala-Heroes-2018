#pragma once

#include <QObject>
#include <QThread>
#include "mainwindow.h"


class Mapping : public QObject
{
	Q_OBJECT

public:
	Mapping(QObject *parent = Q_NULLPTR);
	~Mapping();

};
