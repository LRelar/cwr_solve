/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:22:22 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:29:00 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Forbidden defines:
**	#define FWIDTH format->width
**	#define FERR formstat->errflag
*/

#define ERRVAR "formstat->result"

uint8_t				ft_place_mem(t_format *formstat, t_fword *format)
{
	const void		*ptr;
	int				res;
	t_printer_rout	*printer;

	if (!(format->width))
		format->width = 8;
	ptr = (const void *)ft_get_mem(format);
	if ((!ptr))
	{
		ptr = (void *)"(null)\n";
		res = 7;
		printer = &filling_mainbuf;
		format->width = res;
	}
	else
	{
		printer = &ft_printmem;
		res = (format->width / 16 + ((format->width % 16) != 0)) * 41 + \
																format->width;
	}
	if (ft_check_add_ovf(&(formstat->result), formstat->result, res))
		return (formstat->errflag = ft_err_varoverflow(ERRVAR, __func__));
	printer((const char *)ptr, (size_t)format->width, 0, (int)formstat->fd);
	return (0);
}
