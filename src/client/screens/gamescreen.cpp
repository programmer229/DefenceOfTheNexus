#include <QDebug>

#include "gamescreen.h"

#include "../mainwindow.h"
#include "../widgets/gamemap.h"
#include "../widgets/imagebutton.h"
#include "../../server/engine.h"
#include "../../core/attributes/moving.h"
#include "../../utils/factory.h"

void client::GameScreen::onPaused() {

}

void client::GameScreen::onResumed() {

}

client::GameScreen::GameScreen() : Screen() {
    auto gameMap = new GameMap();
    gameMap->setDisplayBounds(QRect(1920, 1080, 1920, 1080));
    Sprite background(QPixmap(":/sprites/background"), 1, 4, 4);
    background.setBackAndForthMode(true);
    gameMap->setBackground(background);
    addChild(gameMap);
    auto closeButton = new ImageButton(QPoint(24, 24), 72, 72);
    closeButton->setImage(QImage(":/images/cancel"));
    closeButton->setOnClick([=](QPoint point) {
        QThread* thread = QThread::create([&] {
            QThread::msleep(1);
            MainWindow::getInstance()->closeScreen();
        });
        thread->start();
    });

    addChild(closeButton);

    GameConfiguration gameConfiguration;
    engine = std::shared_ptr<server::Engine>(new server::Engine(gameConfiguration));

    gameMap->setGameWorld(engine->getGameWorld());
    gameMap->setCommandQueue(engine->getCommandQueue());

    gameMap->getGameWorld()->summonObject(utils::Factory::getObjectSignature("test1").value(),
                                          QPoint(2000, 1000), 100);

    gameMap->getGameWorld()->summonObject(utils::Factory::getObjectSignature("resourcebundle-stone").value(),
            QPoint(2200, 1000));

    gameMap->getGameWorld()->buildWall(QPoint(0, 1500), QPoint(2000, 500),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->getGameWorld()->buildWall(QPoint(0, 1500), QPoint(-100, 50),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->getGameWorld()->buildWall(QPoint(2000, 1500), QPoint(0, 500),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->getGameWorld()->buildWall(QPoint(500, 1500), QPoint(0, 500),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->getGameWorld()->buildWall(QPoint(200, 200), QPoint(800, 800),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->getGameWorld()->buildWall(QPoint(-100, 500), QPoint(3, 9000),
                                       utils::Factory::getObjectSignature("wall1").value(),
                                       utils::Factory::getObjectSignature("column1").value());
    gameMap->setShowHitBoxes(true);
    engine->start();
}

const std::shared_ptr<server::Engine>& client::GameScreen::getEngine() const {
    return engine;
}

client::GameScreen::~GameScreen() {
    if (engine) {
        engine->finish();
    }
}
