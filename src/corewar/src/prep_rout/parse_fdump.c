/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:37:07 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 01:18:01 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	Obsolete and forbidden defines:
**	#define _ENDS_WITH_COMA(x) *(x + ft_strlen(x) - 1) == ','
*/

/*
**	Я использую ft_lstadd для создания очередного сосуда (t_vasa), поскольку
**	данные типа t_list и t_vasa - однородные.
*/

/*
*	ПРОВЕРИЛ.
*/

inline static void	ft_add_step_container(t_vasa **chain_head)
{
	t_vasa			*step;

	step = *chain_head;
	ft_lstadd((t_list **)chain_head, ft_lstnew_r(NULL, 0));
	if (*chain_head == step)
	{
		ft_err_malloc("new_head for cyc_to_dump", "ft_lstnew_r");
		ft_manage_world(NULL);
	}
}

/*
** //? Проверил. Не все ОК со вложенными функциями.
*/

inline static uint8_t	ft_register_fdump_param(char *argv, long long *value, t_vasa **error_head)
{
	uint8_t				flag;

	flag = 0;
	if (ft_are_digits(argv))
	{
		*value = ft_atol_r(argv, &flag);
		if (((int)(*value) != *value) || flag)
		{
			ft_err_fdump_inter(error_head, argv);
			flag = 2;
		}
	}
	else
	{
		flag = 3;
		ft_err_fdump_notnbr(error_head, argv);
	}
	return (flag);
}

/*
**	Если за -dump следовал не положительный INT, мы записываем ошибку.
**	Если проверка параметра -dump завершилась выявлением переполнение, или без
**	ошибок, мы итерируем argv/
**	Такой подход обеспечивает возможностью влюбом случае продолжить работу
**	проигнорировав кривой параментр, но запомнить факт ошибки и выдать MAN
**	перед отработкой тела программы.
*/
/*
* Проверил.
*/
uint8_t				ft_parse_fdump(char ***argv, t_world *nexus)
{
	long long		cycle;
	static size_t	counter;
	uint8_t			flag;

	++*argv;
	flag = ft_register_fdump_param(**argv, &cycle, &nexus->errors);
	if (flag != 3)
		++*argv;
	if (!flag)
	{
		ft_add_step_container(&nexus->cyc.cyc_to_dump);
		nexus->cyc.cyc_to_dump->gen.cyc_sol = (size_t)cycle;
		nexus->cyc.cyc_to_dump->content_size = ++counter;
		nexus->flags |= 1;
		return (ft_scan_lines(argv, nexus));
	}
	ft_scan_lines(argv, nexus);
	return (flag);
}

/*
**	Старая версия. Предположительно хотел сделать гибкий парсер по примеру 
**	ft_printf.
*/

/*
**	void			ft_parse_fdump(char ***argv, t_world *nexus)
**	{
**		if (ft_got_interval(argv, nexus))
**			return (ft_parse_fdump(argv, nexus));
**		else if (ft_got_set(argv, nexus))
**		return (ft_parse_fdump(argv, nexus));
**	else if (ft_got_number(argv, nexus))
**		return (ft_parse_fdump(argv, nexus));
**	else
**		return (0);
**	}
*/

/*
**	Старая недоделанная версия, которая не дает гибкий -dump.
*/

/*
**	void				ft_parse_fdump(char ***argv, t_world *nexus)
**	{
**	t_vasa			*curr;
**	static size_t	counter;
**
**	while (ft_are_digits(*++*argv))
**	{
**		curr = nexus->cyc.cyc_to_dump;
**		ft_lstadd((t_list **)&nexus->cyc.cyc_to_dump, ft_lstnew_r(NULL, 0));
**		if (nexus->cyc.cyc_to_dump == curr)
**		{
**			ft_err_malloc("new_head for cyc_to_dump", "ft_lstnew_r");
**			ft_manage_world(NULL);
**		}
**		nexus->cyc.cyc_to_dump->gen.cyc_sol = (size_t)ft_atoi(**argv);
**		nexus->cyc.cyc_to_dump->content_size = ++counter;
**		++*argv;
**	}
**	else
**		ft_err_fdump(&nexus->errors, **argv);
**	}
*/


/*
**	In content_size at this time current length of chain is written.
**	After all -dump vslus are harvested
**	Я вообще не помню, зачем эта функция. А вспомнил, я хотел прикрутить
**	возможность вывода нескольких ходов за раз, интервал ходов и прочее...
**	собственно got_interval - функция обработки инетервала выгружаемых
**	ходов.
*/

/*
**	uint8_t			ft_got_interval(char ***argv, t_world *nexus)
**	{
**		char		*sep;
**		long long	left;
**		long long	right;
**		size_t		length;
**	
**		if ((sep = ft_strchr(**argv, '-')) && \
			(ft_strchrcount(**argv, '-') == 1) \
**			&& ft_are_ndigits(**argv, sep) && ft_are_digits(sep + 1))
**		{
**			left = 0;
**			right = 0;
**			length = ft_strlen(**argv);
**			if (ft_antoi(**argv, sep, &left) || _INT_OVF(left) \
**				|| ft_antoi((const char *)sep, **argv + length, &right) || \
**				_INT_OVF(right) \
**				|| right < left)
**			{
**				ft_err_fdump_inter(&nexus->errors, **argv);
**				++*argv;
**				return (1);
**			}
**			while (left <= right)
**				ft_add_cyclist(&nexus->cyc.cyc_to_dump, right--);
**			++*argv;
**			return (_ENDS_WITH_COMA(**argv));
**		}
**		return (0);
**	}
*/