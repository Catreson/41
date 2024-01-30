#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a' - 1;
	while (++c <= 'z')
	{
		write(1, &c, 1);
	}
}