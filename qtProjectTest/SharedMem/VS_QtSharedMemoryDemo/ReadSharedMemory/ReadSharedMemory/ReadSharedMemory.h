#ifndef READSHAREDMEMORY_H
#define READSHAREDMEMORY_H

#include <QtGui/QMainWindow>
#include "ui_ReadSharedMemory.h"
#include <QSharedMemory>
#include <QSystemSemaphore>
class ReadSharedMemory : public QMainWindow
{
	Q_OBJECT

public:
	ReadSharedMemory(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ReadSharedMemory();
	///���ÿռ�
	static	QSystemSemaphore freeSystemSem;
	///���ÿռ�
	static	QSystemSemaphore usedSystemSem;
public slots:
	///��ȡ�����ڴ�
	void loadFromSharedMem();
	void read();
	///ѭ����
	void run();
	void detach();
	void attach();
private:
	Ui::ReadSharedMemoryClass ui;
	QSharedMemory sharedMem;
};

#endif // READSHAREDMEMORY_H
