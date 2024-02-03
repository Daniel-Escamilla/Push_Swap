/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcoded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:29:59 by descamil          #+#    #+#             */
/*   Updated: 2024/02/02 17:55:14 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_three(t_list **stack)
{
	t_list	*current;
	int		first;
	int		second;
	int		third;

	current = *stack;
	first = current->content;
	second = current->next->content;
	third = current->next->next->content;
	if (first > second && first > third)
	{	
		ft_rotate(&current, "ra\n");
		if (second > third)
			ft_swap(&current, "sa\n");
	}
	else if (first < second && second > third && first < third)
	{	
		ft_swap(&current, "sa\n");
		ft_rotate(&current, "ra\n");
	}
	else if (first < second && second > third && first > third)
	{
		ft_rotate(&current, "ra\n");
		ft_rotate(&current, "ra\n");
	}
	else if (first > second && second < third)
		ft_swap(&current, "sa\n");
}

void	ft_force(t_list **stack, int size)
{
	t_list	*current;

	current = *stack;
	if (size == 2)
		ft_swap(&current, "sa\n");
	else if (size == 3)
		ft_three(&current);
	// else if (size == 4)
	// {
	// 	ft_found_min(&stack);
	// 	ft_tree(&stack);
	// }
	// else if (size == 5)
	// {
	// 	ft_found_min(&stack);
	// 	ft_found_min(&stack);
	// 	ft_tree(&stack);
	// }	
		
}

