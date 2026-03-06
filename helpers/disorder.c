#include "../includes/push_swap.h"

static long	count_inversions(t_node *head)
{
	t_node	*i;
	t_node	*j;
	long	inv;

	inv = 0;
	i = head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inv++;
			j = j->next;
		}
		i = i->next;
	}
	return (inv);
}

static long	total_pairs(int n)
{
	return ((long)n * (long)(n - 1) / 2);
}

double	calc_disorder(t_stack *a)
{
	long	inv;
	long	pairs;

	if (!a || !a->top || a->size < 2)
		return (0.0);
	pairs = total_pairs(a->size);
	if (pairs == 0)
		return (0.0);
	inv = count_inversions(a->top);
	return ((double)inv / (double)pairs);
}