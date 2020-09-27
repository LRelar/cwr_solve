/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_num_eq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:11:04 by andru196          #+#    #+#             */
/*   Updated: 2020/08/20 00:39:18 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_num_eq(long num, char *str)
{
	char	*cpy;
	int		pow;

	cpy = str;
	pow = 10;
	if (!str || (!num && *str != '0'))
		return (0);
	if (*str == '0')
		pow = *(str + 1) == 'x' || *(str + 1) == 'X' ? 16 : 8;
	while (*str)
		str++;
	while (str != cpy && num)
	{
		str--;
		if ((*(str) > '9' ? ft_toupper(*str) - 'A' + 10 : *str - '0')
													!= ft_mod(num % pow))
			return (0);
		num /= pow;
	}
	if (!num && str != cpy)
		str--;
	while (!num && str != cpy && (*str == '0' || !*str))
		str--;
	return (!num && (str == cpy ||
	((str == cpy + 1) && (*str == 'x' || *str == 'X') && *(str - 1) == '0')));
}
