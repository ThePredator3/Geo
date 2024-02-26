#pragma once

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

#include "Sand.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();

    QTcpSocket *socket;

private:
    QVector<QTcpSocket*> Sockets;
    QByteArray Data;

    void SendToClient(const SoilData& data);

public slots:
    void incomingConnection(qintptr socketDescriptor) override;
    void slotReadyRead();
};
