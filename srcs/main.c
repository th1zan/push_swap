/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:17:28 by thibault          #+#    #+#             */
/*   Updated: 2023/06/22 19:43:36 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	free_new_argv(char **new_argv, int new_argc)
{
	int	i;

	i = 0;
	while (i < new_argc)
		free(new_argv[i++]);
	free(new_argv);
	return (0);
}

char	**analyze_argv(char **argv)
{
	char	**tab_str_nb;
	char	*prog_name;

	prog_name = ft_strjoin("./push_swap ", argv[1]);
	if (prog_name == NULL)
		return (NULL);
	tab_str_nb = ft_split(prog_name, ' ');
	free(prog_name);
	if (tab_str_nb == NULL)
		return (NULL);
	return (tab_str_nb);
}

int	count_argc(char **new_argv)
{
	int	i;
	int	j;

	j = 0;
	while (new_argv[j] != NULL)
	{
		i = 0;
		while (new_argv[i])
			i++;
		j++;
	}
	return (j);
}

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
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		new_argv = analyze_argv(argv);
		new_argc = count_argc(new_argv);
	}
	list_a = argv_to_list(new_argc, new_argv);
	
	if (argc == 2)
		free_new_argv(new_argv, new_argc);
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

t_nb	*argv_to_list(int argc, char **argv)
{
	t_nb	*head_list;
	int		i;

	i = 1;
	if (check_nbr(argv[i]) < 0 || check_int(argv[i]) < 0)
		exit(0);
	head_list = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (argc - i)
	{
		if (check_nbr(argv[i]) < 0 || check_int(argv[i]) < 0)
			exit(0);
		ft_lstadd_back(&head_list, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (head_list);
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
