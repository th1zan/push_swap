/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:21:51 by thibault          #+#    #+#             */
/*   Updated: 2023/06/17 12:25:10 by thibault         ###   ########.fr       */
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
