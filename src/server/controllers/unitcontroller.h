#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H

#include "../../core/unit.h"

#include "controller.h"

namespace server {

class UnitController : public Controller {
  public:
    explicit UnitController(core::Unit* unit);

    UnitController() = delete;

    static Controller* create(core::Object* object);

    void tick(core::GameWorld* world, double timeDelta) override;

    core::Unit* getUnit() const;

    core::Object* getObject() override;

    void setUnit(core::Unit* unit);

  private:

    core::Unit* unit;
};

}


#endif //UNITCONTROLLER_H
