#ifndef __ENTITY_MANAGER_
#define __ENTITY_MANAGER_
#include <memory>

#include "Entity.h"

namespace game_2d {
    using EntityVec = std::vector<std::shared_ptr<Entity>> ;
    using EntityMap = std::map   <std::string, EntityVec>  ;

    class EntityManager {
        EntityVec m_entities;
        EntityVec m_toAdd;
        EntityMap m_entityMap;
        size_t m_totalEntities = 0;

    public:
        EntityManager();
        std::shared_ptr<Entity> addEntity(const std::string &tag, float xS,  sf::Color color);
        void update();
        EntityVec& getEntities();
        EntityVec& getEntities(const std::string &tag);
    };
}

#endif /* define __ENTITY_MANAGER */