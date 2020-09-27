/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_comp_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:47:02 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 00:47:21 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <cwr_man.h>

void		ft_show_compconf(void)
{
	ft_printf_fd(2, "\033[1mNAME{eoc}\n\tcorewar %s", \
			"-- battle arena for corewar game.");
	ft_printf_fd(2, "\n\033[1mSYNOPSIS{eoc}\n\t%s\n", \
			MAN_SYN);
	ft_printf_fd(2, "\033[1mCOMPILATION CONFIGURATION{eoc}\n\t%s\n\n", \
			CONF_DESC_1);
	ft_printf_fd(2, "%s%d%s\n", CONF_DESC_2, REG_SIZE, CONF_DESC_3);
	ft_printf_fd(2, "%s%d%s\n", CONF_DESC_4, IND_SIZE, CONF_DESC_5);
	ft_printf_fd(2, "%s%d%s\n", CONF_DESC_6, DIR_SIZE, CONF_DESC_7);
	ft_printf_fd(2, "%s%d%s\n", CONF_DESC_8, MAX_PLAYERS, CONF_DESC_9);
	ft_printf_fd(2, "%s%d%s\n", CONF_DESC_10, MEM_SIZE, CONF_DESC_11);
}
