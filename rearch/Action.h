#ifndef __ACTION_H
#define __ACTION_H
#include <iostream>
#include <memory>


namespace game_2d {

enum class action_type {
    NONE,
    START,
    END
};

class Action {
    std::string m_name = "NONE";
    action_type m_type = action_type::NONE;

public:
    Action();
    Action(action_type type, const std::string &name) { }

    const std::string &name() const { return m_name; }
    action_type type() const { return m_type; }
    std::string to_string() const { return m_name; }
};

}


#endif /* __ACTION_H */