#include "TagTreeModel.h"
#include <QtGui>

TagTreeModel::TagTreeModel(QObject *parent):QAbstractItemModel(parent)
{
    rootItem=NULL;

    updateData();
}

TagTreeModel::~TagTreeModel()
{
    delete rootItem;
}

void TagTreeModel::updateData()
{
    // �����ɵ�ģ������
    if(rootItem)
    {
        delete rootItem;
        rootItem=NULL;
    }

    QList<QVariant> rootData;
    rootData<<"Tag"<<"Type";

    rootItem=new TreeItem(rootData);
    setupModelData(rootItem);

    // ˢ��ģ��
    reset();
}

QVariant TagTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // ���ͼ��
    if(role==Qt::DecorationRole&&index.column()==0)
            return QIcon("images/fold.png");

    // ��ʾ�ڵ�����ֵ
    if(role==Qt::DisplayRole)
    {
        TreeItem *item=static_cast<TreeItem*>(index.internalPointer());
         return item->data(index.column());
    }

    return QVariant();
}

Qt::ItemFlags TagTreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return 0;

    return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

QVariant TagTreeModel::headerData(int section, Qt::Orientation orientation,int role) const
{
    if(orientation==Qt::Horizontal&&role==Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TagTreeModel::index(int row, int column,const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent))
        return QModelIndex();

    TreeItem *parentItem;
    if(!parent.isValid())
    {
        parentItem=rootItem;
    }else
    {
        parentItem=static_cast<TreeItem*>(parent.internalPointer());
    }

    TreeItem *childItem=parentItem->child(row);
    if(childItem)
        return createIndex(row,column,childItem); // չ������,Ϊ�ӽڵ㽨������
    else
        return QModelIndex();
}

QModelIndex TagTreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
        return QModelIndex();

    TreeItem *childItem=static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem=childItem->parent();

    // ����ڵ�,ֱ�ӷ��ؿ�����
    if(parentItem==rootItem)
        return QModelIndex();

    // Ϊ����㽨������
    return createIndex(parentItem->row(),0,parentItem);
}

int TagTreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;

    if(!parent.isValid())
        parentItem=rootItem;
    else
        parentItem=static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount(); // ���ظ�������ӽ����Ŀ
}

int TagTreeModel::columnCount(const QModelIndex &parent ) const
{
    return rootItem->columnCount();
}

// ����ģ������,��������10�������,ÿ���������������ӽڵ�����νṹ
void TagTreeModel::setupModelData(TreeItem *parent)
{
    for(int i=0;i<10;i++)
    {
        QList<QVariant> datas;
        datas<<QString("�豸-%1").arg(i+1)<<QString("����-%1").arg(i+1);

        // ������¹������ӽڵ�
        TreeItem *primary=new TreeItem(datas,parent);
        parent->appendChild(primary);

        for(int j=0;j<2;j++)
        {
            QList<QVariant> ds;
            ds<<QString("���豸-%1").arg(j+1)<<QString("������-%1").arg(j+1);

            primary->appendChild(new TreeItem(ds,primary));
        }
    }
}
