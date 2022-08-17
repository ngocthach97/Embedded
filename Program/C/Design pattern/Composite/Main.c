#include <stdio.h>
#include <stdlib.h>
#include "Column.h"
#include "Row.h"
#include "Component.h"

int main(int argc, const char *argv[])
{
	struct column *c1;
	struct row *r1, *r2, *r3;

	r1 = (struct row *)malloc(sizeof(struct row));
	init_row(r1);
	r2 = (struct row *)malloc(sizeof(struct row));
	init_row(r2);
	r3 = (struct row *)malloc(sizeof(struct row));
	init_row(r3);

	c1 = (struct column *)malloc(sizeof(struct column));
	init_column(c1);

	add_component(&c1->component, &r1->component);
	add_component(&c1->component, &r2->component);
	add_component(&c1->component, &r3->component);
	get_component(&c1->component);
	return 0;
}
