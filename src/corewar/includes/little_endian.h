/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_endian.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 08:49:28 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/20 15:13:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTLE_ENDIAN_H
# define LITTLE_ENDIAN_H

# include <cwr.h> 
RTP	ft_swap_endian_one(RTP value);
RTP	ft_swap_endian_two(RTP value);

RTP	ft_swap_endian(RTP value, uintptr_t size);

/*
**			Designations.
**	_F - First;
**	_D - Duo;
**	_T - Third;
**	_Q - Quad (Fourth)
**	_P - Penta (Fith)
**	_H - Hexa (Sixth)
**	_S - Septima (Seventh)
**	_O - Octa (Eight)
**	_R - Right
**	_L - Left
**	_M - Middle
*/

/*
**	We don't need to normalize data (according to REG_SIZE) as normalization is
**	built in the conversion.
*/

# if REG_SIZE == 1
# define _SW_F(x) ((uint32_t)(x) & 0xff)
# define _SUPP_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffffff << 8)
# define _SW_ENDIAN(x) _SW_F(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 2
# define _SW_D(x) (((uint32_t)(x) & 0x0000ff00) >> 8)
# define _SW_F(x) (((uint32_t)(x) & 0x000000ff) << 8)
# define _SUPP_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffff << 16)
# define _SW_ENDIAN(x) _SW_D(x) | _SW_F(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 3
# define _SW_T(x) (((uint32_t)(x) & 0x00ff0000) >> 16)
# define _SW_D(x) ((uint32_t)(x) & 0x0000ff00)
# define _SW_F(x) (((uint32_t)(x) & 0x000000ff) << 16)
# define _SUPP_NEG(x) (((((uint32_t)(x) & 0x80) >> 7) * 0xff) << 24)
# define _SW_ENDIAN(x) _SW_F(x) | _SW_D(x) | _SW_T(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 4
# define _SW_F(x) (((uint32_t)(x) & 0xff000000) >> 24)
# define _SW_D(x) (((uint32_t)(x) & 0x00ff0000) >> 8)
# define _SW_T(x) (((uint32_t)(x) & 0x0000ff00) << 8)
# define _SW_Q(x) (((uint32_t)(x) & 0x000000ff) << 24)
# define _SW_ENDIAN(x) _SW_F(x) | _SW_D(x) | _SW_T(x) | _SW_Q(x)

#endif

# if REG_SIZE == 5
# define _SW_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 32)
# define _SW_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 16)
# define _SW_T(x) ((uint64_t)(x)  & 0x0000000000ff0000)
# define _SW_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 16)
# define _SW_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 32)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffffff) << 40)
# define _SW_RIGHT(x) _SW_P(x) | _SW_Q(x)
# define _SW_MID(x) _SW_T(x)
# define _SW_LEFT(x) _SW_D(x) | _SW_F(x)
# define _SW_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 6
# define _SW_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 40)
# define _SW_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 24)
# define _SW_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 8)
# define _SW_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 8)
# define _SW_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 24)
# define _SW_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 40)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffff) << 48)
# define _SW_RIGHT(x) _SW_H(x) | _SW_P(x)
# define _SW_MID(x) _SW_Q(x) | _SW_T(x)
# define _SW_LEFT(x) _SW_D(x) | _SW_F(x)
# define _SW_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 7
# define _SW_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 48)
# define _SW_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 32)
# define _SW_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 16)
# define _SW_Q(x)  ((uint64_t)(x) & 0x00000000ff000000)
# define _SW_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 16)
# define _SW_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 32)
# define _SW_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 48)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xff) << 56)
# define _SW_RIGHT(x) _SW_S(x) | _SW_H(x) | _SW_P(x)
# define _SW_MID(x) _SW_Q(x)
# define _SW_LEFT(x) _SW_T(x) | _SW_D(x) | _SW_F(x)
# define _SW_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if REG_SIZE == 8
# define _SW_O(x) (((uint64_t)(x) & 0xff00000000000000) >> 56)
# define _SW_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 40)
# define _SW_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 24)
# define _SW_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 8)
# define _SW_Q(x) (((uint64_t)(x) & 0x00000000ff000000) << 8)
# define _SW_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 24)
# define _SW_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 40)
# define _SW_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 56)
# define _SW_RIGHT(x) _SW_O(x) | _SW_S(x) | _SW_H(x)
# define _SW_MID(x) _SW_P(x) | _SW_Q(x)
# define _SW_LEFT(x) _ST_T(x) | _SW_D(x) | _SW_F(x)
# define _SW_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x)

#endif

# if IND_SIZE == 1
# define _SWI_F(x) ((uint32_t)(x) & 0xff)
# define _SUPPI_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffffff << 8)
# define _SWI_ENDIAN(x) _SWI_F(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 2
# define _SWI_D(x) (((uint32_t)(x) & 0x0000ff00) >> 8)
# define _SWI_F(x) (((uint32_t)(x) & 0x000000ff) << 8)
# define _SUPPI_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffff << 16)
# define _SWI_ENDIAN(x) _SWI_D(x) | _SWI_F(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 3
# define _SWI_T(x) (((uint32_t)(x) & 0x00ff0000) >> 16)
# define _SWI_D(x) ((uint32_t)(x) & 0x0000ff00)
# define _SWI_F(x) (((uint32_t)(x) & 0x000000ff) << 16)
# define _SUPPI_NEG(x) (((((uint32_t)(x) & 0x80) >> 7) * 0xff) << 24)
# define _SWI_ENDIAN(x) _SWI_F(x) | _SWI_D(x) | _SWI_T(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 4
# define _SWI_F(x) (((uint32_t)(x) & 0xff000000) >> 24)
# define _SWI_D(x) (((uint32_t)(x) & 0x00ff0000) >> 8)
# define _SWI_T(x) (((uint32_t)(x) & 0x0000ff00) << 8)
# define _SWI_Q(x) (((uint32_t)(x) & 0x000000ff) << 24)
# define _SWI_ENDIAN(x) _SWI_F(x) | _SWI_D(x) | _SWI_T(x) | _SWI_Q(x)

#endif

# if IND_SIZE == 5
# define _SWI_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 32)
# define _SWI_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 16)
# define _SWI_T(x) ((uint64_t)(x)  & 0x0000000000ff0000)
# define _SWI_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 16)
# define _SWI_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 32)
# define _SUPPI_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffffff) << 40)
# define _SWI_R(x) _SWI_P(x) | _SWI_Q(x)
# define _SWI_M(x) _SWI_T(x)
# define _SWI_L(x) _SWI_D(x) | _SWI_F(x)
# define _SWI_ENDIAN(x) _SWI_R(x) | _SWI_M(x) | _SWI_L(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 6
# define _SWI_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 40)
# define _SWI_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 24)
# define _SWI_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 8)
# define _SWI_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 8)
# define _SWI_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 24)
# define _SWI_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 40)
# define _SUPPI_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffff) << 48)
# define _SWI_R(x) _SWI_H(x) | _SWI_P(x)
# define _SWI_M(x) _SWI_Q(x) | _SWI_T(x)
# define _SWI_L(x) _SWI_D(x) | _SWI_F(x)
# define _SWI_ENDIAN(x) _SWI_R(x) | _SWI_M(x) | _SWI_L(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 7
# define _SWI_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 48)
# define _SWI_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 32)
# define _SWI_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 16)
# define _SWI_Q(x)  ((uint64_t)(x) & 0x00000000ff000000)
# define _SWI_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 16)
# define _SWI_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 32)
# define _SWI_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 48)
# define _SUPPI_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xff) << 56)
# define _SWI_R(x) _SWI_S(x) | _SWI_H(x) | _SWI_P(x)
# define _SWI_M(x) _SWI_Q(x)
# define _SWI_L(x) _SWI_T(x) | _SWI_D(x) | _SWI_F(x)
# define _SWI_ENDIAN(x) _SWI_R(x) | _SWI_M(x) | _SWI_L(x) | _SUPPI_NEG(x)

#endif

# if IND_SIZE == 8
# define _SWI_O(x) (((uint64_t)(x) & 0xff00000000000000) >> 56)
# define _SWI_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 40)
# define _SWI_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 24)
# define _SWI_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 8)
# define _SWI_Q(x) (((uint64_t)(x) & 0x00000000ff000000) << 8)
# define _SWI_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 24)
# define _SWI_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 40)
# define _SWI_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 56)
# define _SWI_R(x) _SWI_O(x) | _SWI_S(x) | _SWI_H(x)
# define _SWI_M(x) _SWI_P(x) | _SWI_Q(x)
# define _SWI_L(x) _ST_T(x) | _SWI_D(x) | _SWI_F(x)
# define _SWI_ENDIAN(x) _SWI_R(x) | _SWI_M(x) | _SWI_L(x)

#endif



/*
TD:	UNDER CONSTRUCTION
*/

# if DIR_SIZE == 1
# define _SWD_F(x) ((uint32_t)(x) & 0xff)
# define _SUPP_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffffff << 8)
# define _SWDL_ENDIAN(x) _SWD_F(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 2
# define _SWD_D(x) (((uint32_t)(x) & 0x0000ff00) >> 8)
# define _SWD_F(x) (((uint32_t)(x) & 0x000000ff) << 8)
# define _SUPP_NEG(x) ((((uint32_t)(x) & 0x80) >> 7) * 0xffff << 16)
# define _SWDL_ENDIAN(x) _SWD_D(x) | _SWD_F(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 3
# define _SWD_T(x) (((uint32_t)(x) & 0x00ff0000) >> 16)
# define _SWD_D(x) ((uint32_t)(x) & 0x0000ff00)
# define _SWD_F(x) (((uint32_t)(x) & 0x000000ff) << 16)
# define _SUPP_NEG(x) (((((uint32_t)(x) & 0x80) >> 7) * 0xff) << 24)
# define _SWDL_ENDIAN(x) _SWD_F(x) | _SWD_D(x) | _SWD_T(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 4
# define _SWD_F(x) (((uint32_t)(x) & 0xff000000) >> 24)
# define _SWD_D(x) (((uint32_t)(x) & 0x00ff0000) >> 8)
# define _SWD_T(x) (((uint32_t)(x) & 0x0000ff00) << 8)
# define _SWD_Q(x) (((uint32_t)(x) & 0x000000ff) << 24)
# define _SWDL_ENDIAN(x) _SWD_F(x) | _SWD_D(x) | _SWD_T(x) | _SWD_Q(x)

#endif

# if DIR_SIZE == 5
# define _SWD_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 32)
# define _SWD_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 16)
# define _SWD_T(x) ((uint64_t)(x)  & 0x0000000000ff0000)
# define _SWD_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 16)
# define _SWD_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 32)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffffff) << 40)
# define _SW_RIGHT(x) _SWD_P(x) | _SWD_Q(x)
# define _SW_MID(x) _SWD_T(x)
# define _SW_LEFT(x) _SWD_D(x) | _SWD_F(x)
# define _SWDL_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 6
# define _SWD_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 40)
# define _SWD_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 24)
# define _SWD_Q(x) (((uint64_t)(x) & 0x00000000ff000000) >> 8)
# define _SWD_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 8)
# define _SWD_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 24)
# define _SWD_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 40)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xffff) << 48)
# define _SW_RIGHT(x) _SWD_H(x) | _SWD_P(x)
# define _SW_MID(x) _SWD_Q(x) | _SWD_T(x)
# define _SW_LEFT(x) _SWD_D(x) | _SWD_F(x)
# define _SWDL_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 7
# define _SWD_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 48)
# define _SWD_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 32)
# define _SWD_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 16)
# define _SWD_Q(x)  ((uint64_t)(x) & 0x00000000ff000000)
# define _SWD_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 16)
# define _SWD_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 32)
# define _SWD_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 48)
# define _SUPP_NEG(x) (((((uint64_t)(x) & 0x80) >> 7) * 0xff) << 56)
# define _SW_RIGHT(x) _SWD_S(x) | _SWD_H(x) | _SWD_P(x)
# define _SW_MID(x) _SWD_Q(x)
# define _SW_LEFT(x) _SWD_T(x) | _SWD_D(x) | _SWD_F(x)
# define _SWDL_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x) | _SUPP_NEG(x)

#endif

# if DIR_SIZE == 8
# define _SWD_O(x) (((uint64_t)(x) & 0xff00000000000000) >> 56)
# define _SWD_S(x) (((uint64_t)(x) & 0x00ff000000000000) >> 40)
# define _SWD_H(x) (((uint64_t)(x) & 0x0000ff0000000000) >> 24)
# define _SWD_P(x) (((uint64_t)(x) & 0x000000ff00000000) >> 8)
# define _SWD_Q(x) (((uint64_t)(x) & 0x00000000ff000000) << 8)
# define _SWD_T(x) (((uint64_t)(x) & 0x0000000000ff0000) << 24)
# define _SWD_D(x) (((uint64_t)(x) & 0x000000000000ff00) << 40)
# define _SWD_F(x) (((uint64_t)(x) & 0x00000000000000ff) << 56)
# define _SW_RIGHT(x) _SWD_O(x) | _SWD_S(x) | _SWD_H(x)
# define _SW_MID(x) _SWD_P(x) | _SWD_Q(x)
# define _SW_LEFT(x) _ST_T(x) | _SWD_D(x) | _SWD_F(x)
# define _SWDL_ENDIAN(x) _SW_RIGHT(x) | _SW_MID(x) | _SW_LEFT(x)

#endif
#endif
