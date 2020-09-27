/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_va_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:18:27 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:18:37 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_skip_va_arg_int(va_list *bogey)
{
	va_arg(*bogey, int);
}

void					ft_skip_va_arg_float(va_list *bogey)
{
	va_arg(*bogey, double);
}
