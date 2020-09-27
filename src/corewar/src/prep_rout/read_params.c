/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:44:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:05:12 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
*	ПРОВЕРИЛ.
!	Не трожь (*argv)++. Здесь все правильно (у нас char ***argv).
// TODO:	Проверить ft_parse_champ.
**	Flag '-g' is for future visualization.
*/

uint8_t		ft_scan_lines(char ***argv, t_world *nexus)
{
	if (**argv)
	{
		if (!ft_strcmp(**argv, "-dump"))
			return (ft_parse_fdump(argv, nexus));
		else if (!ft_strcmp(**argv, "-n"))
			return (ft_parse_champ(argv, ft_get_n_flag(argv, nexus), nexus));
		else if (!ft_strcmp(**argv, "-g"))
			(*argv)++;
		else
			return (ft_parse_champ(argv, 0, nexus));
	}
	return (0);
}

void		ft_read_params(char ***argv, t_world *nexus)
{
	uint8_t	parse_stat;

	parse_stat = ft_scan_lines(argv, nexus);
	if (ft_supervise_input(nexus, nexus->champs))
		ft_manage_world(NULL);
}
