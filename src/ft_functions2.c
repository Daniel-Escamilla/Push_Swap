/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:50:13 by descamil          #+#    #+#             */
/*   Updated: 2024/12/04 11:52:34 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clear_stack(t_list **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

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

void	ft_free_split(char **num)
{
	int	j;

	j = 0;
	while (num[j])
		free(num[j++]);
	free(num);
}
