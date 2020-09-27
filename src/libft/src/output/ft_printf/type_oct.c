/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:59:01 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:32:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Forbidden defines:
**	#define FSPACE_PLUS format->space_plus
**	#define FPRECISION format->precision
**	#define OCTRES buffs[0]
**	#define OCTSET buffs[1]
*/

/*
**	In any "place" function (dir type_funcs) there is the same sort of array,
**	where:
**	arr[1]	-	-l- length flag.
**	arr[2]	-	-ll- length flag.
**	arr[3]	-	-h- length flag.
**	arr[4]	-	-hh- length flag.
**	arr[5]	-	-L- length flag.
**	arr[6]	-	-z- length flag.
**	arr[7]	-	-j- length flag.
**	If unsupported length flag was given in format string, a default tip should
**	be chosen.
*/

static t_extract_oct_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_oct_rout	*array[8];

	if (!array[0])
	{
		array[0] = &ft_get_oct_default;
		array[1] = &ft_get_oct_short_short;
		array[2] = &ft_get_oct_short;
		array[3] = &ft_get_oct_long;
		array[4] = &ft_get_oct_long;
		array[5] = &ft_get_oct_long;
		array[6] = &ft_get_oct_long_long;
		array[7] = &ft_get_oct_long_cap;
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
		format->ftp_width(formstat, format, &dims[0], res);
	}
	else
	{
		dims[0] = ft_strlen(bogey);
		dims[1] = dims[0];
		format->ftp_width(formstat, format, &dims[0], bogey);
	}
}

uint8_t							ft_place_octal(t_format *formstat, \
													t_fword *format)
{
	char						*buffs[2];
	char						*bogey;

	if ((format->flags))
		format->filler = ' ';
	else
		format->precision = 1;
	if (!(buffs[0] = (char *)ft_memalloc(24UL + format->precision + \
											(format->space_plus > 0))))
		return (1);
	buffs[1] = "01234567";
	bogey = ft_get_tip(format->length_t)(format, &buffs[0]);
	ft_memset((void *)(buffs[0] + 1), '0', bogey + 1 - (buffs[0] + 1));
	if (format->hash && !(*bogey))
		buffs[0][0] = '0';
	bogey = buffs[0] + 1;
	ft_printout(formstat, format, buffs[0], bogey);
	free(buffs[0]);
	if (formstat->errflag)
		return (1);
	return (0);
}
