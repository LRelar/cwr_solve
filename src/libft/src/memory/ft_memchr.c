/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:33:59 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:16:51 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
** Based on ft_strlen method.
*/

typedef unsigned const char	t_ucc;

inline static const void	*ft_memsync_s(t_ucc *str, t_ucc logos, size_t *n)
{
	size_t					k;
	size_t					dim;

	k = *n;
	dim = sizeof(size_t) - 1;
	while (k-- \
	&& (size_t)str & dim \
	&& *str != logos)
		str++;
	*n = k + 1;
	if (*str == logos || n != 0)
		return (str);
	return (NULL);
}

static void					*ft_memcrawl_s(t_ucc *str, t_ucc logos, size_t n)
{
	while (n != 0)
	{
		if (*str == logos)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

void						*ft_memchr(const void *s, int c, size_t n)
{
	size_t					mask;
	size_t					k;
	const size_t			*bogey;

	if (!n)
		return (NULL);
	c &= 0xFF;
	if (*(char *)(s = (ft_memsync_s((t_ucc *)s, (t_ucc)c, &n))) == (char)c && n)
		return ((void *)s);
	bogey = (size_t *)s;
	k = n / sizeof(size_t);
	while (k--)
	{
		mask = *bogey ^ (~0UL / 255UL * (unsigned long)c);
		if ((mask - MHZERO) & ~mask & DHZERO)
			return (ft_memcrawl_s((t_ucc *)bogey, (t_ucc)c, n));
		bogey++;
	}
	return (ft_memcrawl_s((t_ucc *)bogey, (t_ucc)c, n % sizeof(size_t)));
}
