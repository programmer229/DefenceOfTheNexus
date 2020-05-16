#ifndef MULTIPLAYERINTERFACE_H
#define MULTIPLAYERINTERFACE_H

#include <memory>

#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>
#include <QtCore/QQueue>

#include "../../core/command.h"
#include "../../core/gameworld.h"
#include "../../core/event.h"

namespace client {

class MultiplayerInterface : public QObject {
  Q_OBJECT
  public:
    MultiplayerInterface(QString address, int port);

    void sendInitRequest();

    void sendCommand(const core::Command& command);

    void sendMessage(const QString& message);

    void eventReceived(const QString& message);

    const QString& getAddress() const;

    int getPort() const;

    const std::shared_ptr<QUdpSocket>& getSocket() const;

    const std::shared_ptr<core::GameWorld>& getGameWorld() const;

    uint8_t getTeam() const;

    QQueue<core::Event> getEventQueue();

    bool isReady();

  private:
    QString address;
    int port;
    QQueue<core::Event> eventQueue;

    std::shared_ptr<QUdpSocket> socket = nullptr;

    std::shared_ptr<core::GameWorld> gameWorld = nullptr;
    uint8_t team;

    void initResponse(const QString& message);
    void worldUpdate(const QString& message);

  private slots:
    void readMessage();

  signals:
    void inited();
};

}

#endif  //MULTIPLAYERINTERFACE_H
