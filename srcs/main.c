/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:17:28 by thibault          #+#    #+#             */
/*   Updated: 2023/06/22 22:39:09 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	main(int argc, char **argv)
{
	t_nb	*list_a;
	t_nb	*list_b;
	char	*tmp_list;
	int		new_argc;
	char	**new_argv;

	list_a = NULL;
	list_b = NULL;
	new_argc = argc;
	new_argv = argv;
	tmp_list = malloc(sizeof(char));
	if (!tmp_list)
		return (0);
	tmp_list[0] = '\0';
	list_a = get_arg(new_argc, new_argv, list_a);
	sort(&list_a, &list_b, &tmp_list);
	ft_printf("%s", tmp_list);
	free (tmp_list);
	free_list(list_a);
	return (0);
}

/*
	print_list(list_a);
	print_list(list_b);
	ft_printf("\n nb_op: %d\n", nb_op(tmp_list));
*/

t_nb	*get_arg(int new_argc, char **new_argv, t_nb *list_a)
{
	int	free_tab;

	free_tab = 0;
	if (new_argc <= 1)
		return (0);
	if (new_argc == 2)
	{
		new_argv = analyze_argv(new_argv);
		new_argc = count_argc(new_argv);
		free_tab = 1;
	}
	list_a = argv_to_list(new_argc, new_argv);
	if (free_tab)
		free_new_argv(new_argv, new_argc);
	return (list_a);
}

int	free_new_argv(char **new_argv, int new_argc)
{
	int	i;

	i = 0;
	while (i < new_argc)
		free(new_argv[i++]);
	free(new_argv);
	return (0);
}

int	free_list(t_nb *head_list)
{
	t_nb	*tmp;

	if (!head_list)
		return (-1);
	tmp = head_list;
	free(tmp->prev);
	while (head_list != 0)
	{
		tmp = tmp->next;
		free(head_list);
		head_list = tmp;
	}
	return (0);
}
