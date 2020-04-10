#include <utility>

#include "attribute.h"
#include "object.h"

core::Object::Object(uint64_t id, QPointF position, QPolygonF hitbox, float rotationAngle):
        id(id), position(position), hitbox(std::move(hitbox)), rotationAngle(rotationAngle) {}

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

QLinkedList<core::Attribute*>& core::Object::getAttributes() {
    return attributes;
}

void core::Object::setAttributes(const QLinkedList<Attribute*>& attributes) {
    Object::attributes = attributes;
}

QLinkedList<QString>& core::Object::getStrategies() {
    return strategies;
}

void core::Object::setStrategies(const QLinkedList<QString>& strategies) {
    Object::strategies = strategies;
}

