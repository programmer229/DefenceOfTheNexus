#include <QDebug>

#include "../mainwindow.h"
#include "gamemap.h"
#include "../../utils/colors.h"

client::GameMap::GameMap(QPoint position, int height, int width):
        Widget(position), lastPaintTime(QDateTime::currentDateTime()), commandQueue(nullptr),
        showHitBoxes(false), showSprites(true) {
    setHeight(height);
    setWidth(width);
    setDisplayBounds(QRect(0, 0, width, height));
}

void client::GameMap::setHeight(int height) {
    this->height = height;
}

void client::GameMap::setWidth(int width) {
    this->width = width;
}

const QRect& client::GameMap::getDisplayBounds() const {
    return displayBounds;
}

void client::GameMap::setDisplayBounds(const QRect& displayBounds) {
    GameMap::displayBounds = displayBounds;
}

void client::GameMap::paint(QPainter& painter) {
    if (gameWorld->getObjects().contains(0)) {
         centerWindow(QPoint(gameWorld->getObjects()[0]->getPosition().x(),
                gameWorld->getObjects()[0]->getPosition().y()));
    }

    // paint transform
    painter.setTransform(getTransformToWidget(), true);

    // renew graphics object list

    for (std::shared_ptr<core::Object> object : gameWorld->getObjects()) {
        if (!graphicsObjects.contains(object->getId())) {
            graphicsObjects.insert(object->getId(),
                                   std::shared_ptr<GraphicsObject>(new GraphicsObject(object)));
        }
    }

    QVector<int> eraseList;

    for (auto iterator = graphicsObjects.begin();
         iterator != graphicsObjects.end();
         ++iterator) {
        if (!gameWorld->getObjects().contains(iterator.key())) {
            eraseList.push_back(iterator.key());
        }
    }

    for (int id : eraseList) {
        graphicsObjects.remove(id);
    }

    // update graphics objects

    int64_t deltaTime = lastPaintTime.msecsTo(QDateTime::currentDateTime());

    lastPaintTime = QDateTime::currentDateTime();

    if (showSprites) {
        for (std::shared_ptr<GraphicsObject> graphicsObject : graphicsObjects.values()) {
            graphicsObject->update(painter.transform(), deltaTime);
        }
    }

    if (showHitBoxes) {
        QPainter hitBoxPainter(MainWindow::getInstance());
        hitBoxPainter.setTransform(painter.transform());

        QFont font = hitBoxPainter.font();
        font.setPointSize(40);
        font.setBold(true);
        hitBoxPainter.setFont(font);
        for (const std::shared_ptr<core::Object>& object : gameWorld->getObjects().values()) {
            QPolygon polygon;
            for (auto point : object->getHitbox()) {
                polygon.append(QPoint(point.x() + object->getPosition().x(),
                                      point.y() + object->getPosition().y()));
            }
            hitBoxPainter.setPen(QPen(QBrush(colors::border),
                                      8, Qt::SolidLine,
                                      Qt::SquareCap, Qt::MiterJoin));
            hitBoxPainter.drawPolygon(polygon);
            hitBoxPainter.setPen(QPen(QBrush(QColor(0,0,0)),
                                      8, Qt::SolidLine,
                                      Qt::SquareCap, Qt::MiterJoin));
            hitBoxPainter.drawText(object->getPosition() - QPoint(20,0), QString::number(object->getId()));
        }
    }
}

const std::shared_ptr<core::GameWorld>& client::GameMap::getGameWorld() const {
    return gameWorld;
}

void client::GameMap::setGameWorld(const std::shared_ptr<core::GameWorld>& gameWorld) {
    GameMap::gameWorld = gameWorld;
}

QTransform client::GameMap::getTransformToWidget() const {
    return QTransform(1, 0, 0, 1, -displayBounds.x(), -displayBounds.y()) *
           QTransform(static_cast<double>(width) / displayBounds.width(), 0, 0,
                      static_cast<double>(height) / displayBounds.height(), 0, 0);
}

QTransform client::GameMap::getTransformToMap() const {
    return getTransformToWidget().inverted();
}

void client::GameMap::clicked(QPoint point) {
    point = getTransformToMap().map(point);
    commandQueue->push_back(core::Command("change_move_target", {"0", QString::number(point.x()),
                                                                 QString::number(point.y())}));
}

const std::shared_ptr<QQueue<core::Command>>& client::GameMap::getCommandQueue() const {
    return commandQueue;
}

void client::GameMap::setCommandQueue(const std::shared_ptr<QQueue<core::Command>>& commandQueue) {
    GameMap::commandQueue = commandQueue;
}

int client::GameMap::getWindowHeight() const {
    return displayBounds.height();
}

int client::GameMap::getWindowWidth() const {
    return displayBounds.width();
}

QPoint client::GameMap::getWindowSize() const {
    return QPoint(getWindowWidth(), getWindowHeight());
}

QPoint client::GameMap::getWindowCenter() const {
    return displayBounds.center();
}

void client::GameMap::centerWindow(const QPoint& point) {
    setDisplayBounds(QRect(point.x() - getWindowWidth() / 2.0,
                           point.y() - getWindowHeight() / 2.0,
                           getWindowWidth(), getWindowHeight()));
}

void client::GameMap::changeWindowWidth(int width) {
    QPoint center = getWindowCenter();
    displayBounds.setWidth(width);
    centerWindow(center);
}

void client::GameMap::changeWindowHeight(int height) {
    QPoint center = getWindowCenter();
    displayBounds.setHeight(height);
    centerWindow(center);
}

void client::GameMap::resizeWindow(const QPoint& size) {
    changeWindowWidth(size.x());
    changeWindowHeight(size.y());
}

void client::GameMap::scaleWindow(double scaling) {
    changeWindowWidth(getWindowWidth() * scaling);
    changeWindowHeight(getWindowHeight() * scaling);
}

void client::GameMap::wheelEvent(QWheelEvent* event) {
    scaleWindow(event->angleDelta().y() > 0 ? 1 / 1.03 : 1.03);
}

bool client::GameMap::isShowHitBoxes() const {
    return showHitBoxes;
}

void client::GameMap::setShowHitBoxes(bool showHitBoxesMode) {
    GameMap::showHitBoxes = showHitBoxesMode;
}

bool client::GameMap::isShowSprites() const {
    return showSprites;
}

void client::GameMap::setShowSprites(bool showSprites) {
    GameMap::showSprites = showSprites;
}
