/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:03:09 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:03:16 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_err_mixed_input(void)
{
	ft_putstr_fd("Warning! Mixed variatives invocation. In same format ", 2);
	ft_putendl_fd("string standard invocation (or '*') mixed with k$.", 2);
}
