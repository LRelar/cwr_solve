/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwr_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:26:17 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/20 15:14:22 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CWR_DEFS_H

# define CWR_DEFS_H
# include "cwr.h"
# include "op.h"

/*
**	Forbidden defines:
**	# define _INT_OVF(x) (int)(x) != x
**	# define DESC_BLOCK PROG_NAME_LENGTH + COMMENT_LENGTH
*/

# define _VALID_EXTENSION_ ".cor"
# define DESC_BLOCK 2176

/*
**	KNOWN_OPS	- amount of operations, recognized by the VM.
**	OPC_SIZE	- size of OP_CODE entry on the arena (in bytes);
**	OPCB_SIZE	- size of operands coding byte entry on the arena (in bytes);
*/

# define KNOWN_OPS 17
# define OPC_SIZE 1
# define OPCB_SIZE 1

/*
**	Tested in t_calc_addr.c
**	Considered forbidden.
**	Reformed in function ft_calc_addr.
**	# define CALC_ADDR(x) (((x) % MEM_SIZE) + MEM_SIZE * ((x) < 0))
**	Reformed in function ft_step_size
**	# define STEP_SZ(x, y) ((x) == T_REG) + ((x) == T_DIR) * (y) + ((x) == T_IND) * 2

*/

# define VALID_REG(x) (arena[CALC_ADDR(x)] > 0) * (arena[CALC_ADDR(x)] <= REG_NUMBER)

/*
**	Returns either 0, or a value
*/

# define VALID_OP_CODE(x, y) ((x) >= 0 && (x) < (y)) * (x)

/*
**	DATA TYPE, which base is determined by op.h values.
*/

# if REG_SIZE < 5
#  define RTP int32_t
#  define URTP uint32_t
# else
#  define RTP int64_t
#  define URTP int64_t
# endif

# define _SEP_TYPE RTP

typedef struct s_world		t_world;
typedef struct s_champ		t_champ;
typedef struct s_carry		t_carry;
typedef struct s_cycle		t_cycle;
typedef struct s_error		t_error;
typedef struct s_vasa		t_vasa;
typedef struct s_dvasa		t_dvasa;
typedef struct s_op			t_op;
typedef void				t_err_rout(t_vasa **head, void *object);
typedef void				t_op_rout(t_world *nexus, t_carry *carry, \
										t_dvasa *head, t_dvasa **vacant);
typedef void				t_carry_cont_rout(t_dvasa *leafnode, \
												t_vasa *carry_cont);
typedef RTP					t_swap_endian_rout(RTP value);

# ifndef VASA_H
#  define VASA_H

union						u_generic
{
	void					*content;
	t_carry					*carry;
	t_error					*error;
	t_vasa					*vasa;
	size_t					cyc_sol;											// Дженерик сам по себе является хранилищем данных типа size_t (хранит номер выгружаемого цикла.)
	size_t					*cyc_arr;											// Дженерик выступает в роли указателя на массив 
};
# endif

typedef enum
{
	false,
	true
}							t_bool;

/*
**	Add '	uint8_t					TEMP_has_codebyte;' for t_calc_op_length
**	to get working.
*/

struct						s_op
{
	size_t					cooldown;
	uint8_t					ops_amount;
	uint8_t					t_dir_size;
	uint8_t					ops_types[4];
	RTP						operands[4];
	intptr_t				length;
};

struct						s_vasa
{
	union u_generic			gen;
	size_t					content_size;
	struct s_vasa			*next;
};

struct						s_error
{
	char					*argv_tar;											// Указывает на объект ARGV, который оказался ошибочным.
	char					*errmessage;										// Тело мессаги, которую надлежит вывести при отработке ошибок.
};

/*
?		Не нужен при переделке s_dvasa.
*/
union						u_morph
{
	t_vasa					*un_vasa;
	t_dvasa					*du_vasa;
};

/*
TODO:	Переделать. СМ ft_add_offspring. left не нужен.
*/
struct						s_dvasa
{
	union u_generic			gen;
	size_t					content_size;
	union u_morph			left;
	union u_morph			right;
};

struct						s_cycle
{
	size_t					cycle;												// Текущий цикл. Для производительности есть смысл его убрать в функцию переменной.
	size_t					next_check;											// № Цикла, в котором очередная проверка.
	size_t					cyc_to_die;											// Cycles to die (относится к жизням кареток)
	size_t					cycle_delta;
	size_t					lives_done;											// Количество выполненных live инструкций. Должно обнуляться после каждой проверки. Определяет, уменьшать ли cycles to die после очереной проверки.
	size_t					num_of_checks;										// Количество проведенных проверок. Должно обнуляться после каждой проверки, которой уменьшилось cycles to die.
	t_vasa					*cyc_to_dump;										// Относится к флагу -dump. для (while (1) для работы виртуалки, внутри проверка if (cycle XOR cyc_to_dump);
};

struct						s_carry												//! UNDER CONSTRUCTION!
{
	int						id;													// Задается при инциализации каретки.
	RTP						reg[REG_NUMBER];
	intptr_t				pos;
	t_op					*op_cont;
	uint8_t					op;													//? ОПКОД операции, на которую смотрит каретка в данный момент (запись этого барахла - дважды - сразу после отработки предыдущей, а также прямо перед отработкой.)
	t_bool					carry_flag;
	size_t					last_live_op;										// Указывает на номер цикла, в котором каретка последний раз пинговалась живой.
	size_t					exec_cyc;											// Номер цикла, в котором подлежит исполнению операция (чтения оп-кода / выполнения инструкции)
	t_champ					*parent;											// Указывает на чемпиона-родителя. Через указатель следует проверять правомерность регистрации live в отношении бота.
};

/*
**	.body	- ptr to champion's executable body (not on arena)
**	.size	- nominal size (value parced from file, must be checked)
*/

struct						s_champ
{
	int32_t					id;
	t_bool					alive;
	RTP						size;
	char					*name;
	char					*desc;
	uint8_t					*body;
	size_t					lives_now;
};

/*
**	uint8_t	flags:
**	Description of each bit goes in descending: from the highest to lowest.
**	1:						0:
**	1:						0:
**	1:						0:
**	1:						0:
**	1:						0:
**	1:						0:
**	1:						0:
**	1:	Dump arena.			0:	Announce Battle victor.
*/

struct						s_world
{
	char					*progname;
	uint8_t					flags;												// Пока рудимент, что-то пихать сюда смысла нет.
	t_champ					champ[MAX_PLAYERS];
	t_champ					**champ_ord;										// Массив указателей размера champs с отсартированными по id чемпионами. champs[3]->id == 3, champs[2]->id == 2 
	int						champs;
	uint8_t					arena[MEM_SIZE];
	t_champ					*survivor;											// Последний заявивший о своей жизни.
	t_vasa					*carry;												// Указатель на carry, которую надлежит проверять на исполнение.
	t_vasa					*errors;											// Цепочка ошибок, обнаруженных при парсинге строки. 
	t_cycle					cyc;
};

#endif
