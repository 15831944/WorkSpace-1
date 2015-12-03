#include <QtGui>

#include "trackdelegate.h"
#include "trackeditor.h"

Track::Track(const QString &title, int duration)
{
    this->title = title;
    this->duration = duration;
}

TrackEditor::TrackEditor(QList<Track> *tracks, QWidget *parent)
    : QDialog(parent)
{
    this->tracks = tracks;
    //��ͼ�ؼ�
    tableWidget = new QTableWidget(tracks->count(), 2);
    //����ί��
    tableWidget->setItemDelegate(new TrackDelegate(1));
    //������ͼ��ͷ
    tableWidget->setHorizontalHeaderLabels(
            QStringList() << tr("Track") << tr("Duration"));
    //��ʼ����ͼ����
    for (int row = 0; row < tracks->count(); ++row) {
        Track track = tracks->at(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(track.title);
        //���õ�0����������
        tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1
             = new QTableWidgetItem(QString::number(track.duration));
        item1->setTextAlignment(Qt::AlignRight);
        //���õ�1��������
        tableWidget->setItem(row, 1, item1);
    }
    //����ί�е�SizeHint������������ͼ��С
    tableWidget->resizeColumnToContents(0);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    QPushButton *addTrackButton = buttonBox->addButton(tr("&Add Track"),
            QDialogButtonBox::ActionRole);

    connect(addTrackButton, SIGNAL(clicked()), this, SLOT(addTrack()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tableWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Track Editor"));
}

void TrackEditor::done(int result)
{
    //ok
    if (result == QDialog::Accepted) {
        tracks->clear();
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            QString title = tableWidget->item(row, 0)->text();
            QTableWidgetItem *item = tableWidget->item(row, 1);
            int duration = item ? item->text().toInt() : 0;
            tracks->append(Track(title, duration));
        }
    }
    QDialog::done(result);
}

void TrackEditor::addTrack()
{
    //������²���һ��
    tableWidget->insertRow(tableWidget->rowCount());
}
