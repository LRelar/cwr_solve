/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:29:55 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 21:37:54 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** we use size_t, thus we need libft.h in order to include stdlib.h Yet we got
** ft_memcpy.
*/

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t dstlen;

	if (!dst || !src)
		return (-1);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (0 == size)
		return (srclen);
	if (srclen <= size && srclen <= dstlen)
	{
		ft_memcpy((void *)dst, (const void *)src, srclen + 1);
		return (srclen);
	}
	ft_memcpy((void *)dst, (const void *)src, size - 1);
	*(dst + size - 1) = '\0';
	return (srclen);
}
