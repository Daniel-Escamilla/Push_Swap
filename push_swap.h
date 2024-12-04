/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:01:45 by descamil          #+#    #+#             */
/*   Updated: 2024/12/04 11:56:51 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_num
{
	int		first;
	int		second;
	int		third;
	int		fourth;
	int		fifth;
}			t_num;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

// ft_functions.c
int		ft_isdigit(int c);
void	ft_exit(t_list **stack_a, char **arr);
t_list	*ft_lstnew(int content);
long	ft_atol(const char *str);
int		ft_lstordered(t_list **stack_a);

// ft_functions2.c
int		ft_lstsize(t_list *lst);
void	ft_free_split(char **num);
void	ft_clear_stack(t_list **stack);

// ft_harcoded.c
int		ft_found_min(t_num *num, int size);
void	ft_force(t_list **stack_a, t_list **stack_b, t_num *num, int size);

// ft_harcoded2.c
void	ft_sethree(t_list **stack, t_num *num);
void	ft_setfour(t_list **stack, t_num *num);
void	ft_setfive(t_list **stack, t_num *num);

// ft_main.c
void	ft_error(void);
int		main(int argc, char **argv);

// ft_moves.c
void	ft_swap(t_list	**stack, char *str);
void	ft_rotate(t_list **stack, char *str);
void	ft_rrotate(t_list **stack, char *str);
void	ft_push(t_list **stack_a, t_list **stack_b, char *str);

// ft_push_swap.c
void	ft_check_number(t_list *stack_a, char ***num, int j);
int		ft_duplicates(int number, t_list **stack_a);
void	ft_lstadd_back(t_list **stack_a, t_list *new);
int		ft_new_node_number(int number, t_list **stack_a);
void	ft_take_numbers(int argc, char **argv, t_list **stack_a);

//ft_radix.c
void	ft_radix(t_list **stack_a, t_list **stack_b, int size);

// ft_split.c
char	**ft_split(const char *s, char c);

#endif