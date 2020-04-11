#ifndef FACTORY_H
#define FACTORY_H

#include <functional>
#include <optional>

#include <QJsonObject>
#include <QHash>
#include <QString>

#include "../core/object.h"
#include "../core/attribute.h"
#include "../server/strategies/strategy.h"
#include "../server/controllers/gameworldcontroller.h"
#include "../server/controllers/controller.h"

namespace utils {

class Factory {
  public:

    static server::Strategy* createStrategy(const QString& strategyName, core::Object* object);

    static std::function<std::optional<QJsonObject>(const core::Attribute*)>
    getSerializer(const QString& attributeName);

    static std::function<std::optional<core::Attribute*>(const QJsonObject&)>
    getDeserializer(const QString& attributeName);

    static void registerStrategy(
            const QString& strategyName,
            std::function<server::Strategy*(core::Object*)> creator);

    static void registerAttribute(
            const QString& attributeName,
            std::function<std::optional<QJsonObject>(const core::Attribute*)> serializer,
            std::function<std::optional<core::Attribute*>(const QJsonObject&)> deserializer);

  private:

    static QHash<QString, std::function<server::Strategy*(core::Object*)>> strategyCreators;

    static QHash<QString, std::function<std::optional<QJsonObject>(
            const core::Attribute*)>> attributeSerializers;

    static QHash<QString, std::function<std::optional<core::Attribute*>(
            const QJsonObject&)>> attributeDeserializers;
};

}

#endif //FACTORY_H
