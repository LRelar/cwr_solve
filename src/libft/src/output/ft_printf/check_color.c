/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:41:45 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 22:05:40 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_place_color(t_format *formstat, const char *color, \
						int size, int offset)
{
	ssize_t				overflow;

	overflow = formstat->result + size;
	formstat->marker = formstat->sight + offset;
	formstat->sight = formstat->marker;
	if (overflow < INT32_MIN || overflow > INT32_MAX)
	{
		formstat->errflag = 1;
		ft_err_varoverflow("overflow", __func__);
		return ;
	}
	filling_mainbuf(color, (size_t)size, 0, formstat->fd);
}

uint8_t					ft_check_colour(t_format *formstat)
{
	if (!(ft_memcmp(formstat->sight, "{red}", 5)))
		ft_place_color(formstat, "\x1b[31m", 5, 5);
	else if (!(ft_memcmp(formstat->sight, "{green}", 7)))
		ft_place_color(formstat, "\x1b[32m", 5, 7);
	else if (!(ft_memcmp(formstat->sight, "{yellow}", 8)))
		ft_place_color(formstat, "\x1b[33m", 5, 8);
	else if (!(ft_memcmp(formstat->sight, "{blue}", 6)))
		ft_place_color(formstat, "\x1b[34m", 5, 6);
	else if (!(ft_memcmp(formstat->sight, "{magneta}", 9)))
		ft_place_color(formstat, "\x1b[35m", 5, 9);
	else if (!(ft_memcmp(formstat->sight, "{cyan}", 6)))
		ft_place_color(formstat, "\x1b[36m", 5, 6);
	else if (!(ft_memcmp(formstat->sight, "{eoc}", 5)))
		ft_place_color(formstat, "\x1b[0m", 4, 5);
	else
	{
		formstat->marker = formstat->sight;
		formstat->sight += 1;
		ft_parse_format(formstat);
	}
	return (0);
}
