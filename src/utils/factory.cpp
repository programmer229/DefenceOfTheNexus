#include <QDebug>

#include "factory.h"

std::shared_ptr<server::Strategy>
utils::Factory::createStrategy(const QString& strategyName,
                               const std::shared_ptr<core::Object>& object) {
    if (object == nullptr || !strategyCreators.contains(strategyName)) {
        return nullptr;
    }
    return strategyCreators[strategyName](object);
}

std::shared_ptr<client::SpriteController>
utils::Factory::createSpriteController(const QString& spriteControllerName,
                                       const std::shared_ptr<core::Object>& object) {
    if (object == nullptr || !spriteControllerCreators.contains(spriteControllerName)) {
        return nullptr;
    }
    return spriteControllerCreators[spriteControllerName](object);
}

void utils::Factory::registerStrategy(const QString& strategyName,
                                      std::function<std::shared_ptr<server::Strategy>(
                                              std::shared_ptr<core::Object>)> creator) {
    strategyCreators.insert(strategyName, creator);
}

void utils::Factory::registerSpriteController(const QString& spriteControllerName,
                                              std::function<std::shared_ptr<client::SpriteController>(
                                                      std::shared_ptr<core::Object>)> creator) {
    spriteControllerCreators.insert(spriteControllerName, creator);
}


void utils::Factory::registerAttribute(const QString& attributeName,
                                       std::function<std::optional<QJsonObject>(
                                               const std::shared_ptr<core::Attribute>)> serializer,
                                       std::function<std::optional<std::shared_ptr<core::Attribute>>(
                                               const QJsonObject&)> deserializer) {
    attributeSerializers.insert(attributeName, serializer);
    attributeDeserializers.insert(attributeName, deserializer);
}

std::function<std::optional<QJsonObject>(const std::shared_ptr<core::Attribute>)>
utils::Factory::getSerializer(const QString& attributeName) {
    if (!attributeSerializers.contains(attributeName)) {
        return [](const std::shared_ptr<core::Attribute>) {
            return std::nullopt;
        };
    }
    return attributeSerializers[attributeName];
}

std::function<std::optional<std::shared_ptr<core::Attribute>>(const QJsonObject&)>
utils::Factory::getDeserializer(const QString& attributeName) {
    if (!attributeDeserializers.contains(attributeName)) {
        return [](const QJsonObject&) {
            return std::nullopt;
        };
    }
    return attributeDeserializers[attributeName];
}

void utils::Factory::registerObjectGraphicsDescription(const QString& objectName,
                                                       const client::ObjectGraphicsDescription& description) {
    graphicsDescriptions.insert(objectName, description);
}

std::optional<client::ObjectGraphicsDescription>
utils::Factory::getObjectGraphicsDescription(const QString& objectName) {
    if (!graphicsDescriptions.contains(objectName)) {
        return std::nullopt;
    }
    return graphicsDescriptions[objectName];
}

QHash<QString, std::function<std::shared_ptr<server::Strategy>(
        std::shared_ptr<core::Object>)>> utils::Factory::strategyCreators;

QHash<QString, std::function<std::optional<QJsonObject>(
        const std::shared_ptr<core::Attribute>)>> utils::Factory::attributeSerializers;

QHash<QString, std::function<std::optional<std::shared_ptr<core::Attribute>>(
        const QJsonObject&)>> utils::Factory::attributeDeserializers;

QHash<QString, client::ObjectGraphicsDescription> utils::Factory::graphicsDescriptions;

QHash<QString, std::function<std::shared_ptr<client::SpriteController>(
        std::shared_ptr<core::Object>)>> utils::Factory::spriteControllerCreators;