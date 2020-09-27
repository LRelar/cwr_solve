/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:12:15 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:21:47 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static void		ft_swap(int *a, int *b)
{
	int					pocket;

	pocket = *a;
	*a = *b;
	*b = pocket;
}

inline static uint8_t	ft_bubblesorted(int *array, size_t size, \
															t_datacmp_rout *cmp)
{
	uint8_t				res;
	size_t				bogey;

	res = 1;
	bogey = 0;
	while (bogey < size - 1)
	{
		if (cmp(&array[bogey], &array[bogey + 1]))
		{
			res = 0;
			ft_swap(&array[bogey], &array[bogey + 1]);
		}
		bogey++;
	}
	return (res);
}

void					ft_srt_bubble_intarr(int *array, size_t size, \
															t_datacmp_rout *cmp)
{
	size_t				bogey;

	bogey = 0;
	while (bogey < size)
	{
		if (ft_bubblesorted(array, size - bogey, cmp))
			return ;
		bogey++;
	}
}
