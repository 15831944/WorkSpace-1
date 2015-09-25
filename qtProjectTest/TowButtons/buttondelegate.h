#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QItemDelegate>

class ButtonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ButtonDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

signals:
  void rowSignal(int);
public slots:

private:
    void showMsg(QString str);

private:

    typedef QMap<QModelIndex, QPair<QStyleOptionButton*, QStyleOptionButton*>* >  collButtons;
    collButtons m_btns;

};

#endif // BUTTONDELEGATE_H
