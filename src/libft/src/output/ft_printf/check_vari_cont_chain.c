/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vari_cont_chain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:16:00 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 22:05:48 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Here the bucks chain (k $) is checked for integrity and uniqueness
** links.
** vari_cont_chain checks that the bucks chain is, firstly,
** sorted (1-> 2-> 3-> 4), and secondly, it was compensated if
** turned out to be non-integral (type type: 1-> 2-> 4-> 5-> 10).
** Compensation is set by the vari_interval variable, which determines how much
** missing links (how many times does the current va_list need to be iterated to
** the next call clings to the desired (in a row) va_arg.)
**
** check_consistency checks the chain for uniqueness of links.
** If a non-unique link is caught (full copy, for example, in 2 different words
** format we call the same argument), then its older version
** deleted (older, appeared earlier, therefore it will be further in the chain).
** If non-unique links that are accessed inconsistently
** (in one case, as a float, in the other, as an integer.)
** Then, again, the older record will be deleted, but will be announced
** corresponding warning in std_err.
*/

/*
** I removed the check, because, in theory, it’s superfluous.
** In the parent function we are in the cycle will not go if there is no next.
*/

inline static uint8_t	ft_check_consistency(t_varitype *ptr, \
																uint8_t *flag)
{
	t_varitype			*subst;

	subst = ptr->next;
	if (ptr->vari_num == subst->vari_num)
	{
		if (ptr->iterator != subst->iterator)
			*flag = 1;
		ptr->next = subst->next;
		free(subst);
		return (1);
	}
	return (0);
}

static inline void		ft_fill_in_dummy_cont(t_varitype *inserted, \
						t_varitype *next, int num)
{
	inserted->next = next;
	inserted->vari_interval = 1;
	inserted->iterator = &ft_skip_va_arg_int;
	inserted->vari_num = num;
}

static inline uint8_t	ft_check_first_exists(t_format *formstat, \
																uint8_t *flag)
{
	t_varitype			*ptr;

	if (formstat->first->vari_num != 1)
	{
		*flag = 1;
		if (!(ptr = (t_varitype *)ft_memalloc(sizeof(t_varitype))))
		{
			ft_err_malloc("ptr", __func__);
			return ((formstat->errflag = 1));
		}
		ft_fill_in_dummy_cont(ptr, formstat->first, 1);
		formstat->first = ptr;
		return (0);
	}
	return (0);
}

void					ft_check_vari_cont_chain(t_format *formstat)
{
	uint8_t				flag;
	t_varitype			*ptr;

	flag = 0;
	if (!(formstat->first))
		return ;
	if (ft_check_first_exists(formstat, &flag))
		return ;
	ptr = formstat->first;
	while (ptr && ptr->next)
	{
		if (ft_check_consistency(ptr, &flag))
			continue ;
		if (ptr->vari_num != (ptr->next->vari_num - 1))
		{
			flag = 1;
			ptr->vari_interval = ptr->next->vari_num - ptr->vari_num;
		}
		ptr = ptr->next;
	}
	if (flag)
		ft_err_broken_chain();
}
