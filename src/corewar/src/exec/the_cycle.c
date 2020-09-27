/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 22:13:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/26 14:52:38 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

#define CURR_CARRY carry_bogey->gen.carry
#define PROP_OP_CODE op_code * (carry_bogey->gen.carry->op != 0)

/*
!	На этот лист - не более 4 функций. Место под 5 -в резерве, если в
	!	ft_process_carry запрещено объявлять и инициализировать static.
*/

#ifndef NDEBUG

static void				tft_leafnode_not_empty(t_dvasa *tree)
{
	if (tree && tree->gen.vasa)
		DEBfunc()
}

static void				tft_newnode_not_empty(t_dvasa *new_node)
{
	if (new_node)
		if (new_node->content_size || new_node->gen.content || \
			new_node->left.un_vasa || new_node->right.du_vasa)
			DEBfunc()
}

#endif


/*
**	Итерация ->next_check имеет защиту через == 0 для случаев, когда мы
**	достигли момента, когда cycle_delta зануляет cycle_to_die.
!	Здесь может быть косяк, так как мы "эмулируем" cycle_to_die == 0:
	! Мы переносим ликвидацию всех кареток на следующий цикл.
*/
inline static void		ft_cycle_control(t_world *nexus, \
											t_dvasa **tree, t_dvasa **vacant)
{
	t_cycle				*cyc_ptr;

	cyc_ptr = &nexus->cyc;
	if (cyc_ptr->cycle == cyc_ptr->next_check)
	{
		/*
		*	ft_tree_undertaker - функция семейства trees/manage_tree. Вычищает дерево от
			* умерших кареток, высвобождает пустые t_dvasa структуры. Обновляет tree
			* и vacant по необхдимости.
		*	По идее здесь должны обновляться все показатели t_cycle, за исключеним
			* счетчика.
		*/
		ft_tree_undertaker(tree, vacant, cyc_ptr);
		if (++cyc_ptr->num_of_checks == MAX_CHECKS || cyc_ptr->lives_done >= NBR_LIVE)
		{
			cyc_ptr->cyc_to_die = (cyc_ptr->cyc_to_die - CYCLE_DELTA) * (cyc_ptr->cyc_to_die >= CYCLE_DELTA);
			cyc_ptr->num_of_checks = 0;
		}
		// предусмотреть итератор на следующую проверку.
	cyc_ptr->next_check += cyc_ptr->cyc_to_die + (cyc_ptr->cyc_to_die == 0);	//? Бесполезная защита
	cyc_ptr->lives_done = 0;
	}
}

/*
TD:	ПРОВЕРИТЬ.
!	СОДЕРЖИТ ТЕСТЫ
!Контракт:
	*.	t_dvasa **tree должна хранить адрес указателя на валидный корень-лифноду.
	*	Лифнода текущего цикла всегда должна блыть выработана (в результате 
		* отработки цикла должна остаться пустой).
*	Выбор исполнителя в op_tab. В самом начале либо сразу после исполнения оче-
	* редной инструкции значение op каретки == 0. Из этого следует, что нам еще
	* не известна функция, которую надлежит исполнять, необходимо считать ее оп-
	* код. Если же в каретке записан какой-то оп-код, значит, что cooldown 
	* циклов этого опкода мы уже считали, сейчас нужно исполнить инструкцию
	* записанную в настоящий момент на арену.
*	Почему так странно итерируемся carry_bogey. Это задел на возможность
	* дополнения corewar инструкцией с кулдауном в 1 цикл. Такая инструкция 
	* должна быть исполнена в тот же цикл, в котором прочитан ее опкод.
	* Аналогично новая каретка, созданная fork или lfork. Она наследует ВСЕ
	* состояния своего родителя, за исклюением своего положения. В том числе и
	* номер цикла исполнения. Потому потомок должен прочитать оп-код своей
	* инструкции сразу после своего рождения.
	* Используемая логика предполагает возможность вставить такие каретки в
	* текущую очередь применением стандартных средств управления очередью.
//:	Добавить обработчик пустого t_dvasa.
*/
inline static void	ft_carry_process(t_world *nexus, t_dvasa **tree, \
															t_dvasa **new_node)
{
	static t_op_rout	*op_tab[KNOWN_OPS] = { &op_new_op, &op_live, &op_ld, \
												&op_st, &op_add, &op_sub, \
												&op_and, &op_or, &op_xor, \
												&op_zjmp, &op_ldi, &op_sti, \
												&op_fork, &op_lld, &op_lldi, \
												&op_lfork, &op_aff };
	uint8_t				op_code;
	t_vasa				*carry_bogey;

	carry_bogey = (*tree)->gen.vasa;
	if (nexus->cyc.cycle == CURR_CARRY->exec_cyc)
	{
		while (carry_bogey)
		{
			(*tree)->gen.vasa = (*tree)->gen.vasa->next;
			op_code = VALID_OP_CODE(nexus->arena[CURR_CARRY->pos], KNOWN_OPS);
			op_tab[PROP_OP_CODE](nexus, CURR_CARRY, *tree, new_node);
			ft_leafnode_pick(carry_bogey, *tree, new_node, &ft_carry_ins_by_id);
			carry_bogey = (*tree)->gen.vasa;
		}
#ifndef NDEBUG
tft_leafnode_not_empty(*tree);
#endif
		ft_leafnode_vacate(tree, new_node);
#ifndef NDEBUG
tft_newnode_not_empty(*new_node);
#endif
	}
}

/*
TODO:	Дописать ft_print_dump.

		! Сейчас используется старая сортировка t_vasa в t_dvasa.
		! Потому актуально наличие ->left.

		! Должна возвращать 1, если кончились cyc_to_dump.
		! Должна итерировать cyc_to_dump.
		! Должна высвобождать t_vasa.
*	Потенциальная сега в первом if цикла (если за каким-то, блядь, хуем,
*	останемся в цикле отработав последний cyc_to_dump)
*/
void		ft_the_cycle(t_world *nexus, t_dvasa *tree)
{
	t_dvasa	*vacant;
	uint8_t	dump_fl;
	t_vasa	*curr_carry;
	curr_carry = NULL;
	vacant = NULL;
	dump_fl = nexus->flags;
	while (tree)
	{
		nexus->cyc.cycle++;
		ft_carry_process(nexus, &tree, &vacant);
		ft_cycle_control(nexus, &tree, &vacant);
		/*
		! Проверка на cycle_to_die. Очистка мертвых (кареток, героев).
		? У нас 3 варианта:
			1. Не осталось живых кареток -> Объявить победителя.
			2. Не осталось живых кареток в текущем цикле...
			3. В текущем цикле остались живые каретки -> ничего не меняется.
		? Возможно есть смысл сравнивать с nexus->cyc.cyc_to_dump->gen.cyc_sol - 1
		*/
		if (dump_fl && nexus->cyc.cycle == nexus->cyc.cyc_to_dump->gen.cyc_sol)
			if (ft_print_dump(&nexus->cyc.cyc_to_dump))
				break ;
	}
}
