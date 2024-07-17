#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(std::string &tag)
{
    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    m_entities.push_back(e);
    m_entityMap[tag].push_back(e);
    return e;
}