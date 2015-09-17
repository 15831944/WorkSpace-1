#ifndef WRITESHAREDMEMORY_H
#define WRITESHAREDMEMORY_H

#include <QtGui/QMainWindow>
#include "ui_WriteSharedMemory.h"
#include <QSharedMemory>
#include <QSystemSemaphore>
class WriteSharedMemory : public QMainWindow
{
	Q_OBJECT

public:
	WriteSharedMemory(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WriteSharedMemory();
	///���ÿռ�
	static	QSystemSemaphore freeSystemSem;
	///���ÿռ�
	static	QSystemSemaphore usedSystemSem;
public slots:
	///д�빲���ڴ�
	void loadIntoSharedMem();
	void init();
	void write();
	QString read();
	///ѭ��д
	void run();
	void detach();

	 
private:
	Ui::WriteSharedMemoryClass ui;
	QSharedMemory sharedMem;
	int  num;
};

#endif // WRITESHAREDMEMORY_H
