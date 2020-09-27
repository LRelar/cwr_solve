/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:08:18 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/14 17:56:36 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** we use size_t, thus we need libft.h in order to include stdlib.h Yet we got
** ft_memcpy.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	if ((dstlen + srclen) >= dstsize)
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		*(dst + dstsize - 1) = '\0';
	}
	else
	{
		ft_memcpy(dst + dstlen, src, srclen);
		*(dst + dstlen + srclen) = '\0';
	}
	return (srclen + dstlen);
}
