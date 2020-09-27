/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_array_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:45:29 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/23 22:35:07 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#define PTR_ST ptrs[0]
#define PTR_EN ptrs[1]

inline static size_t	ft_build_nonz_arr(t_champ *champ_head, int champs, int **start)
{
	int					*ptr;
	int					i;

	if (!(*start = (int *)ft_memalloc((champs + 1) * sizeof(int))))
	{
		ft_err_malloc(__ERR(buff), __func__);
		ft_manage_world(NULL);
	}
	i = 0;
	ptr = *start;
	while (i != champs)
	{
		if (champ_head[i].id != 0)
			*ptr++ = champ_head[i].id;
		i++;
	}
	ft_srt_bubble_intarr(*start, ptr - *start, &ft_intp_left_grt_right);
	return (ptr - *start);
}

inline static int	ft_assign_new_id(int *arr, size_t size)
{
	static int i;
	uint8_t flag;
	size_t		k;

	flag = 1;
	while (flag)
	{
		flag = 0;
		k = 0;
		while (k < size)
		{
			flag = arr[k] == i;
			i += arr[k] == i;
			if (flag)
				break ;
		}
	}
}

inline static void	ft_assign_champ_ids(t_champ *champ_head, int champs)
{
	int				*arr;
	size_t			size;
	int				i;
	
	i = 0;
	arr = NULL;
	size = ft_build_nonz_arr(champ_head, champs, &arr);
	
	while (i != champs)
	{
		if (!champ_head[i].id)
			champ_head[i].id = ft_assign_new_id(arr, size);
		i++;
	}
}

void			ft_prep_battle(t_world *nexus, int champs)
{
	ft_assign_champ_ids(&nexus->champ[0], champs);
	
	// ft_sort_dumps(&nexus->cyc.cyc_to_dump);
	// ft_place_champs(&nexus)
}


int			main(void)
{
	t_world nexus;

	ft_bzero(&nexus, sizeof(nexus));
	nexus.champ[0].id = 0;
	nexus.champ[1].id = 10;
	nexus.champ[2].id = 1;
	nexus.champ[3].id = 7;
	ft_prep_battle(&nexus, 4);
	return (0);
}