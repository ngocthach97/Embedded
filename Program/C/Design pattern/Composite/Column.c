#include "Column.h"
#include <stdio.h>
#include "Component.h"

void add_column(struct component *component)
{
    printf("Add column ! \n");
}

void render_column(struct component *component)
{
    printf("Render column ! \n");
}
struct component_pos column_pos = {
    ._add = add_column,
    ._render = render_column,
};

void init_column(struct column *column)
{
    init_component(&column->component);
    column->component.name = "column";
    column->component.pos = &column_pos;
}