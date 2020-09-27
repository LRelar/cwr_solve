/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intoa_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:34:11 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/29 17:27:53 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_itoafill(char *endofpocket, long long int n)
{
	while (0 != n)
	{
		*endofpocket-- = (n % 10) + 48;
		n /= 10;
	}
}

static int				ft_numvol(long long int n, size_t shift)
{
	size_t	v;

	v = 0;
	if (0 == n || n < 0)
		v++;
	v += (n >= 0) * shift;
	while (0 != n)
	{
		v++;
		n /= 10;
	}
	return (v);
}

char					*ft_intoa_float(long long int num, char *buff, \
																size_t shift)
{
	size_t				volume;

	volume = ft_numvol(num, shift);
	if (!num)
		*(short int *)(buff + shift) = 48;
	if (num == INT64_MIN)
	{
		*(short int *)buff = 14637;
		num = 223372036854775808LL;
	}
	if (num < 0)
	{
		*buff = '-';
		num *= -1;
	}
	ft_itoafill(buff + volume - 1, num);
	*(buff + volume) = '\0';
	return (buff);
}
