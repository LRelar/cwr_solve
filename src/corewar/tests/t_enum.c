/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_enum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:05:25 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/01 00:35:22 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline static int	callshit(void)
{
	static int i;
	return (++i);
}

int		main(void)
{
	int k;

	k = 0;
	
	for (int i = 0; i < 10; i++)
		k = (t_bool)callshit();
	DEBintt(k) DEBend();
_Bool ls;
ls = 20;

	return (0);
}