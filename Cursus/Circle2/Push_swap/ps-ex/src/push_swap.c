/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:51:31 by danicn            #+#    #+#             */
/*   Updated: 2022/10/20 19:32:23 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	int_free(void *num)
{
	free(num);
}

void	exit_stacks(int *n, t_list *l)
{
	if (l != NULL)
		ft_lstclear(&l, int_free);
	if (n != NULL)
		free(n);
	exit_error();
}

void	init_stacks(t_list **stack1, t_list **stack2, char **argv, int argc)
{
	int		*num;
	t_list	*list;

	num = (int *) malloc(sizeof(int));
	if (!num)
		exit_error();
	*num = ft_atoi(argv[argc - 1]);
	*stack1 = ft_lstnew(num);
	if (!*stack1)
		exit_stacks(num, NULL);
	*stack2 = NULL;
	argc--;
	while (--argc >= 1)
	{
		num = (int *) malloc(sizeof(int));
		if (num == NULL)
			exit_stacks(NULL, *stack1);
		*num = ft_atoi(argv[argc]);
		list = ft_lstnew(num);
		if (!list)
			exit_stacks(num, *stack1);
		ft_lstadd_back(stack1, list);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack1;
	t_list	*stack2;

	if (argc < 2 || argv[1] == NULL)
		return (1);
	args_err(argv);
	init_stacks(&stack1, &stack2, argv, argc);
	if (lst_isordered(stack1) == 0)
	{
		if (argc < 7)
			less_than_six(&stack1, &stack2, argc);
		else
			radix_sort(stack1, stack2);
	}
	ft_lstclear(&stack1, int_free);
	ft_lstclear(&stack2, int_free);
}
