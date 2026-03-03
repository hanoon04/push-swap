#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		start_i;

	init_stack(&ps);
	if (argc == 1)
		return (0);
	if (!parse_flags(&ps, argc, argv, &start_i))
		error_exit(&ps);
	parse_input(&ps, argc, argv, start_i);
	if (is_sorted(ps.a))
	{
		free_all(&ps);
		return (0);
	}
	assign_index(&ps);
	if (ps.strategy == STRAT_MEDIUM)
		medium_sort(&ps);
	else if (ps.strategy == STRAT_SIMPLE)
		simple_sort(&ps);
	else if (ps.strategy == STRAT_COMPLEX)
		complex_sort(&ps);
	else
		adaptive_sort(&ps);
	if (ps.flag_bench)
		print_bench(&ps);
	free_all(&ps);
	return (0);
}