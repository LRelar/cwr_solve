/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:44:31 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:13:36 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h Function
** checks data for presence first, then trying to copy by words size of long int
** if it's impossible either if there some bytes remained - copies byte by byte.
** This version lacking:
** 			if ((bogey = n % sizeof(long)) == 0)
** 			return (dst);
** on the place of string 60 cuz of norme.
** Thus we can get extra small_strings call.
*/

static void		small_strings(unsigned char *csub_dst, \
									unsigned const char *csub_src, size_t *n)
{
	while (*n != 0)
	{
		*csub_dst = *csub_src;
		csub_dst++;
		csub_src++;
		(*n) -= 1;
	}
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		bogey;
	long		*lsub_dst;
	const long	*lsub_src;

	if (0 == n || dst == src)
		return (dst);
	if (n < sizeof(long))
	{
		small_strings((unsigned char *)dst, (unsigned const char *)src, &n);
		return (dst);
	}
	else
	{
		lsub_dst = dst;
		lsub_src = src;
		bogey = n / sizeof(long);
		while (bogey-- != 0)
		{
			*lsub_dst++ = *lsub_src++;
		}
		bogey = n % sizeof(long);
		small_strings((unsigned char *)lsub_dst, \
									(unsigned const char *)lsub_src, &bogey);
		return (dst);
	}
}
