/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:10:41 by abakhcha          #+#    #+#             */
/*   Updated: 2024/05/13 14:06:53 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

void	splt_25line(char *str, t_list **stack_a, t_list **stack_b)
{
	if (checknumbers(str) == -1 || checkminmax(str) == -1
		|| checkdouble(str) == -1)
	{
		free(str);
		write(2, "Error\n", 6);
		exit(1);
	}
	*stack_a = stackinit(*stack_a, str);
	if (check_order(*stack_a) == -1)
	{
		if (ft_lstsize(*stack_a) == 2)
			sa(*stack_a);
		if (ft_lstsize(*stack_a) == 3)
			sort_3(stack_a);
		if (ft_lstsize(*stack_a) > 3)
			turk_algo(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	str = NULL;
	i = 1;
	if (ac < 2)
		return (1);
	while (av[i])
	{
		if ((!av[i][0]) || checkdgts(av[i]) == -1)
		{
			if (i > 1)
				free(str);
			return (write(2, "Error\n", 6), 1);
		}
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	splt_25line(str, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	system("leaks push_swap");
}
