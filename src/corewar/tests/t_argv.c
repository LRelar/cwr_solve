#include <libft.h>

inline static void	ft_test(char **ptr)
{
	DEBtextt(*ptr) DEBend()
}
int	main(int argc, char**argv)
{
	argv++;
	char	***capsule = &argv;
	DEBit(capsule) DEBit(*capsule) DEBtextt(**capsule) DEBend()
	ft_test(++*capsule);
	DEBit(capsule) DEBit(*capsule) DEBtextt(**capsule) DEBend()
	return (0);
}