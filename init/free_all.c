#include "../includes/push_swap.h"

void	free_all(t_ps *ps)
{
	if (!ps)
		return ;
	if (ps->a)
	{
		node_clear(&ps->a->top);
		free(ps->a);
		ps->a = NULL;
	}
	if (ps->b)
	{
		node_clear(&ps->b->top);
		free(ps->b);
		ps->b = NULL;
	}
}