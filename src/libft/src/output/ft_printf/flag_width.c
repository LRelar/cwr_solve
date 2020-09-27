/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:13:35 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 22:08:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static uint8_t	ft_get_numsubline_dummy(const char *start, \
						t_format *formstat)
{
	const char			*ptr;

	ptr = start;
	while (ft_memchr("1234567890", *++ptr, 10))
		;
	formstat->sight = ptr - 1;
	return (1);
}

uint8_t					ft_flag_width_dummy(t_format *formstat)
{
	const char			*start;

	start = formstat->sight;
	if (ft_memchr("123456789", *start, 9))
		return (ft_get_numsubline_dummy(start, formstat));
	else if (*start == '*')
		return (ft_proc_wildcard_dummy(formstat, 1));
	else
		return (0);
}

inline static uint8_t	ft_get_numsubline(const char *start, \
						t_format *formstat, t_fword *format)
{
	long long			arg_num;
	const char			*ptr;
	const char			*end;

	ptr = start;
	while (ft_memchr("1234567890", *++ptr, 10))
		;
	end = ptr;
	formstat->sight = end - 1;
	if (ft_antoi(start, end, &arg_num))
		formstat->errflag = ft_err_varoverflow("arg_num", __func__);
	else
	{
		if (arg_num < INT32_MIN || arg_num > INT32_MAX)
			formstat->errflag = ft_err_varoverflow("arg_num", __func__);
		if (arg_num < 0)
		{
			arg_num *= -1;
			ft_flag_minus("-", format);
		}
		format->width = (int)arg_num;
	}
	return (1);
}

uint8_t					ft_flag_width(t_format *formstat, t_fword *format)
{
	const char			*start;

	start = formstat->sight;
	if (ft_memchr("123456789", *start, 9))
		return (ft_get_numsubline(start, formstat, format));
	else if (*start == '*')
		return (ft_proc_wildcard(formstat, format, 1));
	else
		return (0);
}
