/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_term_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:18:16 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/03 17:50:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>


inline static int	ft_get_term_width(void)
{
	struct winsize	ws_out;
	int				res;

	ft_bzero(&ws_out, sizeof(struct winsize));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws_out);
	res = (int)ws_out.ws_col;
	if (!res)
		res = 80;
	return (res);
}
#define TWENT "20202020202020202020"
#define THIRT "303030303030303030303030303030"
int		main(void)
{
	int	width;

	width = ft_get_term_width();
	ft_printf_fd(2, "=>{red}%*s{eoc}\n", \
			ALIGN_MID(ft_strlen(WRN_HDR)), WRN_HDR);
	ft_printf_fd(2, "=>{red}%*s{eoc}\n", \
			ALIGN_MID(ft_strlen(WRN_BDY)), WRN_BDY);
	ft_printf_fd(2, "\033[1mNAME{eoc}\n\tcorewar %s", \
			"-- battle arena for corewar game.");
	ft_printf_fd(2, "\n\033[1mSYNOPSIS{eoc}\n\t%s\n", \
			MAN_SYN);
	ft_printf_fd(2,"\033[1mDESCRIPTION{eoc}\n\t%s%s", \
			MAN_DESC_1, MAN_DESC_2);
	ft_printf_fd(2, "%s%s%s%s", \
			MAN_DESC_3, MAN_DESC_4, MAN_DESC_5, MAN_DESC_6);
	ft_printf_fd(2, "%s%s%s%s%s", \
			MAN_DESC_7, MAN_DESC_8, MAN_DESC_9, MAN_DESC_10);
	ft_printf_fd(2, MAN_DESC_11, MAX_PLAYERS);

/*
**	//TODO: Убрать в функцию обработки стэка ошибок.
*/
	ft_printf_fd(2, \
			"%s\n%s%s", ERR_DESC_1, ERR_DESC_2, ERR_DESC_3);

	return (0);
}