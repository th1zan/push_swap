/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:17:28 by thibault          #+#    #+#             */
/*   Updated: 2023/05/18 17:38:39 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	main(int argc, char **argv)
{
	t_nb	*head_list_init;
	
	head_list_init = NULL;
	if (argc <= 1)
	{
		ft_putstr_fd("Nombre d'arguments insuffisant", 1);
		exit (0);
	}
	else if (argc == 1)
		return(ft_atoi(argv[1]));
	else
	{
		head_list_init = argv_to_list(argc, argv);
	}
	// print_list(head_list_a);
	head_list_init = quick_sort(head_list_init);
	print_list(head_list_init);
	free_list(head_list_init);
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
		return (-1);
	tmp = head_list;
	free(tmp->prev);
	while (head_list != 0)
	{
		// printf("nb = %d, pt = %p, prev = %p, next = %p\n", head_list->nb, head_list, head_list->prev, head_list->next);
		tmp = tmp->next;
		free(head_list);
		head_list = tmp;	
	}
	return (0);
}
