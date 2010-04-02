#include "entity.h"

Entity::Entity(callback cause) {
    send_event = cause;
}

Entity::~Entity() {
    // nop
}

void Entity::cause(CAUSE_EVENT event, float factor) {
    send_event(this, event, factor);
}