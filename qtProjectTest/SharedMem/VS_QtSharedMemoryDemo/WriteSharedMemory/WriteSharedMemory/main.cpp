#include "WriteSharedMemory.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// ���²��ֽ����������  
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));  
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));  
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));  
	// ���ϲ��ֽ����������  
	WriteSharedMemory w;
	w.show();
	
	return a.exec();
}
