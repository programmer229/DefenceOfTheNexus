#include <utility>

#include "attribute.h"
#include "object.h"

core::Object::Object(uint64_t id, QString typeName, QPointF position, QPolygonF hitbox,
                     float rotationAngle):
    id(id), typeName(std::move(typeName)), position(position), hitbox(std::move(hitbox)),
    rotationAngle(rotationAngle) {}

uint64_t core::Object::getId() const {
    return id;
}

QPointF core::Object::getPosition() const {
    return position;
}

const QPolygonF& core::Object::getHitbox() const {
    return hitbox;
}

float core::Object::getRotationAngle() const {
    return rotationAngle;
}

void core::Object::setPosition(const QPointF& newPosition) {
    position = newPosition;
}

void core::Object::setHitbox(const QPolygonF& newHitbox) {
    hitbox = newHitbox;
}

void core::Object::setRotationAngle(float angle) {
    rotationAngle = angle;
}

bool core::Object::isIntersect(const core::Object& object) const {
    return object.hitbox.intersects(hitbox);
}

void core::Object::setId(uint64_t newId) {
    id = newId;
}

QLinkedList<std::shared_ptr<core::Attribute>>& core::Object::getAttributes() {
    return attributes;
}

void core::Object::setAttributes(const QLinkedList<std::shared_ptr<Attribute>>& attributes) {
    this->attributes = attributes;
}

QStringList& core::Object::getStrategies() {
    return strategies;
}

void core::Object::setStrategies(const QStringList& strategies) {
    this->strategies = strategies;
}

bool core::Object::hasAttribute(const QString& name) const {
    for (const auto& attribute : attributes) {
        if (attribute->getAttributeName() == name) {
            return true;
        }
    }
    return false;
}

const QString& core::Object::getTypeName() const {
    return typeName;
}

void core::Object::setTypeName(const QString& typeName) {
    this->typeName = typeName;
}

const QLinkedList<std::shared_ptr<core::Attribute>>& core::Object::getAttributes() const {
    return attributes;
}

std::shared_ptr<core::Attribute> core::Object::getAttribute(const QString& name) {
    for (const auto& attribute : attributes) {
        if (attribute->getAttributeName() == name) {
            return attribute;
        }
    }
    return nullptr;
}

const QStringList& core::Object::getStrategies() const {
    return strategies;
}
