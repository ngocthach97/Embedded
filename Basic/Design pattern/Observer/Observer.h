#ifndef OBSERVER_
#define OBSERVER_
#include "Subject.h"

struct observer_pos;

struct observer
{
    struct observer_pos *pos;
};

struct observer_pos
{
    void (*update)(struct observer *);
};

void init_observer(struct observer *);

static inline void update_observer(struct observer *observer)
{
    observer->pos->update(observer);
}
#endif