#include "../includes/push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	is_all_spaces(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_int_token(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	stack_contains(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	handle_token(t_ps *ps, const char *tok)
{
	long	nb;
	t_node	*n;

	if (!is_valid_int_token(tok))
		error_exit(ps);

	nb = ft_atol(tok);
	if (nb < INT_MIN || nb > INT_MAX)
		error_exit(ps);

	if (stack_contains(ps->a, (int)nb))
		error_exit(ps);

	n = node_new((int)nb);
	if (!n)
		error_exit(ps);
	node_add_back(&ps->a, n);
}

void	parse_input(t_ps *ps, int argc, char **argv, int start_i)
{
	char	**tokens;
	int		i;

	if (!ps || start_i >= argc)
		error_exit(ps);

	if (argc - start_i == 1)
	{
		if (argv[start_i][0] == '\0' || is_all_spaces(argv[start_i]))
			error_exit(ps);

		tokens = ft_split(argv[start_i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			error_exit(ps);
		}
		i = 0;
		while (tokens[i])
			handle_token(ps, tokens[i++]);
		free_split(tokens);
		return ;
	}
	i = start_i;
	while (i < argc)
		handle_token(ps, argv[i++]);
}