#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
        auto e = std::make_shared<Entity>(tag, m_totalEntities++);
        m_entities.push_back(e);
        m_entityMap[tag].push_back(e);
        return e;
    }

    EntityManager::EntityManager() {

    }
}