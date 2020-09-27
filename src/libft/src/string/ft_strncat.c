/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:09:11 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/15 14:32:17 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use NULL and size_t, thus we need libft.h in order to include stdlib.h
*/

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2len > n)
	{
		ft_memcpy(s1 + s1len, s2, n);
		*(s1 + s1len + n) = '\0';
	}
	if (s2len <= n)
	{
		ft_memcpy(s1 + s1len, s2, s2len);
		*(s1 + s1len + s2len) = '\0';
	}
	return (s1);
}
