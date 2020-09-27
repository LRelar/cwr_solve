/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:56:10 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 14:02:56 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline intptr_t	ft_calc_addr(intptr_t offset)
{
	return ((offset % MEM_SIZE) + MEM_SIZE * (offset < 0));
}

inline intptr_t	ft_step_size(uint8_t ops_type, uint8_t t_dir_size)
{
	return ((ops_type == T_REG) + (ops_type == T_DIR) * t_dir_size + \
													(ops_type == T_IND) * 2);
}

inline uint8_t	ft_check_reg_is_valid(uint8_t *arena, uintptr_t ptr)
{
	uint8_t		value;
	
	value = arena[ft_calc_addr(ptr)];
	return (value > 0 && value <= REG_NUMBER);
}