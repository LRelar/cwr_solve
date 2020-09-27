/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 22:13:55 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/26 13:43:17 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	Не забывай соблюдать нотацию!
*/

inline static void		ft_control_doubles(t_vasa **errors_head, \
											t_champ *champs, const int current)
{
	int					k;

	k = 0;
	while (k != current)
	{
		if (champs[k].id == champs[current].id)
		{
			ft_err_id_doubled(errors_head, champs[current].name);
			champs[current].id = 0;
			return ;
		}
		k++;
	}
}

/*
**	Logic behind this algo:
**	We start with i == 0 and id == 1;
**	We traverse through array of champs searching champs[i].id == 0;
**	If we found such one, our job is to check if current id is unique.
**	That's where second cycle kicks in: we run through the array yet again,
**	searching champs[k].id == id. If one is found our job to update id (id++)
**	and check new id for being uniq. That's why k=0 under second if.
**	Eventualy we pop out of second while, what leaves us with def-ly unique id
**	that we can use at current champs[i].id.
*/

inline static void		ft_auto_assign(int ch_amount, t_champ *champs)
{
	int					id;
	int					i;
	int					k;

	id = 1;
	i = 0;
	while (i != ch_amount)
	{
		if (!champs[i].id)
		{
			k = 0;
			while (k != ch_amount)
			{
				if (id == champs[k++].id)
				{
					k = 0;
					id++;
				}
			}
			champs[i].id = id++;
		}
		i++;
	}
}

void					ft_check_id(t_vasa **errors_head, \
												t_champ *champs, int ch_amount)
{
	int					i;

	i = ch_amount;
	while (--i != -1)
	{
		if (champs[i].id)
		{
			if (champs[i].id > ch_amount)
			{
				ft_err_id_behind_fighters(errors_head, champs[i].name);
				champs[i].id = 0;
				//* No post-decrement as we have predecr in cycle head.
				continue ;
			}
			ft_control_doubles(errors_head, champs, i);
		}
	}
	ft_auto_assign(ch_amount, champs);
}
