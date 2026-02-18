#include "push_swap.h"

void    error_exit(t_ps *ps)
{
    write(2, "Error\n", 6);
    if (ps)
    {
        node_clear(&ps->a);
        node_clear(&ps->b);
    }
    exit(1);
}