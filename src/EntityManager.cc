#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
        auto e = std::make_shared<Entity>(tag, m_totalEntities++, 10 * m_totalEntities, m_totalEntities, shape_type::Circle, Color::Green);
        m_entities.push_back(e);
        m_entityMap[tag].push_back(e);
        return e;
    }

    EntityVec& EntityManager::getEntities() {
        return m_entities;
    }

    EntityVec& EntityManager::getEntities(const std::string &tag) {
        return m_entityMap[tag];
    }

    EntityManager::EntityManager() {

    }
}