/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:48:19 by tsanglar          #+#    #+#             */
/*   Updated: 2023/06/05 16:25:19 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_lib.h"
#include "inc_struct.h"
#include "inc_functions.h"

int	ft_printf_hex(unsigned long dec, int *result, int cap)
{
	unsigned char	hex;

	hex = dec % 16;
	if (dec > 15)
	{
		ft_printf_hex(dec / 16, result, cap);
	}
	if (hex < 10)
		hex = hex + '0';
	else
		hex = hex + 'a' - 10 - 32 * cap;
	write(1, &hex, 1);
	*result = *result + 1;
	return (0);
}
