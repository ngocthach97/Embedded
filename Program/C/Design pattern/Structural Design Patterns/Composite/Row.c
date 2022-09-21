#include "Row.h"
#include <stdio.h>
#include "Component.h"
void add_row(struct component *component)
{
    printf("Add row ! \n");
}

void render_row(struct component *component)
{
    printf("Render row ! \n");
}
struct component_pos row_pos = {
    ._add = add_row,
    ._render = render_row,
};

void init_row(struct row *row)
{
    init_component(&row->component);
    row->component.name = "row";
    row->component.pos = &row_pos;
}