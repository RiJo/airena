#include "event.h"
#include "zombie.h"

#include <stdio.h>      /* printf() */
#include <unistd.h>     /* sleep() */
#include <set>
#include <queue>

/*

    * thread entities to make events asynchronous

*/

std::set<Entity *> entities;
std::queue<Event *> events;
std::set<Entity *> pending;


void event(Entity *reference, CAUSE_EVENT event, float factor) {
    if (pending.count(reference) == 1) {
        events.push(new Event(reference, event, factor));
        pending.erase(reference);
    }
    else {
        printf("NOT ALLOWED TO SEND MORE EVENTS\n");
    }
}

void handle_event(Event *e) {
    printf("e:\tfrom: %ld\ttype: %d\tfactor: %f\n", (long)e->reference, e->type, e->factor);
    switch (e->type) {
        case WALK:
            e->reference->effect(POSITION, 0.5);
            break;
        case ROTATE:
            e->reference->effect(ROTATED, 0.75);
            break;
    }
}

int main(int argc, char **argv) {
    entities.insert((Entity *)new Zombie(&event));
    entities.insert((Entity *)new Zombie(&event));

    std::set<Entity *>::iterator it;
    while (1) {
        pending.clear();
        for (it = entities.begin(); it != entities.end(); it++) {
            pending.insert(*it);
            (*it)->tick();
        }

        while (!events.empty()) {
            Event *e = events.front();
            events.pop();
            handle_event(e);
            delete e;
        }

        sleep(1);
    }

    return 0;
}
