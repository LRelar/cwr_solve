/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_while_preinc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:16:12 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/10 20:45:51 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

inline static void	ft_init_structs(t_champ *champ_row, int size)
{
	for (int i = 0; i != size; i++)
		champ_row[i].id = i;
	
	champ_row[3].id = 0;
	champ_row[0].id = 3;
}

int		main(void)
{
	int i = -1;
	while (++i != 10)
	{
		if (!(i % 3))
		{
			DEBmesst("We've fallen in %%3 exception.") DEBend()
		}
		if (!(i % 7))
		{
			DEBmesst("We've fallen in %%7 exception. Continure here.") DEBend()
			i += 2;
			continue ;
		}
	}

/*
**	Праверка работы постинкремента в структуре
*/
{
	t_champ		ch_arr[5];
	int			i, k, id;

	i = k = id = 0;
	ft_bzero(ch_arr, sizeof(ch_arr));
	ft_init_structs(&ch_arr[0], 5);

	while (i != 5)
	{
		if (!ch_arr[i].id)
		{
			k = 0;
			while (k != 5)
				if (id == ch_arr[k++].id)
				{
					k = 0;
					id++;
				}
			ch_arr[i].id = id++;
		}
		i++;
	}
}
	return (0);
}