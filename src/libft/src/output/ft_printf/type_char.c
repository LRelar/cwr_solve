/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:30:05 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:44:36 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Type function to extract and write in STD_IN a variative of CHAR type.
**	This one handls unicode (of conventional 11110xxx, 1110xxxx, 110xxxxx types)
*/

/*
**	Function checks if unicode starter byte is followed by apropriate continu-
**	ation bytes. Amount of such a bytes defined by int i.
*/

inline static uint8_t	ft_is_garbage(char *intchar, int i)
{
	int					k;

	k = 0;
	while (++k < i)
		if ((intchar[i] & (11 << 6)) != 128)
			return (1);
	return (0);
}

/*
**	Function checks if start of extracted 'int' has signs of unicode symbols.
**	There are 3 types of unicode symbols:	4-byte,		3-byte,		2 byte.
**											11110XXX	1110XXXX	110XXXXX.
*/

inline static void		ft_check_symbol(char *intchar, char *buffer)
{
	if ((*intchar & (15 << 4)) == (15 << 4))
	{
		if (!(ft_is_garbage(intchar, 4)))
		{
			*(uint32_t *)buffer = *(uint32_t *)(intchar);
			return ;
		}
	}
	else if ((*intchar & (14 << 4)) == (14 << 4))
	{
		if (!(ft_is_garbage(intchar, 3)))
		{
			ft_memcpy((void *)&buffer[0], (void *)intchar, 3);
			return ;
		}
	}
	else if ((*intchar & (6 << 5)) == (6 << 5))
	{
		if (!(ft_is_garbage(intchar, 2)))
		{
			*(uint16_t *)buffer = *(uint16_t *)(intchar);
			return ;
		}
	}
	buffer[0] = *intchar;
}

/*
**		dims[0] = (dims[0] > 0) * dims[0] + (dims[0] == 0) * 1;
**		This is equal to:
**	if (dims[0] == 0)
**		dims[0] = 1;
*/

uint8_t					ft_place_char(t_format *formstat, t_fword *format)
{
	uint32_t			variative;
	char				buffer[9];
	size_t				dims[2];

	if (formstat->errflag)
		return (1);
	*(uint64_t *)buffer = 0;
	buffer[8] = 0;
	variative = (uint32_t)(va_arg(*format->variative, unsigned int));
	ft_check_symbol((char *)&variative, &buffer[0]);
	dims[0] = ft_strlen(&buffer[0]);
	dims[0] = (dims[0] > 0) * dims[0] + (dims[0] == 0) * 1;
	dims[1] = dims[0];
	format->ftp_width(formstat, format, &dims[0], &buffer[0]);
	return (0);
}
