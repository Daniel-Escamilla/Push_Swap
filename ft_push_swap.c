/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:44:01 by descamil          #+#    #+#             */
/*   Updated: 2024/02/02 17:53:44 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (1, "Error\n", 7);
	exit(1);
}

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

void ft_new_node_number(int number, t_list **stack_a)
{
	t_list	*new;
	
	if (ft_duplicates(number ,stack_a) == 1)	
		ft_error();
	new = ft_lstnew(number);
	ft_lstadd_back(stack_a, new);
}

void ft_take_numbers(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**arr;
	
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
			ft_new_node_number(ft_atol(arr[j]), stack_a);
			free(arr[j]);
			j++;
		}
		free(arr);
		i++;
	}
}

void	ft_lstprinter(t_list *stack)
{
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			printf("%d\n", stack->content);
			stack = stack->next;
		}
	}
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_error();
	ft_take_numbers(argc, argv, &stack_a);
	if (ft_lstordered(&stack_a) == 1)
		return (0);
	size = ft_lstsize(stack_a);
	ft_lstprinter(&(*stack_a));
	if (size > 1 && size < 6)
		ft_force(&stack_a, size);
	// else
	// 	ft_radix(&stack_a);
	// ft_rrotate(&stack_a, "rra\n");
	ft_lstprinter(&(*stack_a));
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}

// RA	= 4 5 7 2 NULL -> 5 7 2 4

// RRA	= 4 5 7 2 NULL -> 2 4 5 7
