#include "pushswap.h"

int check_order(t_list *stack)
{
    while(stack->next != NULL)
    {
        if(stack->x > stack->next->x)
            return (-1);
        stack = stack->next;
    }
    return (1);
}

int lst_max(t_list *lst)
{
    int max;

    max = lst->x;
    while(lst->next != NULL)
    {
        if(max < lst->next->x)
            max = lst->next->x;
        lst = lst->next;
    }
    return (max);
}

void sort_3(t_list **lst)
{
    int max;

    max = lst_max(*lst);
    if (max == ft_lstlast(*lst)->x)
        sa(*lst);
    else 
    {
        if (max == (*lst)->x)
            ra(lst);
        else
            rra(lst);
        if (check_order(*lst) == -1)
            sa(*lst);
    }
}