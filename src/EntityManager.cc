#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag, float xS,  sf::Color color) {
        auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++, xS,  color));
        m_toAdd.push_back(e);
        return e;
    }

    EntityVec& EntityManager::getEntities() {
        return m_entities;
    }

    EntityVec& EntityManager::getEntities(const std::string &tag) {
        return m_entityMap[tag];
    }

    void EntityManager::update() {
        /* remove not alived */

        /* add new */
        for(auto n : m_toAdd) {
            m_entities.push_back(n);
            m_entityMap[n->tag()].push_back(n);
            std::cout << n->tag() << std::endl;
        }
        m_toAdd.clear();

        /* update position */
        for(auto &e : m_entities) {
            e->update();
        }
    }

    EntityManager::EntityManager() {

    }
}