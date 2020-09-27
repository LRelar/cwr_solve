/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_list_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:04:21 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:21:00 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Null-terminated t_list **arr_ptr must be used in this function set.
**	Expect undefind behavior on t_list chain otherwise.
**	size_t length does not count null-terminator at the and of the array.
**	If length == 10, then sizeof(arr_ptr) == 11: 10 for real elements and 11th
**	as a NULL-terminator.
*/

inline static void		ft_lineup(t_list **head, t_list **arr_ptr, \
									size_t length)
{
	size_t				bogey;

	bogey = 0;
	*head = arr_ptr[bogey];
	while (bogey < length)
	{
		arr_ptr[bogey]->next = arr_ptr[bogey + 1];
		bogey++;
	}
}

inline static void		ft_swap(t_list **a, t_list **b)
{
	t_list				*pocket;

	pocket = *a;
	*a = *b;
	*b = pocket;
}

inline static uint8_t	ft_bubblesorted(t_list **array, size_t size, \
															t_datacmp_rout *cmp)
{
	uint8_t				res;
	size_t				bogey;

	res = 1;
	bogey = 0;
	while (bogey < size - 1)
	{
		if (cmp(array[bogey], array[bogey + 1]))
		{
			res = 0;
			ft_swap(&array[bogey], &array[bogey + 1]);
		}
		bogey++;
	}
	return (res);
}

void					ft_srt_listarr_bubble(t_list **head, t_list **arr_ptr, \
											size_t length, t_datacmp_rout *cmp)
{
	size_t				bogey;

	bogey = 0;
	while (bogey < length)
	{
		if (ft_bubblesorted(arr_ptr, length - bogey, cmp))
		{
			ft_lineup(head, arr_ptr, length);
			return ;
		}
		bogey++;
	}
}
