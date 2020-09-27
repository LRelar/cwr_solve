/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:27:03 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/01 13:31:40 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int main(int argc, char **argv)
{
	while(*argv)
	{
		ft_printf("{red} %s {eoc}\nSEPARATOR\n", *argv);
		ft_printf("SEPARATOR \n");
		argv++;
	}
	return (0);
}