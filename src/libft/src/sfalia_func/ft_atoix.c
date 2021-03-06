/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:33:08 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:44:57 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_dec(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str != '0')
		return (1);
	while (*str && *str == '0' && *(str + 1) == '0')
		str++;
	if (ft_toupper(*(str + 1)) == 'X')
		return (0);
	while (*str)
		if (!(*str == '8' || *str == '9'))
			return (1);
	return (0);
}

long long int	ft_atoix(char *str)
{
	long long	rez;
	int			sign;
	int			method;

	while (ft_isspace(*str))
		str++;
	if (is_dec(str))
		return (ft_atoil(str));
	sign = *str == '-' ? -1 : 1;
	str += (*str == '+' || *str == '-');
	method = *str == '0' ? 8 : 10;
	method = method == 8 && ft_toupper(*(str + 1)) == 'X' ? 16 : method;
	while (*str == '0')
		str++;
	str = ft_toupper(*str) == 'X' ? str + 1 : str;
	rez = 0;
	while ((method == 10 && ft_isdigit(*str)) || (method == 8 && *str >= '0'
	&& *str <= '7') || (method == 16 && (ft_isdigit(*str) ||
	(ft_toupper(*str) >= 'A' && ft_toupper(*str) <= 'F'))))
	{
		rez *= method;
		rez += ft_isdigit(*str) ? *str - '0' : ft_toupper(*str) - 'A' + 10;
		str++;
	}
	return (rez * sign);
}
