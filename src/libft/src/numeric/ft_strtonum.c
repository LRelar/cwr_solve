/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtonum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:03:45 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 08:04:35 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	Forbidden defines
**	F8CK THIS F8CKING NORME! IT DOES NOT MAKE CODE BETTER!
**	#define LI64MAX (INT64_MAX / 10)
**	#define LI32MAX (INT32_MAX / 10)
**	#define WILL_OVERFLOW(x, y) res > (x) || res == (x) && *str > (y)
**	#define WILL_UNDERFLOW(x, y) res > (x) || res == (x) && *str > (y)
*/

#define LI64MAX 922337203685477580LL
#define LI32MAX 214748364

long long		ft_atol_r(const char *str, uint8_t *status)
{
	long long	res;
	int			sign;

	res = 0;
	if (!str)
		return ((*status = 1) - 1);
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = (*str == '-') * (-1) + (*str != '-');
	str += (*str == '-') + (*str == '+');
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if (sign == -1 && \
			(res > LI64MAX || (res == LI64MAX && *str > '8')) && (*status = 1))
			break ;
		if (sign == 1 && \
			(res > LI64MAX || (res == LI64MAX && *str > '7')) && (*status = 2))
			break ;
		res = (res * 10) + (*str - '0');
		str += 1;
	}
	if (*status)
		return ((*status == 1) * INT64_MIN + (*status == 2) * INT64_MAX);
	res *= sign;
	return (res);
}

long long		ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str += 1;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-') + (*str == '+');
	res = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if (sign == -1 && (res > LI64MAX || (res == LI64MAX && *str > '8')))
			return (0);
		if (sign == 1 && (res > LI64MAX || (res == LI64MAX && *str > '7')))
			return (-1);
		res = (res * 10) + (*str - '0');
		str += 1;
	}
	res *= sign;
	return (res);
}

int				ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str += 1;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-') + (*str == '+');
	res = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if (sign == -1 && (res > LI32MAX || (res == LI32MAX && *str > '8')))
			return (0);
		if (sign == 1 && (res > LI32MAX || (res == LI32MAX && *str > '7')))
			return (-1);
		res = (res * 10) + (*str - '0');
		str += 1;
	}
	res *= sign;
	return (res);
}
