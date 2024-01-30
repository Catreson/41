#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0' - 1;
	while (++c <= '9')
	{
		write(1, &c, 1);
	}
}