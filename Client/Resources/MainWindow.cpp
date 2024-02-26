#include "Headers/MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    ui->textBrowser->append("Hello! My name is Geo.");
    ui->textBrowser->append(" ");
    ui->textBrowser->append("Select one of the soil types and enter its resistivity.");
    ui->textBrowser->append("Types of soil:");
    ui->textBrowser->append("1 - Coarse sand");
    ui->textBrowser->append("2 - Medium sand");
    ui->textBrowser->append("3 - Fine sand");
    ui->textBrowser->append("4 - Silty sand");
    ui->textBrowser->append(" ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SendToServer(int soilNumber, float soilResistivity)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_6);
    out << soilNumber << soilResistivity;
    socket->write(Data);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_6);

    // Проверяем, достаточно ли данных в сокете
    if (socket->bytesAvailable() < sizeof(float) * 7)
    {
        // Если нет, возвращаемся и ждем больше данных
        return;
    }

    QString soilName{};
    float soilResistivity{ 0 };
    float porosityCoefficient{ 0 };
    float specificAdhesion{ 0 };
    float firstSpecificAdhesion{ 0 };
    float secondSpecificAdhesion{ 0 };
    float angleInternalFriction{ 0 };
    float firstAngleInternalFriction{ 0 };
    float secondAngleInternalFriction{ 0 };

    in >> soilName >> soilResistivity >> porosityCoefficient >> specificAdhesion >> firstSpecificAdhesion >>
        secondSpecificAdhesion >> angleInternalFriction >> firstAngleInternalFriction >> secondAngleInternalFriction;

    if(in.status() == QDataStream::Ok)
    {
        ui->textBrowser->append(tr("Name of soil: %1").arg(soilName));
        ui->textBrowser->append(tr("Soil resistivity: %1").arg(soilResistivity) + tr(" MPa"));
        ui->textBrowser->append(tr("Porosity coefficient (e): %1").arg(porosityCoefficient) + tr(" m/day"));
        ui->textBrowser->append(tr("Specific adhesion (cn): %1").arg(specificAdhesion) + tr(" MPa"));
        ui->textBrowser->append(tr("cn_II / cn_I: %1").arg(firstSpecificAdhesion) +tr("/%1").arg(secondSpecificAdhesion));
        ui->textBrowser->append(tr("Angle internal friction (fn): %1").arg(angleInternalFriction) + tr(" grad"));
        ui->textBrowser->append(tr("fn_II / fn_I: %1").arg(firstAngleInternalFriction) +
                                tr("/%1").arg(secondAngleInternalFriction));
        ui->textBrowser->append(" ");
    }
    else
    {
        ui->textBrowser->append("read error");
        // Если нет, выводим сообщение об ошибке
        QMessageBox::critical(this, tr("Ошибка чтения"), tr("Не удалось прочитать данные из сокета"));
    }
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString firstLine = ui->lineEdit->text();
    QString secondLine = ui->lineEdit_2->text();

    bool ok;
    int soilNumber = firstLine.toInt(&ok);
    float soilResistivity = secondLine.toFloat(&ok);

    SendToServer(soilNumber, soilResistivity);
}

