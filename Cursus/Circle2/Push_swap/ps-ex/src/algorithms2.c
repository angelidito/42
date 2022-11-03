/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:17:02 by danicn            #+#    #+#             */
/*   Updated: 2022/10/20 19:49:35 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int arr[], int n)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	bucle_sort(t_list *lst, int size, int *arr)
{
	int	i;

	while (lst != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == *(int *)lst->content)
			{
				*(int *)lst->content = size - i - 1;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

t_list	*sort(t_list *lst)
{
	int		*arr;
	int		i;
	int		size;
	t_list	*l;

	size = ft_lstsize(lst);
	arr = (int *) malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	l = lst;
	while (i < size)
	{
		arr[i] = *(int *)lst->content;
		i++;
		lst = lst->next;
	}
	insertion_sort(arr, size);
	i = 0;
	bucle_sort(l, size, arr);
	free(arr);
	return (l);
}

int	lst_isordered(t_list *s1)
{
	while (s1->next != NULL)
	{
		if (*(int *)s1->content < *(int *)s1->next->content)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

void	radix_sort(t_list *s1, t_list *s2)
{
	t_list	*lst;
	int		size;
	int		i;
	int		j;

	if (lst_isordered(s1) == 0)
	{
		lst = sort(s1);
		size = ft_lstsize(lst);
		j = 1;
		while (lst_isordered(lst) == 0)
		{	
			i = 0;
			while (i < size && lst_isordered(lst) == 0)
			{
				if (*(int *)ft_lstlast(lst)->content & j)
					rotate_a(&lst);
				else
					push_b(&lst, &s2);
				i++;
			}
			minibucle(&lst, &s2, &j);
		}
	}
}
