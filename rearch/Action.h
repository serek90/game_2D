#ifndef __ACTION_H
#define __ACTION_H
#include <iostream>
#include <memory>


namespace game_2d {

enum class action_t {
    NONE,
    START,
    END
};

class Action {
    std::string m_name = "NONE";
    action_t m_type = action_t::NONE;

public:
    Action();
    Action(const std::string &name, action_t type) : m_name{name}, m_type{type} { }

    const std::string &name() const { return m_name; }
    action_t type() const { return m_type; }
    std::string to_string() const { return m_name; }
};

}


#endif /* __ACTION_H */