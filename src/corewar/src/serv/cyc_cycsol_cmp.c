/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyc_cycsol_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:59:08 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/01 20:07:32 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int				ft_cyc_left_grt_right(void *a, void *b)
{
	return ((((t_vasa *)a)->gen.cyc_sol) > (((t_vasa *)b)->gen.cyc_sol));
}

int				ft_cyc_left_lsr_right(void *a, void *b)
{
	return ((((t_vasa *)a)->gen.cyc_sol) < (((t_vasa *)b)->gen.cyc_sol));
}
