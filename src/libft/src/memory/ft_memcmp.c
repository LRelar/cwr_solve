/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:16:11 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:12:06 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
*/

typedef const void		t_cv;

static int				ft_btbcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*sub_s1;
	unsigned const char	*sub_s2;

	sub_s1 = (unsigned const char *)s1;
	sub_s2 = (unsigned const char *)s2;
	while (n != 0)
	{
		if (*sub_s1 != *sub_s2)
			return (*sub_s1 - *sub_s2);
		sub_s1++;
		sub_s2++;
		n--;
	}
	return (0);
}

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				bogey;
	const size_t		*sub_s1;
	const size_t		*sub_s2;

	if (0 == n || ((const char *)s1 == NULL && (const char *)s2 == NULL))
		return (0);
	if (n < sizeof(size_t))
		return (ft_btbcmp(s1, s2, n));
	sub_s1 = (const size_t *)s1;
	sub_s2 = (const size_t *)s2;
	bogey = n / sizeof(size_t);
	while (bogey-- != 0)
	{
		if (*sub_s1 != *sub_s2)
			return (ft_btbcmp((t_cv *)sub_s1, (t_cv *)sub_s2, sizeof(size_t)));
		sub_s1++;
		sub_s2++;
	}
	bogey = n % sizeof(size_t);
	return (ft_btbcmp((const void *)sub_s1, (const void *)sub_s2, bogey));
}
