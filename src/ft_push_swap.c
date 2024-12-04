/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:44:01 by descamil          #+#    #+#             */
/*   Updated: 2024/12/04 12:13:12 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_number(t_list *stack_a, char ***num, int j)
{
	int		i;

	i = 0;
	if ((*num)[j][i] == '+' || (*num)[j][i] == '-')
		i++;
	if ((*num)[j][i] == '\0')
		ft_exit(&stack_a, *num);
	while ((*num)[j][i] != '\0')
	{
		if (ft_isdigit((*num)[j][i]) == 0)
			ft_exit(&stack_a, *num);
		i++;
	}
}

int	ft_duplicates(int number, t_list **stack_a)
{
	t_list	*current;

	if (stack_a == NULL)
		current = NULL;
	else
		current = *stack_a;
	while (current != NULL)
	{
		if (current->content == number)
		{
			ft_clear_stack(stack_a);
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **stack_a, t_list *new)
{
	t_list	*current_list;

	current_list = *stack_a;
	if (current_list == NULL)
	{
		*stack_a = new;
		return ;
	}
	while (current_list->next != NULL)
		current_list = current_list->next;
	current_list->next = new;
}

int	ft_new_node_number(int number, t_list **stack_a)
{
	t_list	*new;

	if (ft_duplicates(number, stack_a) == 1)
		return (1);
	new = ft_lstnew(number);
	ft_lstadd_back(stack_a, new);
	return (0);
}

void	ft_take_numbers(int argc, char **argv, t_list **stack_a)
{
	long	number;
	char	**arr;
	int		i;
	int		j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr == NULL || arr[0] == NULL)
			ft_exit(stack_a, arr);
		while (arr[j] != NULL)
		{
			ft_check_number((*stack_a), &arr, j);
			number = ft_atol(arr[j]);
			if (number == (long) INT_MAX + 1)
				ft_exit(stack_a, arr);
			if (ft_new_node_number((int) number, stack_a) == 1)
				ft_exit(stack_a, arr);
			j++;
		}
		ft_free_split(arr);
	}
}
