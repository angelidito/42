/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:03:48 by danicn            #+#    #+#             */
/*   Updated: 2022/10/20 19:47:31 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	init_stacks(t_list **stack1, t_list **stack2, char **argv, int argc);
void	swap_a(t_list **list);
void	int_free(void *num);
void	swap_b(t_list **list);
void	swap_ab(t_list **list, t_list **list2);
void	swap(t_list **list);
void	push_a(t_list **s1, t_list **s2);
void	push_b(t_list **s1, t_list **s2);
void	rotate_a(t_list **s1);
void	rotate_b(t_list **s1);
void	rotate(t_list **s1);
void	rotate_rr(t_list **s1, t_list **s2);
void	rrotate_a(t_list **s1);
void	rrotate_b(t_list **s1);
void	rrotate_rr(t_list **s1, t_list **s2);
void	rrotate_a(t_list **s1);
void	rrotate_(t_list **s1);
void	less_than_six(t_list **s1, t_list **s2, int argc);
void	three_nums(t_list **s1);
void	four_nums(t_list **s1, t_list **s2);
void	five_nums(t_list **s1, t_list **s2);
void	radix_sort(t_list *s1, t_list *s2);
int		lst_isordered(t_list *s1);
void	insertion_sort(int arr[], int n);
void	args_err(char **argv);
void	limits(char *arg);
void	equal_number(char **argv, int i);
int		ft_strcmp(char *s1, char *s2);
long	ft_atol(const char *s);
void	exit_error(void);
void	minibucle(t_list **lst, t_list **s2, int *j);

#endif