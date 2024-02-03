/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:50:13 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 16:59:08 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear_stack(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_lstdelone(t_list *lst)
{
	if (lst != NULL)
		free(lst);
}
