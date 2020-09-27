/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:32:22 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/14 00:48:45 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MALL ft_memalloc

/*
**	Forbidden defines:
**	#define FHASH format->hash
**	#define FPRECISION format->precision
**	#define FWIDTH format->width
**	#define HEXRES buffs[0]
**	#define HEXSET buffs[1]
*/

/*
**	In any "place" function (dir type_funcs) there is the same sort of array,
**	where:
**	arr[0]	-	no length flags.
**	arr[1]	-	-hh- length flag.
**	arr[2]	-	-h- length flag.
**	arr[3]	-	-l- length flag.
**	arr[4]	-	-z- length flag.
**	arr[5]	-	-j- length flag.
**	arr[6]	-	-ll- length flag.
**	arr[7]	-	-L- length flag.
**	If unsupported length flag was given in format string, a default tip should
**	be chosen.
*/

static t_extract_hex_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_hex_rout	*array[8];

	if (!array[0])
	{
		array[0] = &ft_get_hex_default;
		array[1] = &ft_get_hex_short_short;
		array[2] = &ft_get_hex_short;
		array[3] = &ft_get_hex_long;
		array[4] = &ft_get_hex_long;
		array[5] = &ft_get_hex_long;
		array[6] = &ft_get_hex_long_long;
		array[7] = &ft_get_hex_long_cap;
	}
	return (array[num]);
}

inline static void				ft_printout(t_format *formstat, \
									t_fword *format, char *res, char *bogey)
{
	size_t						dims[2];

	if (*res)
	{
		dims[0] = ft_strlen(res);
		dims[1] = dims[0];
		if (format->filler == '0')
		{
			filling_mainbuf(res, 2, 0, formstat->fd);
			dims[1] -= 2;
			format->ftp_width(formstat, format, &dims[0], bogey);
		}
		else
			format->ftp_width(formstat, format, &dims[0], res);
	}
	else
	{
		dims[0] = ft_strlen(bogey);
		dims[1] = dims[0];
		format->ftp_width(formstat, format, &dims[0], bogey);
	}
}

/*
**	The function writes in one chunk of allocated string. It reutilizes
**	precision, if it's not used. Works only in conjunction with castom
**	intoa_base (stands for Integer shifted to Nth byte in given string).
*/

uint8_t							ft_place_hexal_cap(t_format *formstat, \
													t_fword *format)
{
	char						*buffs[2];
	char						*bogey;
	char						*buffer;

	if ((format->flags))
		format->filler = ' ';
	else
		format->precision = 1;
	if (!(buffer = (char *)MALL(24UL + format->precision + format->hash * 2)))
		return (1);
	buffs[0] = buffer + 1;
	buffs[1] = "0123456789ABCDEF";
	bogey = ft_get_tip(format->length_t)(format, &buffs[0]);
	if (!*(bogey + 1))
		format->hash = 0;
	buffs[0] = buffer;
	ft_memset((void *)(buffs[0] + 2), '0', bogey + 1 - (buffs[0] + 2));
	bogey = buffs[0] + 2;
	if (format->hash && *bogey)
		*(short int *)buffs[0] = (short int)22576U;
	ft_printout(formstat, format, buffs[0], bogey);
	free(buffs[0]);
	if (formstat->errflag)
		return (1);
	return (0);
}
