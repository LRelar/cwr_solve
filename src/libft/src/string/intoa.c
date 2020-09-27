/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:43:28 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/30 22:23:01 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This version ALWAYS writes digits of the numbers startung from buff[1] (
**	first element is always for sign). It uses SHIFT, if we got precision, in
**	order to be able to fill it with 0's).
**	Minus is being set within this function, however.
*/

static char				*ft_itoafill(char *endofpocket, long long int n)
{
	while (0 != n)
	{
		*endofpocket-- = (n % 10) + 48;
		n /= 10;
	}
	return (endofpocket);
}

static int				ft_numvol(long long int n)
{
	size_t				v;

	v = 0;
	if (0 == n)
		v++;
	while (0 != n)
	{
		v++;
		n /= 10;
	}
	return (v);
}

char					*ft_intoa(long long int num, char *buff, size_t shift)
{
	size_t				volume;

	volume = ft_numvol(num);
	if (num == INT64_MIN)
	{
		*(buff + (shift > volume) * (shift - volume) + 1) = '9';
		*buff = '-';
		num = 223372036854775808LL;
		return (ft_itoafill(buff + volume + (shift > volume) * \
													(shift - volume), num) - 1);
	}
	if (num < 0)
	{
		*buff = '-';
		num *= -1;
	}
	if (num)
	{
		return (ft_itoafill(buff + volume + (shift > volume) * \
														(shift - volume), num));
	}
	return (buff + shift);
}
