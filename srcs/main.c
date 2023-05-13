/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:17:28 by thibault          #+#    #+#             */
/*   Updated: 2023/05/13 15:15:25 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int print_list(t_nb *list_pt)
{
	if (!list_pt)
		return (0);
	while (list_pt != 0)
	{
		ft_putnbr_fd(list_pt->nb, 1);
		ft_putstr_fd("\n", 1);
		list_pt = list_pt->next;
	}	
	return (0);
}

int	main(int argc, char **argv)
{
	t_nb	*head_list;
	
	head_list = NULL;
	if (argc <= 1)
	{
		ft_putstr_fd("Nombre d'arguments insuffisant", 1);
		exit (0);
	}
	else
	{
		head_list = argv_to_list(argc, argv);
	}
	print_list(head_list);
	// sort_list(head_list);
	// print_sorted_list(head_list);
	
	
	free_list(head_list);
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
	while(argc - i)
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
		// printf("%c\n", str[i]);
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Un élément de la liste n'est pas un nombre", 1);
			exit (0);
		}
		i++;
	}
	return (0);
}

int free_list(t_nb *head_list)
{
	t_nb    *tmp;
	
	if (!head_list)
		return (0);
	tmp = head_list;
	while (head_list != 0)
	{
		// printf("nb = %d, pt = %p, next = %p\n", head_list->nb, head_list, head_list->next);
		tmp = tmp->next;
		free(head_list);
		head_list = tmp;	
	}	
	return (0);
}
