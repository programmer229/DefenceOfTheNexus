#ifndef COST_H
#define COST_H

#include <memory>
#include <QMap>
#include <QtCore/QHash>
#include "resource.h"

#include "../object.h"

namespace core {

class Cost : public Attribute {
  public:
    Cost();

    explicit Cost(QVector<Resource> cost);

    bool isEnough(const Resource& playerResource) const;

    bool isEnough(const QVector<Resource>& playerResources) const;

    const QVector<Resource>& getCost() const;

    // false if not enough
    bool pay(QVector<Resource>& playerResources) const;

    static QString attributeName;

    QString getAttributeName() override;

    std::shared_ptr<Attribute> clone() override;

  private:
    QVector<Resource> cost;
};

} // namespace core


#endif //COST_H
