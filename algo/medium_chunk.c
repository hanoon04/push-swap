#include "../includes/push_swap.h"

static int	int_sqrt(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}

static void	push_chunks(t_ps *ps)
{
	int	n;
	int	chunk_count;
	int	chunk_size;
	int	limit;
	int	pushed;

	n =  ps->a->size;
	chunk_count = int_sqrt(n);
	if (chunk_count < 1)
		chunk_count = 1;
	chunk_size = n / chunk_count;
	if (chunk_size < 1)
		chunk_size = 1;
	limit = chunk_size - 1;
	pushed = 0;
	while (pushed < n)
	{
		if (ps->a->top->index <= limit)
		{
			do_op(ps, OP_PB);
			pushed++;
			if (ps->b->top && ps->b->top->index < limit - (chunk_size / 2))
				do_op(ps, OP_RB);
			if (pushed > limit)
				limit += chunk_size;
			if (limit >= n)
				limit = n - 1;
		}
		else
			do_op(ps, OP_RA);
	}
}

static void	rebuild_a(t_ps *ps)
{
	int	pos;

	while (ps->b->size > 0)
	{
		pos = find_max_pos_index(ps->b);
		rotate_b_to_top(ps, pos);
		do_op(ps, OP_PA);
	}
}

void	medium_sort(t_ps *ps)
{
	if (!ps || !ps->a || ps->a->size < 2)
		return ;
	push_chunks(ps);
	rebuild_a(ps);
}