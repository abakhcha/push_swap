#include "pushswap.h"

void ss(t_list *a,t_list *b)
{
    sa(a);
    sb(b);
}

void rr(t_list **a,t_list **b)
{
    if(*b == NULL || *a == NULL)
        return;
    ra(a);
    rb(b);
}
void rrr(t_list **a,t_list **b)
{
    if(*b == NULL || *a == NULL)
        return;
    rra(a);
    rrb(b);
}