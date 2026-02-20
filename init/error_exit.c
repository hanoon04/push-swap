#include "../includes/push_swap.h"

void	error_exit(t_ps *ps)
{
	write(2, "Error\n", 6);
	free_all(ps);
	exit(1);
}