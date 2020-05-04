#ifndef UNITICON_H
#define UNITICON_H

#include "../graphicsobject.h"
#include "../widget.h"

namespace client {

class UnitIcon : public Widget {
  public:
    UnitIcon(QPoint position, int width, int height);

    const std::shared_ptr<GraphicsObject>& getGraphicsObject() const;

    void setGraphicsObject(const std::shared_ptr<GraphicsObject>& graphicsObject);

    void paint(QPainter& painter) override;

  private:
    std::shared_ptr<GraphicsObject> graphicsObject;
};

}

#endif //UNITICON_H
