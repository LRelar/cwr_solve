/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:43:28 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/30 22:23:24 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_itoafill(char *endofpocket, \
						unsigned long long int n)
{
	while (0 != n)
	{
		*endofpocket-- = (n % 10) + 48;
		n /= 10;
	}
	return (++endofpocket);
}

static int				ft_numvol(unsigned long long int n)
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

char					*ft_uintoa(unsigned long long int num, char *buff,\
						size_t shift)
{
	size_t				volume;

	volume = ft_numvol(num);
	if (num)
	{
		return (ft_itoafill(buff + volume + (shift > volume) * \
													(shift - volume), num) - 1);
	}
	return (buff + shift);
}
