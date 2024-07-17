#ifdef __ENTITY_MANAGER_
#define __ENTITY_MANAGER_

#include "Entity.h"
typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map   <std::string, EntityVec>  EntityMap;
class EntityManager
{
    EntitytVec m_etities;
    EntityVec m_toAdd;
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;

public:
    EntityManager();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    void update();
    EntityVec& getEntities();
    EntityVec& getEntities(const std::string &tag);
};

#endif /* define __ENTITY_MANAGER */