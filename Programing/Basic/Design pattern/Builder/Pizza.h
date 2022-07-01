#ifndef PIZZA_H_
#define PIZZA_H_

struct pizza_ops;
struct pizza
{
	char *name;
	struct pizza_ops *ops;
};


struct pizza_ops
{
	void (*prepare)(struct pizza *);
	void (*bake)(struct pizza *);
	void (*cut)(struct pizza *);
	void (*box)(struct pizza *);

	struct pizza_ops *__super;
};

void init_pizza(struct pizza *);

static inline void pizza_prepare(struct pizza *pizza)
{
	pizza->ops->prepare(pizza);
}

static inline void pizza_bake(struct pizza *pizza)
{
	pizza->ops->bake(pizza);
}

static inline void pizza_cut(struct pizza *pizza)
{
	pizza->ops->cut(pizza);
}

static inline void pizza_box(struct pizza *pizza)
{
	pizza->ops->box(pizza);
}

#endif /* PIZZA_H_ */