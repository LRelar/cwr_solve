/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:53:53 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:18:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use size_t, thus we need libft.h in order to include stdlib.h
** Logics: [...|....|abcd|..fr|om.h|ere.|we w|ill.|move|]
** 		   [...|....{L..#|..#R}..E.|F...|....|....|....|]
** 						^src^dst    ^ Ending byte
** # point at adresses of src and dst virtual pointers. We move 8 bytes
** Starting from to write L byte to DST leads to losing # and R bytes.
** That's why we propagate ending byte and start moving src from it's end (E)
*/

static void		small_strings_tol(unsigned char *csub_dst, \
									unsigned char *csub_src, size_t *n)
{
	while (*n != 0)
	{
		*csub_dst = *csub_src;
		csub_dst++;
		csub_src++;
		*n -= 1;
	}
}

static void		small_strings_tor(unsigned char *csub_dst, \
									unsigned char *csub_src, size_t *n)
{
	while (*n != 0)
	{
		*csub_dst = *csub_src;
		csub_dst--;
		csub_src--;
		*n -= 1;
	}
}

static void		b_word_tol(size_t *dst, size_t *src, size_t n)
{
	size_t	bogey;

	bogey = n / sizeof(size_t);
	while (bogey-- != 0)
		*dst++ = *src++;
	bogey = n % sizeof(size_t);
	small_strings_tol((unsigned char *)dst, (unsigned char *)src, &bogey);
}

static void		b_word_tor(size_t *dst, size_t *src, size_t n)
{
	size_t	bogey;

	bogey = n % sizeof(size_t);
	small_strings_tor((unsigned char *)dst + n - 1, \
							(unsigned char *)src + n - 1, &bogey);
	bogey = n / sizeof(size_t);
	dst += (bogey - 1);
	src += (bogey - 1);
	while (bogey-- != 0)
		*dst-- = *src--;
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (0 == len || dst == src)
		return (dst);
	if (len < sizeof(long))
	{
		if (src > dst)
			small_strings_tol((unsigned char *)dst, (unsigned char *)src, &len);
		else
			small_strings_tor((unsigned char *)dst + len - 1, \
								(unsigned char *)src + len - 1, &len);
		return (dst);
	}
	if (src > dst)
		b_word_tol((size_t *)dst, (size_t *)src, len);
	else
		b_word_tor((size_t *)dst, (size_t *)src, len);
	return (dst);
}
