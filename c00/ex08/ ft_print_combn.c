#include <unistd.h>

void	inception(int n, char c[], int len)
{
	char	tmp;

	if (n == len)
	{
		write(1, c, len);
		if (c[0] != 1 + '9' - len)
			write(1, &", ", 2);
		return ;
	}
	tmp = c[n - 1];
	while (++tmp <= '9')
	{
		c[n] = tmp;
		inception(n + 1, c, len);
	}
}

void	ft_print_combn(int n)
{
	char	c[9];

	c[0] = '0' - 1;
	while (++c[0] <= '9')
	{
		inception(1, c, n);
	}
}
