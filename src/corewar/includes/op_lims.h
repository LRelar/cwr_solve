/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lims.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 22:22:58 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/02 12:38:10 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#ifndef OP_LIMS_H
#define IND_SIZE_MAX				8
#define REG_SIZE_MAX				8
#define DIR_SIZE_MAX				8
#define MEM_SIZE_MAX				7864319
#define REG_NUMBER_MAX				32

#if IND_SIZE > IND_SIZE_MAX || IND_SIZE < 1 || \
	REG_SIZE > REG_SIZE_MAX || REG_SIZE < 1 || \
	DIR_SIZE > DIR_SIZE_MAX || DIR_SIZE < 1 || \
	MEM_SIZE > MEM_SIZE_MAX || MEM_SIZE < 341
#define FAULT_LAUNCH
#else
#define NOMINAL_LAUNCH
#endif

#endif
