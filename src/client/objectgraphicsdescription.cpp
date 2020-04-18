#include "objectgraphicsdescription.h"

int client::ObjectGraphicsDescription::getWidth() const {
    return width;
}

void client::ObjectGraphicsDescription::setWidth(int width) {
    ObjectGraphicsDescription::width = width;
}

int client::ObjectGraphicsDescription::getHeight() const {
    return height;
}

void client::ObjectGraphicsDescription::setHeight(int height) {
    ObjectGraphicsDescription::height = height;
}

const QStringList& client::ObjectGraphicsDescription::getSpriteControllers() const {
    return spriteControllers;
}

void client::ObjectGraphicsDescription::setSpriteControllers(const QStringList& spriteControllers) {
    ObjectGraphicsDescription::spriteControllers = spriteControllers;
}


const QHash<QString, SpriteDescription>&
client::ObjectGraphicsDescription::getSpriteDescriptions() {
    return spriteDescriptions;
}

void
client::ObjectGraphicsDescription::setSpriteDescriptions(
        const QHash<QString, SpriteDescription>& spriteDescriptions) {
    ObjectGraphicsDescription::spriteDescriptions = spriteDescriptions;
}