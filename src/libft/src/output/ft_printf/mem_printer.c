/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:45:34 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:41:58 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_putsym(const unsigned char *addr, int fd)
{
	if (*addr >= 32 && *addr <= 126)
		filling_mainbuf((const char *)addr, 1, 0, fd);
	else
		filling_mainbuf(".", 1, 0, fd);
}

static void				print_hex(unsigned char c, int fd)
{
	char	buff[3];
	int		i;
	char	*system;

	buff[2] = '\0';
	system = "0123456789abcdef";
	i = 1;
	while (i >= 0)
	{
		buff[i] = system[c % 16];
		c /= 16;
		i--;
	}
	filling_mainbuf(buff, 2, 0, fd);
}

static void				ft_filler(size_t i, size_t step, int fd)
{
	while (i < step)
	{
		filling_mainbuf("  ", 2, 0, fd);
		if (i && (i % 2))
			filling_mainbuf(" ", 1, 0, fd);
		i++;
	}
}

inline static void		ft_print_hexes(size_t *ctr, size_t size, \
											const unsigned char *addr, int fd)
{
	while ((*ctr % 16) && *ctr < size)
	{
		print_hex(addr[*ctr], fd);
		if (*ctr && (*ctr % 2))
			filling_mainbuf(" ", 1, 0, fd);
		++*ctr;
	}
}

void					ft_printmem(const char *addr, size_t size, int fl, \
									int fd)
{
	size_t				ctr;
	size_t				offset;
	size_t				step;

	(void)fl;
	if (!addr)
		return ;
	step = 0;
	while (step < size)
		step += 16;
	ctr = 0;
	while (ctr < size)
	{
		offset = ctr;
		print_hex(addr[ctr++], fd);
		ft_print_hexes(&ctr, size, (const unsigned char *)addr, fd);
		if (ctr >= size)
			ft_filler(ctr, step, fd);
		ft_putsym((const unsigned char *)&addr[offset++], fd);
		while ((offset % 16) && offset < size)
			ft_putsym((const unsigned char *)&addr[offset++], fd);
		filling_mainbuf("\n", 1, 0, fd);
	}
}
