/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_overflow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:03:28 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:03:52 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_err_varoverflow(char *variable,
						const char *call_func)
{
	ft_putstr_fd("Warning! Variable ", 2);
	ft_putstr_fd(variable, 2);
	ft_putstr_fd(", used in function: ", 2);
	ft_putstr_fd(call_func, 2);
	ft_putendl_fd("overflowed. Excpect undefined behavior.", 2);
	return (1);
}
