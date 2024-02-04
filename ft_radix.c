/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:51:56 by descamil          #+#    #+#             */
/*   Updated: 2024/02/04 16:47:17 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_all(t_list **stack)
{
	t_list	*temp;
	t_list	*tempo;
	int		content;
	int		i;

	temp = *stack;
	while (temp != NULL)
	{
		tempo = *stack;
		i = 1;
		content = temp->content;
		while (tempo != NULL)
		{
			if (content > tempo->content)
				i++;
			tempo = tempo->next;
		}
		temp->index = i;
		temp = temp->next;
	}
}
int	ft_number_bits(int size)
{
	int	i;
	
	i = 0;
	while (size > 0)
	{
		size /= 2;
		i++;
	}
	return (i);
}

void	ft_bits(t_list **stack_a, t_list **stack_b, int size)
{
	int	bits;
	int	i;
	int	j;
	
	i = 0;
	bits = ft_number_bits(size);
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i & 1) == 1)
				ft_rotate(stack_a, "ra\n");
			else
				ft_push(stack_a, stack_b, "pb\n");
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_push(stack_b, stack_a, "pa\n");
		i++;
	}
}

void	ft_radix(t_list **stack_a, t_list **stack_b, int size)
{
	ft_index_all(stack_a);
	ft_bits(stack_a, stack_b, size);
}
