/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_get_minmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:59:43 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 11:18:23 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	get_max(t_nb **head_list)
{
	t_nb	*tmp;
	int		max_num;
	int		position;
	int		max_position;

	tmp = *head_list;
	max_num = tmp->nb;
	position = 1;
	max_position = 1;
	while (tmp != NULL)
	{
		if (tmp->nb > max_num)
		{
			max_num = tmp->nb;
			max_position = position;
		}
		tmp->index = position;
		tmp = tmp->next;
		position++;
	}
	return (max_position);
}

int	get_min(t_nb **head_list)
{
	t_nb	*tmp;
	int		min_num;
	int		position;
	int		min_position;

	tmp = *head_list;
	min_num = tmp->nb;
	position = 1;
	min_position = 1;
	while (tmp != NULL)
	{
		if (tmp->nb < min_num)
		{
			min_num = tmp->nb;
			min_position = position;
		}
		tmp->index = position;
		tmp = tmp->next;
		position++;
	}
	return (min_position);
}
