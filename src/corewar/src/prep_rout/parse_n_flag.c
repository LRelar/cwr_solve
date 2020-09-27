/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 12:38:14 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/26 13:45:16 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
** Check ~/src/prep_rout/parse_fdump.c for hints.
*/

inline static uint8_t	ft_register_fn_param(char *argv, long long *value, \
												t_vasa **error_head)
{
	uint8_t				flag;

	flag = 0;
	if (ft_are_digits(argv))
	{
		*value = ft_atol_r(argv, &flag);
		if (((int)(*value) != *value) || flag || (*value > MAX_PLAYERS))
		{
			*value = -1;
			ft_err_fn_inter(error_head, argv);
			flag = 2;
		}
	}
	else
	{
		flag = 3;
		*value = -1;
		ft_err_fn_notnbr(error_head, argv);
	}
	return (flag);
}

/*
**	++*argv; - to iterate towards declared -n value.
*/

int						ft_get_n_flag(char ***argv, t_world *nexus)
{
	long long	res;
	uint8_t		flag;

	++*argv;
	flag = ft_register_fn_param(**argv, &res, &nexus->errors);
	if (flag != 3)
		++*argv;
	return ((int)res);
}
