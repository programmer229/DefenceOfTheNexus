#ifndef STRATEGY_H
#define STRATEGY_H

#include <QString>

#include "../../core/object.h"
#include "../controllers/databundle.h"
#include "../../core/gameworld.h"

namespace server {

class Strategy {
  public:
    explicit Strategy(std::shared_ptr<core::Object>);

    ~Strategy();

    virtual void tick(std::shared_ptr<core::GameWorld> world, double timeDelta) = 0;

    virtual QString getName() = 0;

    virtual QStringList getRequiredAttributes();

    virtual QStringList getStartAfter();

    virtual void assign(DataBundle& dataBundle) = 0;

    std::shared_ptr<core::Object> getObject() const;

  private:

    std::shared_ptr<core::Object> object;
};

}

#endif //STRATEGY_H
