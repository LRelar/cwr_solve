/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdetect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:49:18 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/23 21:25:39 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	9259542123273814144UL:
**	1000 0000 1000 0000 1000 0000 1000 0000
**	1000 0000 1000 0000 1000 0000 1000 0000
*/

uint8_t				ft_wdetect(const char *str, size_t length)
{
	size_t			real_length;
	const size_t	*bogey;

	if (length)
		real_length = length;
	else
		real_length = ft_strlen(str);
	bogey = (const size_t *)str;
	while (real_length >= 8)
	{
		if (*bogey & 9259542123273814144UL)
			return (1);
		bogey++;
		real_length -= 8;
	}
	str = (const char *)bogey;
	while (real_length--)
		if (*str++ & 128U)
			return (1);
	return (0);
}
