/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:46:28 by ycorrupt          #+#    #+#             */
/*   Updated: 2020/07/02 22:56:12 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf_fd(int fd, const char *format, ...)
{
	t_format			formstat;

	ft_init_formstat(&formstat, format, fd);
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
