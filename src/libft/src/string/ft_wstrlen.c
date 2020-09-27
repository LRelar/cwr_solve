/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:26:30 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/23 21:58:23 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void		ft_check_tail(unsigned const char *bogey, \
									unsigned const char *end, size_t *counter)
{
	while (bogey < end)
	{
		if ((*(bogey) & (3UL << 6)) == 128)
			*counter += 1;
		bogey++;
	}
}

inline static size_t	ft_count_conts(unsigned const char *str, \
													unsigned const char *end)
{
	size_t				counter;
	const size_t		*bogey;

	bogey = (const size_t *)(unsigned const *)str;
	counter = 0;
	while (bogey <= (size_t *)end - 1)
	{
		counter += ((*bogey & 192UL) == (1UL << 7));
		counter += ((*bogey & 49152UL) == (1UL << 15));
		counter += ((*bogey & 12582912UL) == (1UL << 23));
		counter += ((*bogey & 3221225472UL) == (1UL << 31));
		counter += ((*bogey & 824633720832UL) == (1UL << 39));
		counter += ((*bogey & 211106232532992UL) == (1UL << 47));
		counter += ((*bogey & 54043195528445952UL) == (1UL << 55));
		counter += ((*bogey & 13835058055282163712UL) == (1UL << 63));
		bogey++;
	}
	ft_check_tail((unsigned const char *)bogey, end, &counter);
	return (counter);
}

size_t					ft_wstrlen(const char *str)
{
	size_t				byte_size;
	const char			*bogey;

	byte_size = ft_strlen(str);
	bogey = str + byte_size;
	return (byte_size - ft_count_conts((unsigned const char *)str, \
												(unsigned const char *)bogey));
}
