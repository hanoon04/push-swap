#include "push_swap.h"

static void	pb_silent(t_stack *a, t_stack *b) { push(a, b); }
static void	pa_silent(t_stack *a, t_stack *b) { push(b, a); }

void	do_op(t_ps *ps, t_op op)
{
	if (!ps || !ps->a || !ps->b)
		return ;

	if (ps->flag_bench)
	{
		if (op == OP_SA) swap(ps->a);
		else if (op == OP_SB) swap(ps->b);
		else if (op == OP_SS) { swap(ps->a); swap(ps->b); }
		else if (op == OP_PA) pa_silent(ps->a, ps->b);
		else if (op == OP_PB) pb_silent(ps->a, ps->b);
		else if (op == OP_RA) rotate(ps->a);
		else if (op == OP_RB) rotate(ps->b);
		else if (op == OP_RR) { rotate(ps->a); rotate(ps->b); }
		else if (op == OP_RRA) rev_rotate(ps->a);
		else if (op == OP_RRB) rev_rotate(ps->b);
		else if (op == OP_RRR) { rev_rotate(ps->a); rev_rotate(ps->b); }
	}
	else
	{
		if (op == OP_SA) swap_printer(ps->a, 'a');
		else if (op == OP_SB) swap_printer(ps->b, 'b');
		else if (op == OP_SS) ss(ps->a, ps->b);
		else if (op == OP_PA) pa(ps->a, ps->b);
		else if (op == OP_PB) pb(ps->a, ps->b);
		else if (op == OP_RA) rotate_printer(ps->a, 'a');
		else if (op == OP_RB) rotate_printer(ps->b, 'b');
		else if (op == OP_RR) rr(ps->a, ps->b);
		else if (op == OP_RRA) rev_rotate_printer(ps->a, 'a');
		else if (op == OP_RRB) rev_rotate_printer(ps->b, 'b');
		else if (op == OP_RRR) rrr(ps->a, ps->b);
	}

	ps->op_total++;
	if ((int)op >= 0 && (int)op < 11)
		ps->op_count[op]++;
}
