/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:51:56 by descamil          #+#    #+#             */
/*   Updated: 2024/02/04 12:52:12 by descamil         ###   ########.fr       */
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

void	ft_radix(t_list **stack_a, t_list **stack_b, int size)
{
	ft_lstprinter(*stack_a);
	ft_lstprinter(*stack_b);
	printf("SIZE	=	%d\n", size);
	ft_index_all(stack_a);
	printf("1º = %d\n", (*stack_a)->index);
	printf("2º = %d\n", (*stack_a)->next->index);
	printf("3º = %d\n", (*stack_a)->next->next->index);
	printf("4º = %d\n", (*stack_a)->next->next->next->index);
	printf("5º = %d\n", (*stack_a)->next->next->next->next->index);
	printf("6º = %d\n", (*stack_a)->next->next->next->next->next->index);
}
