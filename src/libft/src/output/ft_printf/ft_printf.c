/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:42:33 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/14 00:41:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**			filling_mainbuf.
** Legacy ft_ls. Moved here without changes.
** DOES NOT carry out ft_printf status check. Will print as soon as
** one of several conditions will be met:
**		1. The buffer is full.
**		2. The flag for output is set.
**		3. The line submitted for recording will overflow the buffer.
** THEN, every entry in the buffer implies the need for preliminary verification
** Ki state of the function.
*/

void					filling_mainbuf(const char *data, size_t length, \
										int flag, int fd)
{
	static char			buff[4096];
	static char			*offset;

	if (!flag)
	{
		if (length > 4096)
		{
			filling_mainbuf(NULL, 0, 1, fd);
			write(fd, data, length);
			return ;
		}
		if (offset + length > buff + 4095)
			filling_mainbuf(NULL, 0, 1, fd);
		ft_memcpy(offset, data, length);
		offset += length;
	}
	if (flag)
	{
		if (!offset)
			offset = buff;
		write(fd, buff, offset - buff);
		offset = buff;
	}
}

/*
**			ft_init_formstat
** Initialization of the statistics structure for the current printf instance.
** We nullify it, assign values to pointers.
**		marker - a pointer that we “walk” along the format line.
**		end - a pointer to the end of a format string (to '\ 0').
**		sight - pointer to the next formatting word.
*/

void					ft_init_formstat(t_format *ptr, const char *src, int fd)
{
	ft_bzero((void *)ptr, sizeof(t_format));
	ptr->marker = src;
	ptr->end = src + ft_strlen(src);
	ptr->sight = src;
	ptr->fd = fd;
}

/*
**			ft_printf
** Main function (input). Its implementation of prints is divided
** into a number of stages.
** 1. Implementation of the t_format basic structure. It records statistics
** operation of the entire implementation (error flag, result of work,
** row status format et cetera.)
** 2. Initialization of the main output buffer (retrieved from ft_ls.)
** 3. Initial scan of a format string (counting (wild cards, WC),
** Valid formatting words (begin with%, end with d or other mod-
** by the identifier of the length of the variant extracted from the ellipse.))
** 4. Initialization and termination of the use of variable option structures.
** 5. Parsing a string, which at each successful stage, writes the result to
** buffer.
*/

int						ft_printf(const char *format, ...)
{
	t_format			formstat;

	ft_init_formstat(&formstat, format, 1);
	filling_mainbuf(NULL, 0, 1, formstat.fd);
	va_start(formstat.ref_ap, format);
	va_copy(formstat.cur_ap, formstat.ref_ap);
	if (ft_scan_string(&formstat) || (ft_parse_format(&formstat)))
	{
		va_end(formstat.ref_ap);
		if (formstat.errflag)
			return (-1);
		return (formstat.result);
	}
	ft_wipe_structs(&formstat, NULL, NULL);
	va_end(formstat.ref_ap);
	filling_mainbuf(NULL, 0, 1, formstat.fd);
	return (formstat.result);
}
