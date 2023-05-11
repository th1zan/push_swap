/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:21:51 by thibault          #+#    #+#             */
/*   Updated: 2023/05/11 15:16:21 by tsanglar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while ((s[i]))
		i++;
	return (i);
}

void	ft_lstadd_back(t_nb **list_nb, t_nb *new_nb)
{
	t_nb	*nb_end;

	nb_end = ft_lstlast(*list_nb);
	if (nb_end == 0)
		*list_nb = new_nb;
	else
	nb_end->next = new_nb;
}

t_nb	*ft_lstlast(t_nb *list_pt)
{
	if (!list_pt)
		return (0);
	while (list_pt->next != 0)
		list_pt = list_pt->next;
	return (list_pt);
}
