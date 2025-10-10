#ifndef __ENTITY_H
#define __ENTITY_H
#include <iostream>
#include <memory>
#include "Components/CTransform.h"
#include "Components/CShape.h"
#include "Components/CCollision.h"
#include "Components/CScore.h"
#include "Components/CInput.h"
#include "Components/CLifeSpan.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Components/Vec2.h"

namespace game_2d {
    class Entity {
        const size_t m_id = 0;
        const std::string m_tag = "Default";
        bool m_alive = true;
        Entity(const std::string& tag, size_t id) {}
        Entity(const std::string& tag, size_t id, float xS,  sf::Color color, int p);
        friend class EntityManager;
    public:

        std::shared_ptr<CTransform> cTransform;
        std::shared_ptr<CShape> cShape;
        std::shared_ptr<CCollision> cCollision;
        std::shared_ptr<CScore> cScore;
        std::shared_ptr<CInput> cInput;
        std::shared_ptr<CLifeSpan> cLifeSpan;

        void kill() { m_alive = false; }
        bool is_alive() const { return m_alive; }
        const std::string tag() const { return m_tag; }
        const size_t id() const { return m_id; }
   };
}


#endif /* __ENTITY_H */