/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b_50.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:14:31 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 11:22:23 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	a_to_b_50(t_nb **list_a, t_nb **list_b, char **tmp_list)
{
	int	size;
	int	position;

	while (ft_lstsize(*list_a) > 2)
	{
		size = ft_lstsize(*list_a);
		position = get_min(list_a);
		if (position <= (size / 2 + 1))
		{
			position--;
			while (position--)
				rotate(list_a, "a", tmp_list);
		}
		else
		{	
			position = size - position + 1;
			while (position--)
				reverse_rotate(list_a, "a", tmp_list);
		}
		push(list_a, list_b, "b", tmp_list);
	}
	sort_list(list_a, list_b, tmp_list);
	while (ft_lstsize(*list_b) > 0)
		push(list_b, list_a, "a", tmp_list);
	return (0);
}
