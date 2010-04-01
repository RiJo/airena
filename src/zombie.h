#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "entity.h"

class Zombie : private Entity {
    public:
        Zombie(callback cause) : Entity(cause) {}
        virtual void effect(EFFECT_EVENT, float);
        virtual void tick();
};

#endif