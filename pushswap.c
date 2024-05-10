#include "pushswap.h"

int main(int ac, char **av)
{
    int i;
    char *str;
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    str = " ";
    i = 1;
    if (ac < 2)
        return (1);
    while(av[i])
    {
        if((!av[i][0]) || checkdgts(av[i]) == -1)
        {
            if (i > 1)
                free(str);
            return (write(2, "Error\n", 6),1);
        }
        str = ft_strjoin(str,ft_strjoin(av[i]," "));
        i++;
    }
    if (checknumbers(str) == -1 || checkminmax(str) == -1 || checkdouble(str) == -1)
    {
        free(str);
        return (write(2, "Error\n", 6),1);
    }
    stack_a = stackinit(stack_a, str);
    if(check_order(stack_a) == -1)
    {
        if(ft_lstsize(stack_a) == 2)
            sa(stack_a);
        if(ft_lstsize(stack_a) == 3)
            sort_3(&stack_a);
        if(ft_lstsize(stack_a) > 3)
            turk_algo(&stack_a,&stack_b);
    }
    printf("-------a---------\n");
    while(stack_a)
    {
        printf("%d\n",stack_a->x);
        stack_a = stack_a->next;
    }
    printf("-------b---------\n");
    while(stack_b)
    {
        printf("%d\n",stack_b->x);
        stack_b = stack_b->next;
    }
    free(stack_a);
}
