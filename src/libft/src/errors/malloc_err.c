/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:02:39 by kokeefe           #+#    #+#             */
/*   Updated: 2019/11/22 03:49:53 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_err_malloc(char *variable, const char *call_func)
{
	ft_putstr_fd("Error! Failed to allocate memory", 2);
	if (variable)
	{
		ft_putstr_fd(" for ", 2);
		ft_putstr_fd(variable, 2);
	}
	ft_putstr_fd(" in function: ", 2);
	ft_putstr_fd(call_func, 2);
	ft_putendl_fd(".", 2);
	return (1);
}
