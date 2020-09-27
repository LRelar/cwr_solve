/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_op_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:22:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 16:45:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
TODO:	Сделать.
*/
void		op_lldi(t_world *nexus, t_carry *carry, \
							t_dvasa *head, t_dvasa **vacant)
{
	t_op	op_cont;

	ft_clone_op_cont(14, &op_cont);
	if (!(ft_eval_operands_type(&nexus->arena[0], carry->pos, &op_cont)))
	{
	// Распарсить параметры.
	// Выполнить операцию.
	// Передвинуть каретку.
	// Обновить exec_cyc.
	return ;
	}
	// Передвинуть каретку.
	// Обновить exec_cyc.
}