#include "zombie.h"

#include <stdio.h>

void Zombie::effect(EFFECT_EVENT e, float factor) {
    printf("effect %d: %f\n", e, factor);
}

void Zombie::tick() {
    printf("tick() = Zombie (%ld)\n", (long)this);
    cause(WALK, 0.666);
    cause(ROTATE, 1.0);
}