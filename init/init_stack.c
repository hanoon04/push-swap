#include "../includes/push_swap.h"

void	init_stack(t_ps *ps)
{
	int	i;

	ps->a = NULL;
	ps->b = NULL;
	ps->strategy = STRAT_ADAPTIVE;
	ps->flag_bench = 0;
	ps->disorder = 0.0;
	ps->op_total = 0;
	i = 0;
	while (i < 11)
		ps->op_count[i++] = 0;
}