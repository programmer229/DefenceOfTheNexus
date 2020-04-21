#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <memory>
#include <QMap>
#include <QtCore/QHash>

#include "object.h"
#include "attributes/resource.h"
#include "../server/objectsignature.h"

namespace core {

class GameWorld {
  public:
    GameWorld();

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);

    QVector<QPair<core::ResourceType, int>>& getResources();

    const QVector<QPair<core::ResourceType, int>>& getResources() const;

    void setResources(const QVector<QPair<core::ResourceType, int>>& resources);

    void addResources(core::ResourceType type, int amount);

    QHash<int64_t, std::shared_ptr<core::Object>>& getObjects();

    const QHash<int64_t, std::shared_ptr<core::Object>>& getObjects() const;

    void setObjects(const QHash<int64_t, std::shared_ptr<core::Object>>& objects);

    std::shared_ptr<core::Object>
    summonObject(const server::ObjectSignature& signature, const QPoint& position,
                 float rotationAngle = 0);

    int getLastSummonedId() const;

    void setLastSummonedId(int lastSummonedId);

    ~GameWorld();

  private:

    int height;
    int width;

    int lastSummonedId;

    QVector<QPair<core::ResourceType, int>> resources;
    QHash<int64_t, std::shared_ptr<core::Object>> objects;
};

}

#endif  // GAMEWORLD_H
