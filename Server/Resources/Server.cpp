#include "Headers/Server.h"

Server::Server() :
socket(new QTcpSocket)
{
    if(this->listen(QHostAddress::Any, 2323))
    {
        qDebug() << "start";
    }
    else
    {
        qDebug() << "error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Client connected" << socketDescriptor;
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_6);

    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "read...";

        int soilNumber{ 0 };
        float soilResistivity{ 0 };

        in >> soilNumber >> soilResistivity;

        int firstProperty = 0;
        int secondProperty = 1;

        Sand sand(soilNumber, soilResistivity);

        std::string soilName = sand.GetName();

        float resistivity = sand.GetSoilResistivity();
        float porosityCoefficient = sand.PorosityCoefficient();

        float specificAdhesion = sand.SoilProperty(firstProperty, soilNumber);
        float firstSpecificAdhesion = sand.FirstSoilProperty(firstProperty);
        float secondSpecificAdhesion = sand.SecondSoilProperty(firstProperty);

        float angleInternalFriction = sand.SoilProperty(secondProperty, soilNumber);
        float firstAngleInternalFriction = sand.FirstSoilProperty(secondProperty);
        float secondAngleInternalFriction = sand.SecondSoilProperty(secondProperty);

        qDebug() << soilName << resistivity << porosityCoefficient << specificAdhesion << firstSpecificAdhesion <<
                    secondSpecificAdhesion << angleInternalFriction << firstAngleInternalFriction <<
                    secondAngleInternalFriction;

//        SendToClient(SoilData(soilName, resistivity, porosityCoefficient, specificAdhesion, firstSpecificAdhesion,
//                     secondSpecificAdhesion, angleInternalFriction, firstAngleInternalFriction,
//                     secondAngleInternalFriction));

        SoilData data(soilName, resistivity, porosityCoefficient, specificAdhesion, firstSpecificAdhesion,
                 secondSpecificAdhesion, angleInternalFriction, firstAngleInternalFriction,
                 secondAngleInternalFriction);

        SendToClient(data);
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void Server::SendToClient(const SoilData& data)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_6);
    out << QString::fromStdString(data.Dump());
    socket->write(Data);
}

