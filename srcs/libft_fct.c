/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:21:51 by thibault          #+#    #+#             */
/*   Updated: 2023/06/16 13:42:28 by thibault         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while ((s[i]))
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		ls1;
	int		ls2;
	int		i;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s3 = malloc((sizeof(char) * (ls1 + ls2 + 1)));
// printf("s3 in strjoin p: %p\n", s3);
	if (!s3)
		return (0);
	i = 0;
	while (i < ls1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < ls1 + ls2)
	{
		s3[i] = s2[i - ls1];
		i++;
	}
	s3[i] = 0;
	return (s3);
}

t_nb	*ft_lstnew(int nb)
{
	t_nb	*new_nb;

	new_nb = (t_nb *)malloc(sizeof(t_nb));
// printf("new_nb in lst_new p: %p\n", new_nb);
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

/*
int	get_octile(t_nb *head_list, int octile)
{
	int		count;
	int		*values;
	int		octile_value;
	t_nb	*tmp;
	int		index;
	int		i;

	count = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	values = (int *)malloc(count * sizeof(int));
	i = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		values[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	bubble_sort(values, count);
	if (octile >= 1 && octile <= 8)
	{
		index = (octile * count) / 8;
		octile_value = values[index];
	}
	else
		octile_value = -1;
	free(values);
	return (octile_value);
}
*/

int	*allocate_values_array(t_nb *head_list, int count)
{
	int		*values;
	int		i;
	t_nb	*tmp;

	values = (int *)malloc(count * sizeof(int));
// printf("values in allocate_values p: %p\n", values);
	i = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		values[i] = tmp->nb;
		i++;
		tmp = tmp->next;
	}
	return (values);
}

int	compute_octile_value(int octile, int count, int *values)
{
	int	octile_value;
	int	index;

	octile_value = -1;
	if (octile >= 1 && octile <= 8)
	{
		index = (octile * count) / 8;
		octile_value = values[index];
	}
	return (octile_value);
}

int	get_octile(t_nb *head_list, int octile)
{
	int		count;
	t_nb	*tmp;
	int		*values;
	int		octile_value;

	count = 0;
	tmp = head_list;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	values = allocate_values_array(head_list, count);
	bubble_sort(values, count);
	octile_value = compute_octile_value(octile, count, values);
	free(values);
	return (octile_value);
}

int	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
