#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include "../core/object.h"
#include "spritecontroller.h"

namespace client {

class GraphicsObject {
  public:
    explicit GraphicsObject(const std::shared_ptr<core::Object>& object);

    void update(const QTransform& painterTransform, uint64_t timeDeltaMSec);

    const std::shared_ptr<core::Object>& getObject() const;

    int getHeight() const;

    int getWidth() const;

  private:
    std::shared_ptr<core::Object> object;

    int height;
    int width;

    QVector<std::shared_ptr<SpriteController>> spriteControllers;
};

}

#endif //GRAPHICSOBJECT_H
