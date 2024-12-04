/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcoded2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:03:02 by descamil          #+#    #+#             */
/*   Updated: 2024/12/04 10:44:27 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sethree(t_list **stack, t_num *num)
{
	t_list	*current;

	current = *stack;
	num->first = current->content;
	num->second = current->next->content;
	num->third = current->next->next->content;
	num->fourth = 0;
	num->fifth = 0;
}

void	ft_setfour(t_list **stack, t_num *num)
{
	t_list	*current;

	current = *stack;
	ft_sethree(&current, num);
	num->fourth = current->next->next->next->content;
}

void	ft_setfive(t_list **stack, t_num *num)
{
	t_list	*current;

	current = *stack;
	ft_setfour(&current, num);
	num->fifth = current->next->next->next->next->content;
}
