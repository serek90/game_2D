#ifndef __CLIFESPAN_H
#define __CLIFESPAN_H

namespace game_2d {

    struct CLifeSpan {
        int remaining = 0;
        int total     = 0;
        CLifeSpan(int total_) : remaining{total_}, total{total_} {}
    };

}

#endif /* __CLIFESPAN_H */