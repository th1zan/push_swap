/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:18:03 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/11 18:26:50 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char(char **new_argv, int new_argc)
{
	int	k;

	k = 0;
	while (k < new_argc)
		free(new_argv[k++]);
	free(new_argv);
}

void	free_piles(t_list *pile_a)
{
	t_list	*temp;

	while (pile_a)
	{
		temp = pile_a;
		pile_a = temp->next;
		free(temp);
	}
}

static	void	s_m_b(t_list *pile_a, t_list *pile_b, int ac, char **av)
{
	if (ft_lstsize(pile_a) <= 10)
		sm_sort_max_10(&pile_a, &pile_b, MIN_TO_MAX);
	else if (ft_lstsize(pile_a) <= 100)
	{
		sort_pile_k(pile_a, ac, av);
		middle_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
	else
	{
		sort_pile_k(pile_a, ac, av);
		big_sort(&pile_a, &pile_b);
		small_sort(&pile_a, &pile_b, MIN_TO_MAX);
		small_sort_r(&pile_a, &pile_b, MAX_TO_MIN);
	}
	free_piles(pile_a);
	free_piles(pile_b);
}

static	int	createpile_minisort(int new_argc, char **new_argv)
{
	t_list	*pile_b;
	t_list	*pile_a;

	pile_b = NULL;
	pile_a = create_pile(new_argc, new_argv);
	if (!already_sorted(pile_a))
	{
		free_piles(pile_a);
		return (0);
	}
	if (ft_lstsize(pile_a) <= 2)
	{
		if (pile_a->content > pile_a->next->content)
		{
			write(1, "sa\n", 3);
			free_piles(pile_a);
			return (1);
		}
	}
	s_m_b(pile_a, pile_b, new_argc, new_argv);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**new_argv;
	int		new_argc;

	if (argc <= 1)
		return (0);
	new_argv = argv;
	new_argc = argc;
	if (argc == 2)
	{
		new_argv = input_as_str(argv);
		new_argc = n_of_n(new_argv);
	}
	if (!err_input_checker(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	createpile_minisort(new_argc, new_argv);
	if (argc == 2)
		free_char(new_argv, new_argc);
	return (0);
}
