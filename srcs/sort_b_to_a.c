/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:15:49 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 11:16:21 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	rotate_b_to_a(t_nb **list_b, char **tmp_list, int position)
{
	position--;
	while (position--)
		rotate(list_b, "b", tmp_list);
	return (position);
}

int	r_rotate_b_to_a(t_nb **list_b, char **tmp_list, int size, int position)
{
	position = size - position + 1;
	while (position--)
		reverse_rotate(list_b, "b", tmp_list);
	return (position);
}

int	b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	position;

	size = ft_lstsize(*list_b);
	position = get_max(list_b);
	while (size > 1)
	{
		if (position < (size / 2))
			position = rotate_b_to_a(list_b, tmp_list, position);
		else
			position = r_rotate_b_to_a(list_b, tmp_list, size, position);
		push(list_b, list_a, "a", tmp_list);
		size = ft_lstsize(*list_b);
		position = get_max(list_b);
	}
	push(list_b, list_a, "a", tmp_list);
	return (0);
}

/*
int	b_to_a(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	position;
	int	size;

	size = ft_lstsize(*list_b);
	position = get_max(list_b);
	while (size > 1)
	{
		if (position < (size / 2))
		{
			position--;
			while (position--)
				rotate(list_b, "b", tmp_list);
		}
		else
		{	
			position = size - position + 1;
			while (position--)
				reverse_rotate(list_b, "b", tmp_list);
		}
		push(list_b, list_a, "a", tmp_list);
		size = ft_lstsize(*list_b);
		position = get_max(list_b);
	}
	push(list_b, list_a, "a", tmp_list);
	return (0);
}
*/