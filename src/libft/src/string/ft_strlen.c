/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:59:30 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 01:38:30 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
** Previously function had
** if (bogey == '\0')
**		return (bogey - (unsigned const char *)str);
** Preventing segfaults.
*/

static unsigned const char	*ft_memsync(unsigned const char *str)
{
	while (((size_t)str & (sizeof(size_t) - 1)) != 0)
	{
		if (*str == '\0')
			return (str);
		str++;
	}
	return (str);
}

static unsigned const char	*ft_memcrawl(unsigned const char *str)
{
	while (*str != '\0')
		str++;
	return (str);
}

size_t						ft_strlen(const char *str)
{
	size_t					*monad;
	unsigned const char		*bogey;

	bogey = ft_memsync((unsigned const char *)str);
	if ((*bogey == 0))
		return (bogey - (unsigned const char *)str);
	monad = (size_t *)bogey;
	while (1)
	{
		if (((*monad + 0X7EFEFEFEFEFEFEFF) ^ ~*monad) & 0x8101010101010100)
			if (((((*monad & 0x7F7F7F7F7F7F7F7F) + 0x7F7F7F7F7F7F7F7F) | *monad)
				| 0x7F7F7F7F7F7F7F7F))
			{
				return (ft_memcrawl(((unsigned const char *)(monad))) - \
													(unsigned const char *)str);
			}
		monad++;
	}
}
