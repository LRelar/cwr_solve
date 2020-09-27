/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctrl_detect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:57:26 by mschimme          #+#    #+#             */
/*   Updated: 2020/05/06 18:09:49 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int main (void)
{
	char *buff[] = { \
					"This string has no any control characters at all. And it's quite a long for a string.", \
					"T\x0Ahis string has a control character in the beggining (close to it, anyway).", \
					"This string is formed the way, a control \x0A appeared as a part of machine word.", \
					"This string is designed to detect a control symbol in the end \n", \
					NULL };
	for (int i = 0; buff[i]; i++)
	{
		DEBtextt(buff[i]) DEBintt(ft_ctrl_detect(&buff[i][0], ft_strlen(buff[i]))) DEBend()
	}
	return (0);
}