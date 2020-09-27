/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_check_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:43:15 by mschimme          #+#    #+#             */
/*   Updated: 2020/06/30 19:45:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>


int		main(void)
{
	t_champ lolkekcheburek;
	t_champ *ptr;

	ft_bzero(&lolkekcheburek, sizeof(t_champ));
	lolkekcheburek.size = 32;
	ptr = &lolkekcheburek;
	
	size_t	check = (size_t)ptr->size;
	DEBlt(check); DEBend()
	return (0);
}