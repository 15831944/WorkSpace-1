#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

/**
 * @brief ͨ�����νṹ��
 */
class TreeItem
{
public:
    TreeItem(const QList<QVariant> &data,TreeItem *parent=0 );
    ~TreeItem();

    void appendChild(TreeItem *child);
    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();

private:
    TreeItem *parentItem;  // �����
    QList<TreeItem*> childItems; // �ӽ���б�
    QList<QVariant> itemData; // �ӽڵ��Ӧ����
};

#endif // TREEITEM_H
