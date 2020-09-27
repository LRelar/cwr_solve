/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 18:06:44 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:07:09 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
*	ПРОВЕРИЛ.
//TODO: Предусмотреть проверку состояния **argv (случай "-n" "20" "NULL")
*/

inline static uint8_t	ft_check_filename(char *argv)
{
	if (argv)
		return (ft_strequ(ft_strrchr(argv, '.'), _VALID_EXTENSION_) == 1);
	return (0);
}

/*
*	ПРОВЕРИЛ.
**	Пояснения по поводу flag, id и их значений.
**	id - переменная, хранящая уникальный номер чемпиона, который задается
**	пользователем, либо присваивается виртуальной машиной.
**	Если id == 0, значит пользватель не задавал произвольный id.
**	Если id < 0, попытка присвоить id пользователем оказалась неудачной.
**	Если id > 0, попытка присвоить id пользователем оказалась успешной.
**	Соответственно, если до этого вызывался -n, то id != 0, а значит, в случае
**	ошлибки, надо просмотреть этот флаг повторно (тобишь не итерировать *argv).
//TODO:	Проверить отпрыска: ft_check_filename.
*/

uint8_t					ft_parse_champ(char ***argv, int id, t_world *nexus)
{

	static t_err_rout*	array[2] = { &ft_err_invalid_parameter, \
									&ft_err_not_champ };
	int					flag;

	flag = (id != 0);
	if (ft_check_filename(**argv))
	{
		nexus->champs += ft_read_champ_file(**argv, id, &nexus->champ[0], \
											&nexus->errors);
		++*argv;
		return (ft_scan_lines(argv, nexus));
	}
	else
	{
		array[flag](&nexus->errors, **argv);
		*argv += (flag == 0);
		ft_scan_lines(argv, nexus);
		return (3);
	}
}
