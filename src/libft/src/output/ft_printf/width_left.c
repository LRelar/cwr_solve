/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:05:35 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:45:18 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Forbidden defines:
**	#define ADDMAX formstat->result + *max
**	#define BSIZE sizes[0]
**	#define CSIZE sizes[1]
**	#define WIDTH format->width
*/

static inline void		ft_place_filler(int width, char *fillers, int fd)
{
	while ((width))
	{
		while (width > 8)
		{
			filling_mainbuf(fillers, 8, 0, fd);
			width -= 8;
		}
		filling_mainbuf(fillers, width, 0, fd);
		width = 0;
	}
}

static inline uint8_t	ft_check_limits(t_format *formstat, \
								int width, size_t *sizes)
{
	int					newres;
	int					max;

	newres = 0;
	if (sizes[0] > INT32_MAX)
		return (ft_err_varoverflow("vari_strlen", __func__));
	max = (sizes[1] < (size_t)width) * ((size_t)width + sizes[0] - sizes[1]) + \
										(sizes[1] >= (size_t)width) * sizes[0];
	if (ft_check_add_ovf(&newres, formstat->result, max))
		return (ft_err_varoverflow("ADDMAX", __func__));
	formstat->result = newres;
	return (0);
}

void					ft_width_left(t_format *formstat, t_fword *format, \
									size_t *dims, char *formatted_variative)
{
	size_t				sizes[2];
	char				arr[8];

	sizes[0] = dims[0];
	if (ft_wdetect((const char *)formatted_variative, sizes[0]))
		sizes[1] = ft_wstrlen((const char *)formatted_variative);
	else
		sizes[1] = sizes[0];
	if (ft_check_limits(formstat, format->width, &sizes[0]))
		formstat->errflag = 1;
	ft_memset(&arr[0], format->filler, 8);
	if (formstat->errflag)
		return ;
	ft_place_filler((format->width > (int)sizes[1]) * \
					(format->width - (int)sizes[1]), &arr[0], formstat->fd);
	filling_mainbuf(formatted_variative, dims[1], 0, formstat->fd);
}
