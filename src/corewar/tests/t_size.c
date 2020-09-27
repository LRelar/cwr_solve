/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:00:33 by mschimme          #+#    #+#             */
/*   Updated: 2020/05/05 16:10:02 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deblib.h>


int main (void)
{
	char buff[4] = { 0, 0, 0x02, 0x23};
	int *ptr = &buff[0];
	DEBintt(*ptr)
	char anot[4] = { 0x02, 0x23, 0, 0};
	ptr = &anot[0];
	DEBintt(*ptr)
	char yeta[4] = { 0x23, 0x02, 0, 0};
	ptr = &yeta[0];
	DEBintt(*ptr)
	return (0);
}