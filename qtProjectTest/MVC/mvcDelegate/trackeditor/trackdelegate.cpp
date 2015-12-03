#include <QtGui>

#include "trackdelegate.h"

TrackDelegate::TrackDelegate(int durationColumn, QObject *parent)
    : QItemDelegate(parent)
{
    this->durationColumn = durationColumn;
}

void TrackDelegate::paint(QPainter *painter,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    //�����������
    if (index.column() == durationColumn) {
        //���������ӦModel�е�����
        int secs = index.model()->data(index, Qt::DisplayRole).toInt();
        //����ʱ���ʽ�ַ��� ��:��
        QString text = QString("%1:%2")
                       .arg(secs / 60, 2, 10, QChar('0'))
                       .arg(secs % 60, 2, 10, QChar('0'));
        //��ȡ��������
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        //�����ı�
        drawDisplay(painter, myOption, myOption.rect, text);
        //�����ǰ�н��㣬�ͻ���һ��������Σ�����ʲô������
        drawFocus(painter, myOption, myOption.rect);
    } else{
        //����Ĭ��
        QItemDelegate::paint(painter, option, index);
    }
}

QWidget *TrackDelegate::createEditor(QWidget *parent,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    //����ʱ����
    if (index.column() == durationColumn) {
        //ʱ��༭�ؼ�
        QTimeEdit *timeEdit = new QTimeEdit(parent);
        //ʱ��༭�ؼ��ı���ʽ
        timeEdit->setDisplayFormat("mm:ss");
        //����༭�����������ύ�͹رղ�
        connect(timeEdit, SIGNAL(editingFinished()),
                this, SLOT(commitAndCloseEditor()));
        return timeEdit;
    } else {
        //����ʹ��Ĭ��ί�д���
        return QItemDelegate::createEditor(parent, option, index);
    }
}
//���ÿؼ�ֵ
void TrackDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
{
    //����ʱ����
    if (index.column() == durationColumn) {
        //��õ�ǰ������Model�е�ֵ
        int secs = index.model()->data(index, Qt::DisplayRole).toInt();
        //����ʱ��ؼ���ֵ
        QTimeEdit *timeEdit = qobject_cast<QTimeEdit *>(editor);
        timeEdit->setTime(QTime(0, secs / 60, secs % 60));
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}
//����Modelֵ
void TrackDelegate::setModelData(QWidget *editor,
                                 QAbstractItemModel *model,
                                 const QModelIndex &index) const
{
    //������
    if (index.column() == durationColumn) {
        //���ʱ��ؼ�ֵ
        QTimeEdit *timeEdit = qobject_cast<QTimeEdit *>(editor);
        QTime time = timeEdit->time();
        int secs = (time.minute() * 60) + time.second();
        //����ģ��ֵ
        model->setData(index, secs);
    } else {
        //����ʹ��Ĭ��ί�д���
        QItemDelegate::setModelData(editor, model, index);
    }
}
//�Զ��� �ύ�͹ر� �ۺ���
void TrackDelegate::commitAndCloseEditor()
{
    QTimeEdit *editor = qobject_cast<QTimeEdit *>(sender());
    //�ύ�ÿؼ���ֵ ����ģ�������ݲ�����
    emit commitData(editor);
    //�رոÿؼ� ���Ը�֪ί��ȥ������һ���ؼ�
    emit closeEditor(editor);
}
