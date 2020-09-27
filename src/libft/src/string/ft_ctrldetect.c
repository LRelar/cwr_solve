/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrldetect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:51:43 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 08:11:51 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The following macros is quite tricky. In 8 operations were are trying to
**	detect if at least 1 byte of (x) is a member of set 0..128 (excluding
**	borders) is also a member of set m..n, where m is in 0..127, and
**	n is in 0..128. Why limitations? Cuz 7th bit of the lesser byte of
**	filtration result is a detector bit: if x really belongs to m..n set,
**	given operations will return 128, otherwise - 0.
**	If given set steps by its borders beyond value of 128, each byte of machine
**	word will overflow during the operations thus 7th bit will turn to 0.
*/

/*
**	Forbidden defines:
**	#define _PUSHUP_(x, n) ~0UL / 255 * (127 + (n)) - ((x) & ~0UL / 255 * 127)
**	#define _PLDWN_(x, m) ~(x) & ((x) & ~0UL / 255 * 127) + ~0UL / 255 * \
**	(127 - (m))
**	#define BYTEINRANGE(x, m, n) _PUSHUP_(x, n) & _PLDWN_(x, m) & \
**	~0UL / 255 * 128
*/

inline static size_t	ft_bloom(size_t value, size_t left, size_t right)
{
	size_t				res;

	res = ~0UL / 255 * (127 + right) - (value & ~0UL / 255 * 127) & \
			~value & (value & ~0UL / 255 * 127) + ~0UL / 255 * (127 - left) & \
			~0UL / 255 * 128;
	return (res);
}

inline static uint8_t	ft_memsync_s(uint8_t **ptr, size_t *n)
{
	size_t				k;

	k = *n;
	while (k-- && ((size_t)*ptr & sizeof(size_t) - 1) && \
			!((**ptr > 0 && **ptr < 9) || (**ptr > 9 && **ptr < 32)))
		*ptr += 1;
	*n = k + 1;
	if (*n && ((**ptr > 0 && **ptr < 9) || (**ptr > 9 && **ptr < 32)))
		return (1);
	return (0);
}

inline static uint8_t	ft_memcrawl_s(uint8_t *ptr, size_t n)
{
	while (n != 0)
	{
		if ((*ptr > 0 && *ptr < 9) || (*ptr > 9 && *ptr < 32))
			return (1);
		ptr++;
		n--;
	}
	return (0);
}

uint8_t					ft_ctrl_detect(void *src, size_t length)
{
	size_t				k;
	size_t				*ptr;

	if (!length)
		return (0);
	if (ft_memsync_s((uint8_t **)&src, &length))
		return (1);
	k = length / sizeof(size_t);
	ptr = (size_t *)src;
	while (k--)
	{
		if (ft_bloom(*ptr, 0, 9) || ft_bloom(*ptr, 9, 32))
			return (1);
		ptr++;
	}
	return (ft_memcrawl_s((uint8_t*)ptr, length % sizeof(size_t)));
}
