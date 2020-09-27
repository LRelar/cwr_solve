/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:29:47 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 08:13:18 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned const char	*ft_memrcrawl(unsigned const char *str, \
											unsigned const char logos, size_t n)
{
	while (n != 0)
	{
		if (*str == logos)
			return (str);
		str--;
		n -= 1;
	}
	if (*str == logos)
		return (str);
	return (NULL);
}

static unsigned const char	*ft_wordwalker(unsigned const char *str, \
												unsigned const char logos)
{
	size_t					counter;

	counter = 8;
	while (counter != 0)
	{
		if (*str == logos)
			return (str);
		str--;
		counter--;
	}
	return (NULL);
}

static void					*ft_memrchr(const void *s, int c, size_t n)
{
	size_t					*monad;
	unsigned char			logos;
	size_t					mask;

	logos = c;
	if (*(unsigned const char *)s == logos)
		return ((void *)s);
	if (n < (sizeof(size_t)))
		return ((void *)ft_memrcrawl(s, (unsigned const char)logos, n));
	else
	{
		monad = (size_t *)(s - sizeof(size_t) + 1);
		while (n / sizeof(size_t) != 0)
		{
			mask = *monad ^ (~0UL / 255 * logos);
			if ((mask - MHZERO) & ~mask & DHZERO)
				return ((void *)ft_wordwalker(s, (unsigned const char)logos));
			monad--;
			n -= 8;
			s -= 8;
		}
		return ((void *)ft_memrcrawl(s, (unsigned const char)logos, n));
	}
}

char						*ft_strrchr(const char *s, int c)
{
	size_t					length;
	const void				*bogey;

	length = ft_strlen(s);
	bogey = (const void *)s + length;
	return (ft_memrchr(bogey, c, length));
}
