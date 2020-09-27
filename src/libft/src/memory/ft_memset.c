/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:41:50 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 21:35:37 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h Function
** in_small_string performes the task if len of main function is < 8.
*/

static void		in_small_string(void *s, unsigned char c, size_t *n)
{
	while (*n != 0)
	{
		*(unsigned char *)s = c;
		*n -= 1;
		s++;
	}
}

static void		*ft_memsync(void *s, unsigned char c, size_t *n)
{
	while (((size_t)s & (sizeof(size_t) - 1)) != 0)
	{
		*(unsigned char *)s = c;
		*n -= 1;
		s++;
	}
	return (s);
}

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			*bogey;
	size_t			num;
	size_t			ver;
	unsigned char	symb;

	symb = (unsigned char)c;
	ver = sizeof(size_t);
	num = c;
	bogey = (size_t *)b;
	if (0 == len)
		return (b);
	if (len < sizeof(size_t))
	{
		in_small_string((void *)bogey, symb, &len);
		return (b);
	}
	while (ver-- != 0)
		num = ((num) << 8) + (int)symb;
	bogey = ft_memsync((void *)bogey, symb, &len);
	ver = len / sizeof(size_t);
	while (ver-- != 0)
		*bogey++ = num;
	ver = len % sizeof(size_t);
	in_small_string((void *)bogey, symb, &ver);
	return (b);
}
