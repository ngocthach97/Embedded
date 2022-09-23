#include <stdio.h>
#include <stdlib.h>
#include "Originator.h"
#include "CareTaker.h"

int main(int argc, const char *argv[])
{
    struct originator *originator = (struct originator *)malloc(sizeof(struct originator));
    init_originator(originator);

    struct caretaker *caretaker = (struct caretaker *)malloc(sizeof(struct caretaker));
    init_caretaker(caretaker);

    _setState_originator(originator, "State #1");

    _setState_originator(originator, "State #2");

    _add(caretaker, _saveStateToMemento_originator(originator));

    _setState_originator(originator, "State #3");

    _add(caretaker, _saveStateToMemento_originator(originator));

    _setState_originator(originator, "State #4");

    printf("Current State: %s \n", _getState_originator(originator));

    _getStateFromMemento_originator(_get(caretaker, 0), originator);

    printf("First saved State: %s \n", _getState_originator(originator));

    _getStateFromMemento_originator(_get(caretaker, 1), originator);

    printf("Second saved State: %s \n", _getState_originator(originator));
    return 0;
}