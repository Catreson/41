#include <unistd.h>

int	abes(int a)
{
	return (((a > 0) - (a < 0)) * a);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
		write(1, &"-", 1);
	if (nb >= 10 || nb <= -10)
	{
		ft_putnbr(abes(nb / 10));
		ft_putnbr(abes(nb % 10));
	}
	else
	{
		c = abes(nb) + '0';
		write(1, &c, 1);
	}
}
