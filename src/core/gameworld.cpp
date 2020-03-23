//
// Created by derovi on 3/23/2020.
//

#include "gameworld.h"

#include "resource.h"
#include "object.h"

int core::GameWorld::getHeight() const {
    return height;
}

void core::GameWorld::setHeight(int height) {
    GameWorld::height = height;
}

int core::GameWorld::getWidth() const {
    return width;
}

void core::GameWorld::setWidth(int width) {
    GameWorld::width = width;
}

const QVector<core::Resource>& core::GameWorld::getResources() const {
    return resources;
}

void core::GameWorld::setResources(const QVector<core::Resource>& resources) {
    GameWorld::resources = resources;
}

const QMap<int64_t, core::Object *> core::GameWorld::getObjects() const {
    return objects;
}

void core::GameWorld::setObjects(const QMap<int64_t, core::Object *> objects) {
    GameWorld::objects = objects;
}
