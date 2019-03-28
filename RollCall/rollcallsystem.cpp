#include "rollcallsystem.h"

RollCallSystem::RollCallSystem(QWidget *parent) :
    QMainWindow(parent)
{
    initUI();
    readJson();
}

RollCallSystem::~RollCallSystem()
{

}

void RollCallSystem::initUI()
{
    startBtn = new QPushButton("start");
    stopBtn = new QPushButton("stop");
    displayEdit = new QTextEdit("点名");
    displayEdit->setReadOnly(true);

    widget = new QWidget();
    timer = new QTimer;

    connect(timer, SIGNAL(timeout()), this, SLOT(srand()));
    connect(stopBtn, SIGNAL(clicked()), this, SLOT(stopSlot()));
    connect(startBtn, SIGNAL(clicked()), this, SLOT(startSlot()));

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(startBtn, 0);
    buttonLayout->addWidget(stopBtn, 0);

    QHBoxLayout * layout = new QHBoxLayout();
    layout->addWidget(displayEdit);
    layout->addLayout(buttonLayout);

    widget->setLayout(layout);

    setCentralWidget(widget);
}

void RollCallSystem::readJson()
{
    QJsonDocument m_json;
    QJsonObject m_object;

    QFile file;
    file.setFileName(":/setting/data.json");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "warning", "can not open this file");
        return;
    }

    m_json = QJsonDocument::fromJson(file.readAll());
    m_object = m_json.object();

    QJsonArray m_names = m_object.value("person_name").toArray();

    foreach (auto i, m_names) {
        name_data.append(i.toString());
    }

    file.close();
}

void RollCallSystem::startSlot()
{
    timer->start(2000);
}

void RollCallSystem::stopSlot()
{
    timer->stop();

    int num = 0;
    QString str = displayEdit->toPlainText();

    for(int i = 0; i < total; i++)
    {
        num = i;
        break;
    }

    for (int i = 0; i < total - 1; i++)
    {
        if (i > num)
        {
            name_data[i] = name_data[i + 1];
        }
    }

    total--;
}

void RollCallSystem::srand()
{
    qsrand(QTime(0,0,0,0).msecsTo((QTime::currentTime()))); // set seed
    displayEdit->clear();
    int num = qrand() % total;
    displayEdit->setText(name_data[num]);  // random name
}
















