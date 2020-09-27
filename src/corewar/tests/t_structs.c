#include <libft.h>

typedef struct s_est t_est;
typedef struct s_ubstr t_ubstr;

struct s_ubstr
{
	char *string_one;
	char *string_two;
	void *someptr;
};

struct s_est
{
	char var[4];
	t_ubstr	block[4];
	void *ptr;
};

inline static void	ft_foo(t_ubstr *block)
{
	int i = 0, k = 4;
	while (i < k)
	{
		block[i].string_one = "WTF!?\t";
		DEBtextt(block[i].string_one)
		i++;
	}
}

int	main(void)
{
	t_est	this;
	t_est	*that = &this;
	DEBit(&this) 	DEBend()
	DEBit(&this.ptr); 	DEBit(&(this.ptr)) 	DEBend()
	for (int i = 0; i < 4; i++)
		DEBit(&this.var[i])
	DEBend()
	for (int i = 0; i < 4; i++)
		DEBit(&(this.var[i]))
	DEBend()
	DEBmesst("Using pointers to struct\n")
	for (int i = 0; i < 4; i++)
		DEBit(&that->var[i])
	DEBend()
	for (int i = 0; i < 4; i++)
		DEBit(&(that->var[i]))
	DEBend()

	DEBmesst("Checking some shit with pointers")
	ft_foo(&this.block[0]);
	return (0);
}