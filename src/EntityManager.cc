#include "EntityManager.h"

namespace game_2d {
    std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag, float xS,  sf::Color color, int p) {
        auto e = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++, xS,  color, p));
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

        /* add new */
        for(auto n : m_toAdd) {
            m_entities.push_back(n);
            m_entityMap[n->tag()].push_back(n);
            std::cout << n->tag() << std::endl;
        }
        m_toAdd.clear();

        /* remove not alived */
        m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(), [](std::shared_ptr<Entity> e){ return !e->is_alive(); }), m_entities.end());
        for(auto& [key,vec] : m_entityMap)
            vec.erase(std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<Entity> e){ return !e->is_alive(); }), vec.end());
    }

    EntityManager::EntityManager() {

    }
}