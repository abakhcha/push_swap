#include "pushswap.h"

t_list *find_target(int y, t_list *a)
{
    int sign;
    t_list *a2;
    t_list *target;

    target = NULL;
    sign = 1;
    a2 = a;
    while(a != NULL)
    {
        if(a->x > y)
        {
            target = a;
            sign *= -1;
            break;
        }
        a = a->next;
    }
    while (a != NULL)
    {
        if(a->x > y)
            if(a->x < target->x)
                target = a;
        a = a->next;
    }
    if(sign == 1)
        target = lst_min(a2);
    return (target);
}
void push_except3(t_list **a, t_list **b)
{
    int size = ft_lstsize(*a);
    while(size > 3)
    {
        pb(a, b);
        size = ft_lstsize(*a);
    }
    if(check_order(*a) == -1)
        sort_3(a);
}

void fill_stacks(t_list *b, t_list *a)
{
    int size = ft_lstsize(b);
    int i = 0;
    t_list *tmp = b;
    while (tmp)
    {
       tmp->position = i;
        tmp->target_node = find_target(tmp->x,a);
        if (i > (size / 2))
        {
            tmp->position = size - tmp->position;
            tmp->up = 0;
        }
        else
            tmp->up = 1;
        tmp = tmp->next;
        i++;
    }
    fill_positiona(a);
    fill_swap_cost(b);
}

void    fill_swap_cost(t_list *b)
{
 
    while(b)
    {
        (b)->push_cost = (b)->position + (b)->target_node->position;
        (b) = (b)->next;
    }
}

void fill_positiona(t_list *a)
{
    int size = ft_lstsize(a);
    int i = 0;
    while (a)
    {
        a->position = i;
        if (i > (size / 2))
        {
            a->position = size - a->position;
            a->up = 0;
        }
        else
            a->up = 1;
        a = a->next;
        i++;
    }
}
int smallest_pushcost(t_list *b)
{
    int small;

    small = b->push_cost;
    while(b && b->next)
    {
        if (small > b->push_cost)
            small = b->push_cost;
        b = b->next;
    }
    return (small);
}

void push_to_a(t_list **a, t_list **b)
{
    int smaller;
    t_list *tmp;

    tmp = *b;
    smaller = smallest_pushcost(*b);
    while (tmp)
    {
        if (tmp->push_cost == smaller)
            break;
        tmp = tmp->next;
    }
    while ((tmp->target_node->up = 1 && tmp->up == 1) && (tmp->position != 0 && tmp->target_node->position != 0))
        rr(a, b);
    while ((tmp->target_node->up = 0 && tmp->up == 0) && (tmp->position != 0 && tmp->target_node->position != 0))
        rrr(a, b);

    while (tmp->position != 0 && tmp->up == 1)
        rb(b);
    while (tmp->position != 0 && tmp->up == 0)
        rrb(b);
    while (tmp->target_node->position != 0 && tmp->target_node->up == 1)
        ra(a);
    while (tmp->target_node->position != 0 && tmp->target_node->up == 0)
        rra(a);
}