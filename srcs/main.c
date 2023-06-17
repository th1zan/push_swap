/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:17:28 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 12:26:17 by thibault         ###   ########.fr       */
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

	list_a = NULL;
	list_b = NULL;
	tmp_list = malloc(sizeof(char));
	if (!tmp_list)
		return (0);
	tmp_list[0] = '\0';
	if (argc <= 1)
	{
		ft_putstr_fd("Nombre d'arguments insuffisant", 1);
		exit (0);
	}
	else if (argc == 1)
		return (ft_atoi(argv[1]));
	else
		list_a = argv_to_list(argc, argv);
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

int	check_duplicates(t_nb *list_a)
{
	t_nb	*current;
	t_nb	*temp;

	current = list_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->nb == temp->nb)
				return (-1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

t_nb	*argv_to_list(int argc, char **argv)
{
	t_nb	*head_list;
	int		i;

	i = 1;
	check_nbr(argv[i]);
	head_list = ft_lstnew(ft_atoi(argv[i]));
	i++;
	while (argc - i)
	{
		check_nbr(argv[i]);
		ft_lstadd_back(&head_list, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (head_list);
}

int	check_nbr(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Un élément de la liste n'est pas un nombre", 1);
			exit (0);
		}
		i++;
	}
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
