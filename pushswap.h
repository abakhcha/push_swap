#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INTMAX 2147483647 
#define INTMIN -2147483648 
typedef struct lst
{
    int x;
    int up;
    int position;
    int push_cost;
    struct lst *target_node;
    struct lst *next;
} t_list;

char	*ft_strjoin(char const *s1, char const *s2);
int checknumbers(char *str);
char	**ft_split(char  *s, char c);
t_list *stackinit(t_list *stack_a, char *str);
long long	ft_atoi(char *str);
int ft_strlen(const char *str);
char	*ft_strneww(size_t n);
int checkminmax(char *str);
int checkdouble(char *str);
void	free_arrayy(char **array);
void sa(t_list *stack_a);
void ra(t_list **stack_a);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void rra(t_list **stack_a);
int checkdgts(char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstbfrlast(t_list *lst);
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void pb(t_list **a, t_list **b);
void pa(t_list **b, t_list **a);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rr(t_list **a,t_list **b);
void rrr(t_list **a,t_list **b);
void ss(t_list *a,t_list *b);
int check_order(t_list *stack);
void sort_3(t_list **lst);
int	ft_lstsize(t_list *lst);
t_list *find_target(int y, t_list *a);
int lst_max(t_list *lst);
int find_bigsmaller(int y, t_list *a);
t_list  *lst_min(t_list *lst);
void fill_stacks(t_list *b, t_list *a);
void fill_positiona(t_list *a);
void push_except3(t_list **a, t_list **b);
void    fill_swap_cost(t_list *b);
void push_to_a(t_list **a, t_list **b);

#endif