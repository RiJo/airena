#include "entity.h"

Entity::Entity(callback e) {
    send_event = e;
}

void Entity::cause(CAUSE_EVENT e) {
    send_event(this, e);
}