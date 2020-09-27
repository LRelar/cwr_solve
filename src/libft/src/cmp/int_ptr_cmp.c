/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_ptr_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:25:50 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:24:34 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Thus array will be sorted ascending.
*/

int				ft_intp_left_grt_right(void *a, void *b)
{
	return (*(int *)a > *(int *)b);
}

/*
**	Thus array will be sorted descending.
*/

int				ft_intp_left_lsr_right(void *a, void *b)
{
	return (*(int *)a < *(int *)b);
}
