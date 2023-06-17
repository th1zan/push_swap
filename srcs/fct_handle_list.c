/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_handle_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:57:52 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 12:24:58 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

t_nb	*ft_lstnew(int nb)
{
	t_nb	*new_nb;

	new_nb = (t_nb *)malloc(sizeof(t_nb));
	if (!new_nb)
		return (NULL);
	new_nb->prev = NULL;
	new_nb->next = NULL;
	new_nb->nb = nb;
	return (new_nb);
}

void	ft_lstadd_back(t_nb **head_list_nb, t_nb *new_nb)
{
	t_nb	*nb_end;

	nb_end = ft_lstlast(*head_list_nb);
	if (nb_end == 0)
		*head_list_nb = new_nb;
	else
	nb_end->next = new_nb;
	new_nb->prev = nb_end;
}

t_nb	*ft_lstlast(t_nb *list_pt)
{
	if (!list_pt)
		return (0);
	while (list_pt->next != 0)
		list_pt = list_pt->next;
	return (list_pt);
}

int	ft_lstsize(t_nb *liste)
{
	int	n;

	n = 0;
	while (liste != 0)
	{
		liste = liste->next;
		n++;
	}
	return (n);
}

void	ft_lstadd_front(t_nb **lst, t_nb *new)
{
	new->next = *lst;
	*lst = new;
}
