#ifndef SUBJECT_
#define SUBJECT_
#include "Observer.h"
#include "Subject.h"

#define SIZE 32

struct subject
{
    struct observer *list_observer[SIZE];
    int state;
    int index;
};

void init_subject(struct subject *);

void add_list(struct subject *, struct observer *);

int get_state(struct subject *);

void set_state(struct subject *, int state_change);

#endif