/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:34:56 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/14 01:15:07 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Forbidden defines:
**	#define FPRECISION format->precision
*/

static t_extract_arg_rout		*ft_get_tip(uint8_t num)
{
	static t_extract_arg_rout	*array[2];

	if (!array[0])
	{
		array[0] = &ft_get_string_default;
	}
	return (array[num]);
}

static void						ft_shift_unicode(char *extr, size_t *reslen)
{
	if (reslen)
	{
		if ((extr[*reslen] & 192) == 192)
			++*reslen;
		while ((extr[*reslen] & 192) == (1UL << 7))
			++*reslen;
	}
}

uint8_t							ft_place_string(t_format *formstat, \
													t_fword *format)
{
	char						*extraction;
	size_t						dims[2];

	extraction = ft_get_tip(0)(format);
	if (!extraction)
		return ((formstat->errflag = 1));
	dims[0] = ft_strlen(extraction);
	if (format->flags)
		dims[0] = ((size_t)format->precision > dims[0]) * dims[0] + \
			((size_t)format->precision <= dims[0]) * (size_t)format->precision;
	ft_shift_unicode(extraction, &dims[0]);
	dims[1] = dims[0];
	format->ftp_width(formstat, format, &dims[0], extraction);
	free(extraction);
	if (formstat->errflag)
		return (1);
	return (0);
}
