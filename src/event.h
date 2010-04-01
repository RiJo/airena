#ifndef _EVENT_H_
#define _EVENT_H_

class Entity;

enum CAUSE_EVENT {
    WALK,
    ROTATE
};

enum EFFECT_EVENT {
    POSITION,
    ROTATED
};

struct Event {
    Entity *reference;
    CAUSE_EVENT type;
    float factor;
    
    Event(Entity *r, CAUSE_EVENT t, float f) : reference(r), type(t), factor(f) {}
};

#endif