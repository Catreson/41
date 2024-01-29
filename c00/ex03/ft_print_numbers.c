#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (i <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}