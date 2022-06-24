#ifndef PIZZA_H_
#define PIZZA_H_

struct pizza;

struct pizza_operations
{
    void (*prepare)(struct pizza *);
    void (*bake)(struct pizza *);
    void (*cut)(struct pizza *);
    void (*box)(struct pizza *);
};

struct pizza
{
    char *name;
    struct pizza_operations *pos;
};

void init_pizza(struct pizza *);

static inline void prepare_pizza(struct pizza *pizza)
{
    pizza->pos->prepare(pizza);
}

static inline void bake_pizza(struct pizza *pizza)
{
    pizza->pos->bake(pizza);
}

static inline void cut_pizza(struct pizza *pizza)
{
    pizza->pos->cut(pizza);
}

static inline  void box_pizza(struct pizza *pizza)
{
    pizza->pos->box(pizza);
}

#endif
