/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_va_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:17:42 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:18:00 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_prepare_va_list(t_format *formstat, int number, \
						va_list *var)
{
	int					k;
	t_varitype			*bogey;

	bogey = formstat->first;
	while (bogey && (bogey->vari_num != number))
	{
		bogey->iterator(var);
		k = bogey->vari_interval;
		while (--k)
			va_arg(*var, int);
		bogey = bogey->next;
	}
}
