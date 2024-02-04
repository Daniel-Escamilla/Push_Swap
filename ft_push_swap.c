/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:44:01 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 18:33:22 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '+' || num[i] == '-')
		i++;
	if (num[i] == '\0')
		ft_error();
	while (num[i] != '\0')
	{
		if (ft_isdigit(num[i]) == 0)
			ft_error();
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
			return (1);
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

void	ft_new_node_number(int number, t_list **stack_a)
{
	t_list	*new;

	if (ft_duplicates(number, stack_a) == 1)
		ft_error();
	new = ft_lstnew(number);
	ft_lstadd_back(stack_a, new);
}

void	ft_take_numbers(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**arr;
	long	number;

	i = 1;
	while (i != argc)
	{
		j = 0;
		arr = ft_split(argv[i], ' ');
		if (arr[j] == NULL)
			ft_error();
		while (arr[j] != NULL)
		{
			ft_check_number(arr[j]);
			number = ft_atol(arr[j]);
			if (number == (long) INT_MAX + 1)
				ft_error();
			ft_new_node_number(number, stack_a);
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
}
