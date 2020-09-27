/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_chaingun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 14:10:25 by mschimme          #+#    #+#             */
/*   Updated: 2020/06/28 15:30:39 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <cwr.h>

typedef void*	t_gun_rout(void);
typedef t_gun_rout*	ammo(void);

t_gun_rout*	my_gun(void)
{
	static int i;

	if (i++ < 10)
		return (&my_gun);
	return (NULL);
}

int		main(void)
{
	t_gun_rout* tratata = NULL;
	
	while ((ammo *)(tratata)())
	{

	}
	return (0);
}
