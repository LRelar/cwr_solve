/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_chain_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:02:00 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:02:13 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_err_broken_chain(void)
{
	ft_putstr_fd("Warning! Variative explicit invocation (aka 'n$') is ", 2);
	ft_putendl_fd("inconsistent. Expect undefined behavior.", 2);
}
