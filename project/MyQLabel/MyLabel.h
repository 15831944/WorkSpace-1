#ifndef __MYLABEL_H__
#define __MYLABEL_H__

#include <QLabel>
#include <QTimer>




#define ROOL_0			0//��ʾ������ʽ1
#define ROOL_1			1//��ʾ������ʽ2


class MyQLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyQLabel(QWidget *parent=0);
	~MyQLabel();

	/*
	 * �����ı�:
	 * 1. ���mscondΪ0�����ֲ�����(Ĭ�ϲ�����);
	 * 2. �������setText()���ֽ�������(��ʹ��QLabel��ͬ);
	*/
	void SetText(const QString &context=0, const int &mscond=0);

private slots:
	void SlotTimeOut();

private:
	QTimer *m_timer;
	int m_msecond;
	QString m_context;
	int m_pos;
	int m_rool;

private:
	void InitVar(int mscond=0);
};

#endif