/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:59:42 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 19:59:42 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_node
{
	int				*value;
	int				index;
	struct s_node	*next;

}	s_node;
typedef struct s_stack
{
	s_node	*top;
	int		size;
}	s_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_ps
{
	s_node		*a;
	s_node		*b;

	t_strategy	strategy;
	int			flag_bench;
	double		disorder;

	long		op_total;
	long		op_count[11];
}	t_ps;

//init
int	parse_flags(t_ps *ps, int argc, char **arg, int *start_i);
void	parse_input(t_ps *ps, int argc, char **argv, int start_i)
void	error_exit(t_ps *ps);

//list
s_node	*new_node(int value);
s_node	*last_node(s_node *stack);
int		lst_size(s_node *stack);
void	lst_add_back(s_node **stack, s_node *new_node);
void	lst_clear(s_node **stack);

//helpers
int		is_sorted(t_node *stack);
int		find_min_pos(t_node *stack);

//libft
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
