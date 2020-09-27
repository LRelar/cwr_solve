/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:55:56 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/28 22:38:42 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoafill(char *endofpocket, int n)
{
	while (0 != n)
	{
		*endofpocket-- = (n % 10) + 48;
		n /= 10;
	}
}

static int	ft_numvol(int n)
{
	size_t	v;

	v = 0;
	if (0 == n || n < 0)
		v++;
	while (0 != n)
	{
		v++;
		n /= 10;
	}
	return (v);
}

char		*ft_itoa(int n)
{
	char	*pocket;
	int		volume;

	volume = ft_numvol(n);
	if (!(pocket = ft_strnew(volume)))
		return (NULL);
	if (n == 0)
		*pocket = '0';
	if (n == -2147483648)
	{
		pocket[0] = '-';
		pocket[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		pocket[0] = '-';
		n *= -1;
	}
	ft_itoafill(pocket + volume - 1, n);
	return (pocket);
}
