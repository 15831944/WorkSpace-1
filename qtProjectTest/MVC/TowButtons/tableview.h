#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include "tablemodel.h"
#include "buttondelegate.h"

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);
    TableModel* tableModel() {return m_model;}

    ~TableView();

signals:

public slots:
    void  showRow(int);
    void showQModeindex(const QModelIndex& index);

private:
    void iniData();

private:
    TableModel *m_model;
    ButtonDelegate *m_buttonDelegate;

};

#endif // TABLEVIEW_H
