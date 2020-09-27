/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:31:03 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 18:04:38 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	In any "place" function (dir type_funcs) there is the same sort of array,
**	where:
**	arr[0]	-	no length flags.
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

static t_extract_float_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_float_rout	*array[8];

	if (!array[0])
	{
		array[0] = &ft_get_float_default;
		array[1] = &ft_get_float_default;
		array[2] = &ft_get_float_default;
		array[3] = &ft_get_float_default;
		array[4] = &ft_get_float_default;
		array[5] = &ft_get_float_default;
		array[6] = &ft_get_float_default;
		array[7] = &ft_get_float_l_cap;
	}
	return (array[num]);
}

uint8_t							ft_place_float(t_format *formstat, \
													t_fword *format)
{
	char						*extraction;
	size_t						dims[2];

	if (!(format->flags))
		format->precision = 6;
	extraction = ft_get_tip(format->length_t)(format, 'f');
	if (!extraction)
		return (1);
	dims[0] = ft_strlen(extraction);
	dims[1] = dims[0];
	format->ftp_width(formstat, format, &dims[0], extraction);
	free(extraction);
	return (0);
}
