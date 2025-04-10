#ifndef __CLIFESPAN_H
#define __CLIFESPAN_H

namespace game_2d {

    class CLifeSpan {
        int remaining_ = 0;
        int total_     = 0;
        CLifeSpan(int total) : remaining_{total}, total_{total} {}
    };

}

#endif /* __CLIFESPAN_H */