
#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

class TableModel;
class ButtonDelegate;

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);
    TableModel* tableModel() {return m_model;}

    ~TableView();

signals:

public slots:

private:
    void iniData();

private:
    TableModel *m_model;
    ButtonDelegate *m_buttonDelegate;

};

#endif // TABLEVIEW_H

