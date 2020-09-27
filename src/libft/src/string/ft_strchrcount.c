/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:35:17 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/03 19:25:40 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strchrcount(const char *s, int c)
{
	size_t		amount;
	const char	*bogey;

	amount = 0;
	bogey = s + ft_strlen(s);
	while (*s != '\0')
	{
		if (!(s = (ft_memchr(s, c, bogey - s))))
			s = bogey;
		if (*s && *s == c)
			amount++;
		if (s != bogey)
			s++;
	}
	return (amount);
}
