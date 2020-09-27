/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_little_endian.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:35:54 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/25 20:59:05 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <cwr.h>
//#include <OSByteOrder.h>

// #define _SW_F(x) (((uint32_t)(x) << 8 & 0xff000000) >> 24)
// #define _SW_S(x) (((uint32_t)(x) << 8 & 0x00ff0000) >> 8)
// #define _SW_T(x) (((uint32_t)(x) << 8 & 0x0000ff00) << 8)
// #define _SW_Q(x) (((uint32_t)(x) & 0x000000ff) << 24)
// #define _SW_ENDIAN(x) _SW_F(x) | _SW_S(x) | _SW_T(x) | _SW_Q(x)

// #define _SW_Q2(x) ((((uint32_t)(x) & 0x80000000) >> 31) * 0xff << 24)
// #define _SW_F2(x) (((((uint32_t)(z) & 0x800000) >> 23) * 0xff) >> 24)
// #define _SW_ENDIAN2(x) (_SW_F2(x) | _SW_S(x) | _SW_T(x) | _SW_Q(x))

// #define _SW_F(x) (((uint32_t)(x) << (8 * (((uint32_t)(x) & 0x800000) >> 23)) & 0xff000000) >> 24)
// #define _SW_S(x) (((uint32_t)(x) << (8 * (((uint32_t)(x) & 0x800000) >> 23)) & 0x00ff0000) >> 8)
// #define _SW_T(x) (((uint32_t)(x) << (8 * (((uint32_t)(x) & 0x800000) >> 23)) & 0x0000ff00) << 8)
// #define _SW_Q(x) (((uint32_t)(x) << (8 * (((uint32_t)(x) & 0x800000) >> 23)) & 0x000000ff) << 24)


// Propper version of swapper
// #define _SW_F(x) ((((uint32_t)(x) << 8) & 0xff000000) >> 24)
// #define _SW_S(x) ((((uint32_t)(x) << 8) & 0x00ff0000) >> 8)
// #define _SW_T(x) ((((uint32_t)(x) << 8) & 0x0000ff00) << 8)
// #define _SW_Q(x) ((	/*(((uint32_t)(x) << 8) & 0x000000ff) |*/ ((((uint32_t)(x) & 0x80) >> 7) * 0xff)) << 24)
// #define _SW_ENDIAN(x) _SW_F(x) | _SW_S(x) | _SW_T(x) | _SW_Q(x)


// NEW VERSION OF SWAPPER
// #define _SW_T(x) (((uint32_t)(x) & 0x00ff0000) >> 16)
// #define _SW_S(x) ((uint32_t)(x) & 0x0000ff00)
// #define _SW_F(x) (((uint32_t)(x) & 0x000000ff) << 16)
// #define _SUPP_NEG(x) (((((uint32_t)(x) & 0x80) >> 7) * 0xff) << 24)
// #define _SW_ENDIAN(x) _SW_F(x) | _SW_S(x) | _SW_T(x) | _SUPP_NEG(x)

// #define _SW_Q(x) (((((uint32_t)(x) & 0x800000) >> 23) * 0xff) << 24)
// #include <stdint.h>
// #include <stdio.h>
// int main (void)
// {
//   uint32_t word = 0x0A0B0C0D; // An unsigned 32-bit integer.
//   char *pointer = (char *) &word; // A pointer to the first octet of the word.

//   for (int i = 0; i < 4; i++)
//   {
//     printf("%02x ", (unsigned int) pointer[i]);
//   }
//   puts("");
// }
RTP	bytecode_to_int64(const uint8_t *bytecode, size_t size);

RTP	bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	RTP	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result |= ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result |= bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

RTP	bytecode_to_int64(const uint8_t *bytecode, size_t size)
{
	RTP	result;
	t_bool	sign;
	int		j;
	
	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	j = 0;
	while (size)
	{
		if (sign)
			result |= ((uint64_t)(bytecode[size - 1] ^ 0xFF) << (j++ * 8));
		else
			result |= (uint64_t)bytecode[size - 1] << (j++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

#define AMO 7
int	main(void)
{

/*
** Этот кусок тестирует макрос на приближенных к реальным данных
*/
	uint8_t		buff[4] = "\x74\xB7\x7e\x00";
	int			*ptr = (int *)&buff[0];
	uint8_t			*refptr =(int *)&buff[0];

	int			l = bytecode_to_int32((const uint8_t *)refptr, 3);
	int			k = ft_swap_endian(*ptr, 3);

	/*
	** Этот кусок тестирует макрос с уже проверенной функцией флипа с дополнением
	*/
// 	RTP k,l; k = l = 0;
// 	uint8_t	test[8] = {0xf0, 0xFF, 0xFF, 0xF0, 0, 0, 0, 0};
// 	k = ft_swap_endian(*(RTP *)&test[0], AMO);
// 	l = bytecode_to_int64(&test[0], AMO);
// #if REG_SIZE <= 4
// 	DEBintt(k) DEBend()
// 	DEBintt(l) DEBend()
// #else
// 	DEBllt(k) DEBend()
// 	DEBllt(l) DEBend()
// #endif
	
	// for (int i = 0xFFFFFFFFLL; i != 0; i--)
	// {
	// 	k = ft_swap_endian(i,(uintptr_t)REG_SIZE);
	// 	l = bytecode_to_int32((const uint8_t *)&i, REG_SIZE);
		
	// 	if (k != l)
	// 	{
	// 		DEBlt(i) DEBlt(k) DEBlt(l) DEBend()
	// 		sleep(1);
	// 	}
	// }

	
// int x = 13;      // sign extend this b-bit number to r
// int r;      // resulting sign-extended number
// int m;
// for (unsigned b = 0; b < 32; b++)
// {
// m = 8 * sizeof(x) - b;
// r = (x << m) >> m;
// }
	return (0);
}

