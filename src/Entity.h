#ifndef __ENTITY_H
#define __ENTITY_H
#include <iostream>
#include <memory>
#include "CTransform.h"
#include "CShape.h"

class Entity
{
    const size_t m_id = 0;
    const std::string m_tag = "Default";
    bool m-alive = true;
public:
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CShape> cShape;
    //std::shared_ptr<CBBox> cBBox;
    //std::shared_ptr<CName> cName;

    Entity(const std::string& tag, size_t id);
};


#endif /* __ENTITY_H */