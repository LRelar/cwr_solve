/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_are_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 13:16:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/04/26 13:41:23 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_are_digits(const char *str);


int	main(int argc, char **argv)
{
	for (int i = 0; i <= argc; i++)
	{
		DEBintt(ft_are_digits(*argv)) DEBtextt(*argv) DEBend()
		argv++;
	}
	return (0);
}