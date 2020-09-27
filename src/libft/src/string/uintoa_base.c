/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:04:19 by mschimme          #+#    #+#             */
/*   Updated: 2020/01/13 13:42:32 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_itoafill(char *endofpocket, \
						unsigned long long int n, uint8_t base, char *charset)
{
	while (0 != n)
	{
		*endofpocket-- = charset[(n % base)];
		n /= base;
	}
	return (endofpocket);
}

static int				ft_numvol(unsigned long long int n, uint8_t base)
{
	size_t				v;

	v = 0;
	while (0 != n)
	{
		v++;
		n /= base;
	}
	return (v);
}

/*
**	num - number to be converted
**	buff[0] - buffer, where result should be stored.
**	buff[1] - charsert, used for convesion.
**	base - calculus base.
**	shift - offset for result in buff[0].
*/

char					*ft_uintoa_base(unsigned long long int num, \
						char **buff, uint8_t base, size_t shift)
{
	char				*charset;
	size_t				volume;

	charset = buff[1];
	volume = ft_numvol(num, base);
	if (num)
	{
		return (ft_itoafill(*buff + volume + (shift > volume) * \
										(shift - volume), num, base, charset));
	}
	return (*buff + shift);
}
