#ifndef SELECTIONSCREEN_H
#define SELECTIONSCREEN_H

#include <QPushButton>

#include "../screen.h"
#include "../network/multiplayerinterface.h"
#include "../widgets/playerslot.h"

namespace client {

class SelectionScreen : public Screen {
  public:
    explicit SelectionScreen(std::shared_ptr<MultiplayerInterface> multiplayerInterface, int playersCount);

  private:
    void onPaused() override;

    void onResumed() override;

    // ToDo
    void requestSlot(int slot_id);
    // ToDo
    void requestNicknameChange(QString nickname);

    void updateSlots(QVector<QString> list);

    void updatePlayerName(int playerId, const QString& name);

    int getMyPlayerId();

    std::shared_ptr<MultiplayerInterface> multiplayerInterface;

    int playersCount;
    QVector<std::shared_ptr<PlayerSlot>> playersSlots;
};

}

#endif //SELECTIONSCREEN_H
