/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 22:00:27 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 21:34:33 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void				*bogey;
	unsigned char		logos;

	logos = (unsigned char)c;
	bogey = NULL;
	if (n == 0)
		return (NULL);
	bogey = (unsigned char *)ft_memchr(src, logos, n);
	if (!bogey)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	else
		return (ft_memcpy(dst, src, (bogey - src) + 1) + (bogey - src) + 1);
}
