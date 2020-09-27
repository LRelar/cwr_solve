/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:22:22 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:25:53 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Forbidden define, lol:
**	#define HEXRES buffs[0]
**	#define HEXSET buffs[1]
**	F8CK this norm!
*/

static t_extract_hex_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_hex_rout	*array[1];

	if (!array[0])
		array[0] = &ft_get_ptr;
	return (array[num]);
}

inline static void				ft_printout(t_format *formstat, \
									t_fword *format, char *res, char *bogey)
{
	size_t						dims[2];

	if (format->filler == '0')
	{
		dims[0] = ft_strlen(res);
		filling_mainbuf(res, 2, 0, formstat->fd);
		dims[1] = dims[0] - 2;
		format->ftp_width(formstat, format, &dims[0], bogey);
	}
	else
	{
		dims[0] = ft_strlen(res);
		dims[1] = dims[0];
		format->ftp_width(formstat, format, &dims[0], res);
	}
}

uint8_t							ft_place_ptr(t_format *formstat, \
													t_fword *format)
{
	char						*buffs[2];
	char						*bogey;
	char						*buffer;

	if ((format->flags))
		format->filler = ' ';
	else
		format->precision = 1;
	if (!(buffer = (char *)ft_memalloc(24UL + format->precision + 2)))
		return (1);
	*(short int *)buffer = (short int)30768U;
	buffs[0] = buffer + 1;
	buffs[1] = "0123456789abcdef";
	bogey = ft_get_tip(0)(format, &buffs[0]);
	ft_memset((void *)(buffer + 2), '0', bogey + 1 - (buffer + 2));
	bogey = buffer + 2;
	ft_printout(formstat, format, buffer, bogey);
	free(buffer);
	if (formstat->errflag)
		return (1);
	return (0);
}
