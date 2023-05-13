/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:21:51 by thibault          #+#    #+#             */
/*   Updated: 2023/05/13 15:09:54 by thibault         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
}

t_nb	*ft_lstnew(int nb)
{
	t_nb *new_nb;

	new_nb = (t_nb *)malloc(sizeof(t_nb));
	if (!new_nb)
		return (NULL);
	new_nb->next = NULL;
	new_nb->nb = nb;
	// printf("nb = %d, pt = %p\n", new_nb->nb, new_nb);
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
}

t_nb	*ft_lstlast(t_nb *list_pt)
{
	if (!list_pt)
		return (0);
	while (list_pt->next != 0)
		list_pt = list_pt->next;
	return (list_pt);
}


