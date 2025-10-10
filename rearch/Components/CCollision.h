#ifndef __CCOLLISION_H
#define __CCOLLISION_H

namespace game_2d {

    struct CCollision {
        float radius = 0;
        CCollision(float r) : radius{r} {}
    };

}

#endif /* __CCOLLISION_H */