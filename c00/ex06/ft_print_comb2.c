#include <unistd.h>

void	write_number(int number)
{
	char	c[2];

	c[0] = '0' + number / 10;
	c[1] = '0' + number % 10;
	write(1, c, 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 100)
	{
		j = i;
		while (++j <= 99)
		{
			write_number(i);
			write(1, &" ", 1);
			write_number(j);
			if (i != 98)
				write(1, &", ", 2);
		}
	}
}