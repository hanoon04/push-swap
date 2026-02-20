#include "../includes/push_swap.h"

void	free_all(t_ps *ps)
{
	if (!ps)
		return ;
	node_clear(&ps->a);
	node_clear(&ps->b);
}