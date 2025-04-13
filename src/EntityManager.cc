#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag, float xS,  sf::Color color) {
        auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++, xS,  color));
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