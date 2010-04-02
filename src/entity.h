#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "point.h"
#include "vector.h"
#include "event.h"

class Entity;

typedef void (*callback)(Entity *, CAUSE_EVENT, float);


class Entity {
    private:
        void (*send_event)(Entity *, CAUSE_EVENT, float);
    
    protected:
        void cause(CAUSE_EVENT, float);

    public:
        Entity(callback);
        virtual ~Entity();
        virtual void effect(EFFECT_EVENT, float) = 0;
        virtual void tick() = 0;
};

#endif