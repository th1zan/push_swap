/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_argv_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:58:35 by thibault          #+#    #+#             */
/*   Updated: 2023/06/22 22:39:29 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

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
