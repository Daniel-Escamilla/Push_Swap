/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:55:24 by descamil          #+#    #+#             */
/*   Updated: 2024/02/02 17:35:35 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	**stack, char *str)
{
	t_list	*current;
	int		temp;
	
	current = *stack;
	if (current == NULL)
		return ;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	write(1, str, 3);
}

void	ft_push(t_list **stack1, t_list **stack2, char *str)
{
	t_list	*current;
	
	if (*stack1 == NULL)
		return ;
	current = *stack1;
	*stack1 = (*stack1)->next;
	current->next = *stack2;
	*stack2 = current;
	write(1, str, 3);
}

void	ft_rotate(t_list **stack,  char *str)
{
	t_list	*current;
	int		temp;
	
	current = *stack;
	if (current == NULL)
		return ;
	temp = current->content;
	while (current->next != NULL)
	{
		current->content = current->next->content;
		current = current->next;
	}
	current->content = temp;
	write(1, str, 3);
}

void	ft_rrotate(t_list **stack,  char *str)
{
	t_list	*current;
	t_list	*start;
	
	current = *stack;
	if (current == NULL)
		return ;
	start = NULL;
	while (current->next != NULL)
	{
		start = current;
		current = current->next;	
	}
	current->next = *stack;
	*stack = current;
	start->next = NULL;
	write(1, str, 4);
}

// void	ft_swap(t_list	**stack, char *str)
// {
// 	t_list	*current;
// 	int		temp;
	
// 	current = *stack;
// 	if (current == NULL)
// 		return ;
// 	temp = current->content;
// 	current->content = current->next->content;
// 	current->next->content = temp;
// 	write(1, str, 3);
// }

			// ^^ RRA o RRB ^^ //

// void	ft_sb()
// {
	
// }

// 3 --> current->content
// 1 --> temp2
// 2 -->

// temp2 = current->next->content
// current->next->content = current->content


// void	ft_ss()
// {
	
// }
// void	ft_pb()
// {
	
// void	ft_rb()
// {
	
// }

// void	ft_rr()
// {
	
// }
// }
// void	ft_rrb()
// {
	
// }

// void	ft_rrr()
// {
	
// }