/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 23:23:12 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/06 21:03:08 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use ft_isdigit and ft_isalpha, thus we
** need libft.h in order to include them.
*/

int			ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
