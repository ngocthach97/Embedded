#include "Subject.h"
#include "Observer.h"

void init_subject(struct subject *subject)
{
    subject->index = 0;
    subject->state = 0;
}

void add_list(struct subject *subject, struct observer *observer)
{
    subject->list_observer[subject->index++] = observer;
}

int get_state(struct subject *subject)
{
    return subject->state;
}

void set_state(struct subject *subject, int state_change)
{
    subject->state = state_change;
    for (int i = 0; i < subject->index; i++)
    {
        update_observer(subject->list_observer[i]);
    }
}