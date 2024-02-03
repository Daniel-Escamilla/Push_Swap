/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcoded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:29:59 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 17:04:22 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_min(t_num *num, int size)
{
	int		temp;
	int		winner;

	temp = num->first;
	winner = 1;
	if (temp > num->second)
	{
		temp = num->second;
		winner = 2;
	}
	if (temp > num->third)
	{
		temp = num->third;
		winner = 3;
	}
	if (temp > num->fourth)
	{
		temp = num->fourth;
		winner = 4;
	}
	if (size == 5)
	{
		if (temp > num->fifth)
		{
			temp = num->fifth;
			winner = 5;
		}
	}
	return (winner);
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

void	ft_three(t_list **stack_a, t_list **stack_b, t_num *num, int size)
{
	ft_sethree(stack_a, num);
	if (num->first > num->second && num->first > num->third)
	{
		ft_rotate(stack_a, "ra\n");
		if (num->second > num->third)
			ft_swap(stack_a, "sa\n");
	}
	else if (num->first < num->second && num->second > num->third)
	{
		ft_rrotate(stack_a, "rra\n");
		if (num->first < num->third)
			ft_swap(stack_a, "sa\n");
	}
	else if (num->first > num->second && num->second < num->third)
		ft_swap(stack_a, "sa\n");
	if (size >= 3)
	{
		ft_push(stack_b, stack_a, "pa\n");
		if (size == 4)
			ft_push(stack_b, stack_a, "pa\n");
	}
}

void	ft_move(t_list **stack_a, t_list **stack_b, int winner, int size)
{
	if (winner == 2)
		ft_swap(stack_a, "sa\n");
	else if (winner == 3)
	{
		ft_rotate(stack_a, "ra\n");
		ft_rotate(stack_a, "ra\n");
	}
	else if (winner == 4 && size == 4)
		ft_rrotate(stack_a, "rra\n");
	else if (winner == 4 && size == 5)
	{
		ft_rrotate(stack_a, "rra\n");
		ft_rrotate(stack_a, "rra\n");
	}
	else if (winner == 5)
		ft_rrotate(stack_a, "rra\n");
	ft_push(stack_a, stack_b, "pb\n");
}

void	ft_force(t_list **stack_a, t_list **stack_b, t_num *num, int size)
{
	int		winner;

	if (size == 2)
		ft_swap(stack_a, "sa\n");
	else if (size == 3)
		ft_three(stack_a, stack_b, num, size);
	else if (size == 4)
	{
		ft_setfour(stack_a, num);
		winner = ft_found_min(num, size);
		ft_move(stack_a, stack_b, winner, size);
		ft_three(stack_a, stack_b, num, size);
	}
	else if (size == 5)
	{
		ft_setfive(stack_a, num);
		winner = ft_found_min(num, size);
		ft_move(stack_a, stack_b, winner, size--);
		ft_setfour(stack_a, num);
		winner = ft_found_min(num, size);
		ft_move(stack_a, stack_b, winner, size);
		ft_three(stack_a, stack_b, num, size);
	}
}
