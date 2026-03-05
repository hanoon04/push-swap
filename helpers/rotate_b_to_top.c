#include "../includes/push_swap.h"

void	rotate_b_to_top(t_ps *ps, int pos)
{
	int	size;

	if (!ps || !ps->b || pos < 0)
		return ;
	size = ps->b->size;
	if (size <= 1)
		return ;
	if (pos <= size / 2)
		while (pos-- > 0)
			do_op(ps, OP_RB);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			do_op(ps, OP_RRB);
	}
}