/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:12:19 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 12:26:02 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	a_to_b_100(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	*octile_tab;
	int	i;

	octile_tab = NULL;
	octile_tab = get_octile_tab(list_a, octile_tab);
	size = ft_lstsize(*list_a);
	i = 0;
	while (i <= 7)
	{
		while (size-- >= 0)
		{
			if ((*list_a)->nb <= octile_tab[i])
				push(list_a, list_b, "b", tmp_list);
			else
				rotate(list_a, "a", tmp_list);
		}
		size = ft_lstsize(*list_a);
		i++;
	}
	a_to_b_100_last_octile(list_a, list_b, tmp_list);
	free(octile_tab);
	return (0);
}

int	*get_octile_tab(t_nb **list_a, int *octile_tab)
{
	int	i;

	octile_tab = (int *)malloc(sizeof(int) * 7);
	if (!octile_tab)
		return (0);
	i = 0;
	while (i <= 7)
	{
		octile_tab[i] = get_octile(*list_a, i + 1);
		i++;
	}
	return (octile_tab);
}

int	a_to_b_100_last_octile(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;

	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		push(list_a, list_b, "b", tmp_list);
		rotate(list_a, "a", tmp_list);
	}
	return (0);
}
