#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
        auto e = std::make_shared<Entity>(tag, m_totalEntities++, 2 * m_totalEntities,  Color::Green);
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

    void EntityManager::update() {
        for(auto &e : m_entities) {
            e->update();
        }
    }

    EntityManager::EntityManager() {

    }
}