#ifndef OBJECT_H
#define OBJECT_H

#include <QtGlobal>
#include <QPointF>
#include <QPolygonF>

namespace core {

class Object {
  public:
    Object() = delete;

    explicit Object(uint64_t id, QPointF position = QPointF(), QPolygonF hitbox = QPolygonF(),
                    float rotationAngle = 0);

    virtual ~Object() = default;

    uint64_t getId() const;

    QPointF getPosition() const;

    const QPolygonF& getHitbox() const;

    float getRotationAngle() const;

    virtual void setPosition(const QPointF& newPosition);

    virtual void setId(uint64_t newId);

    virtual void setHitbox(const QPolygonF& hitbox);

    virtual void setRotationAngle(float angle);

    virtual QString getTypeName() = 0;

    bool isIntersect(const Object& object) const;

  private:
    uint64_t id;
    QPointF position;
    QPolygonF hitbox;
    float rotationAngle;
};

}  // namespace core

#endif // OBJECT_H