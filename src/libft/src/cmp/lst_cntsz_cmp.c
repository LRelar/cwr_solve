/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cntsz_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:59:09 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:24:50 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	lst for Lis.
**	cntsz for content_size.
*/

int				ft_lst_cntsz_left_grt_right(void *a, void *b)
{
	return ((((t_list *)a)->content_size) > (((t_list *)b)->content_size));
}

int				ft_lst_cntsz_left_lsr_right(void *a, void *b)
{
	return (((((t_list *)a)->content_size)) < (((t_list *)b)->content_size));
}
