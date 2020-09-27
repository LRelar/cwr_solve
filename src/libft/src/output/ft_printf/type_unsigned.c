/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:00:13 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:51:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MALL ft_memalloc

/*
**	Forbidden defines:
**	#define FSPACE_PLUS format->space_plus
**	#define FPRECISION format->precision
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

static t_extract_int_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_int_rout	*array[8];

	if (!array[0])
	{
		array[0] = &ft_get_uns_default;
		array[1] = &ft_get_uns_short_short;
		array[2] = &ft_get_uns_short;
		array[3] = &ft_get_uns_long;
		array[4] = &ft_get_uns_long;
		array[5] = &ft_get_uns_long;
		array[6] = &ft_get_uns_long_long;
		array[7] = &ft_get_uns_long_cap;
	}
	return (array[num]);
}

uint8_t							ft_place_unsigned(t_format *formstat, \
													t_fword *format)
{
	char		*res;
	char		*bogey;
	size_t		dims[2];

	if ((format->flags))
		format->filler = ' ';
	else
		format->precision = 1;
	if (!(res = (char *)MALL(24UL + format->precision + \
								(format->space_plus > 0))))
		return (1);
	bogey = ft_get_tip(format->length_t)(format, res);
	ft_memset((void *)(res + 1), '0', bogey + 1 - (res + 1));
	bogey = res + 1;
	dims[0] = ft_strlen(bogey);
	dims[1] = dims[0];
	format->ftp_width(formstat, format, &dims[0], bogey);
	free(res);
	if (formstat->errflag)
		return (1);
	return (0);
}
