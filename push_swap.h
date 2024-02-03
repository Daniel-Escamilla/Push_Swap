/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:01:45 by descamil          #+#    #+#             */
/*   Updated: 2024/02/03 17:33:04 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

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

void	ft_error(void);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);

t_list	*ft_lstnew(int content);
void	ft_lstdelone(t_list *lst);
void	ft_lstprinter(t_list *stack);
void	ft_clear_stack(t_list **stack);
int		ft_lstordered(t_list **stack_a);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_check_number(char *num);
int		ft_duplicates(int number, t_list **stack_a);
void	ft_new_node_number(int number, t_list **stack_a);
void	ft_take_numbers(int argc, char **argv, t_list **stack_a);

int		ft_lstsize(t_list *lst);
int		ft_found_min(t_num *num, int size);
void	ft_force(t_list **stack, t_list **stack_b, t_num *num, int size);

void	ft_sethree(t_list **stack, t_num *num);
void	ft_setfour(t_list **stack, t_num *num);
void	ft_setfive(t_list **stack, t_num *num);

void	ft_swap(t_list	**stack, char *str);
void	ft_rotate(t_list **stack, char *str);
void	ft_rrotate(t_list **stack, char *str);
void	ft_push(t_list **stack1, t_list **stack2, char *str);

#endif