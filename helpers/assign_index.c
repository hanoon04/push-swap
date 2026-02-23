#include "../includes/push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	*stack_to_array(t_node *a, int n, t_ps *ps)
{
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * n);
	if (!arr)
		error_exit(ps);
	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (arr);
}

static int	find_index_in_sorted(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index(t_ps *ps)
{
	int		n;
	int		*arr;
	t_node	*cur;

	if (!ps || !ps->a)
		return ;
	n = node_size(ps->a);
	arr = stack_to_array(ps->a, n, ps);
	sort_int_array(arr, n);
	cur = ps->a;
	while (cur)
	{
		cur->index = find_index_in_sorted(arr, n, cur->value);
		cur = cur->next;
	}
	free(arr);
}
