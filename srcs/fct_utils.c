/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:00:26 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 11:19:10 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	print_list(t_nb *list_pt)
{
	if (!list_pt)
	{
		ft_putstr_fd("liste vide\n", 1);
		return (0);
	}
	ft_putstr_fd("\n", 1);
	while (list_pt != 0)
	{
		ft_putnbr_fd(list_pt->nb, 1);
		ft_putstr_fd(", p =", 1);
		ft_putnbr_fd(list_pt->pivot, 1);
		ft_putstr_fd("\n", 1);
		list_pt = list_pt->next;
	}
	ft_putstr_fd("\n", 1);
	return (0);
}

int	nb_op(char *tmp_list)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (tmp_list[i])
	{
		if (tmp_list[i] == '\n')
			result++;
		i++;
	}
	return (result);
}
