/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:44:31 by mschimme          #+#    #+#             */
/*   Updated: 2019/12/06 21:02:59 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h Function
*/

inline static void	small_string(uint8_t *s, size_t n)
{
	while (n--)
		*s++ = 0;
}

inline static void	*ft_memsync(uint8_t *s, size_t *n)
{
	size_t			k;

	k = *n;
	while (((size_t)s & (sizeof(size_t) - 1)) != 0)
	{
		*s++ = 0;
		k--;
	}
	*n = k;
	return (s);
}

void				ft_bzero(void *s, size_t n)
{
	size_t			bogey;
	size_t			*mask;

	if (0 == n)
		return ;
	if (n < sizeof(size_t))
	{
		small_string((uint8_t *)s, n);
		return ;
	}
	s = ft_memsync((uint8_t *)s, &n);
	bogey = n / sizeof(size_t);
	mask = (size_t *)s;
	while (bogey > 1)
	{
		*mask = 0;
		*(mask + 1) = 0;
		bogey -= 2;
		mask += 2;
	}
	if (bogey)
		*mask++ = 0;
	bogey = n % sizeof(size_t);
	small_string((uint8_t *)mask, bogey);
}
