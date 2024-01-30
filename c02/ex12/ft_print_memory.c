#include <unistd.h>

void	hd_write(char c)
{
	char	tmp;

	if (c <= 9)
		tmp = '0' + c;
	else
		tmp = 'a' + c - 10;
	write(1, &tmp, 1);
}

void	addr_write(void *addr)
{
	int					i;
	unsigned long long	j;

	i = -1;
	j = (unsigned long long int)addr;
	while (++i < 16)
	{
		hd_write((char)(0xF & (j >> ((15 - i) * 4))));
	}
	write(1, &":", 1);
}

void	hex_write(short *addr)
{
	int		i;
	short	j;
	int		k;

	i = -1;
	j = *addr;
	write(1, &" ", 1);
	hd_write((char)(0xF & (j >> ((3 - 2) * 4))));
	hd_write((char)(0xF & (j >> ((3 - 3) * 4))));
	hd_write((char)(0xF & (j >> ((3 - 0) * 4))));
	hd_write((char)(0xF & (j >> ((3 - 1) * 4))));
}

void	text_write(short *addr)
{
	int		i;
	short	j;
	char	tmp;

	i = -1;
	j = (short)*addr;
	tmp = (char)(0xFF & j);
	if (tmp < 32 || tmp > 126)
		write(1, &".", 1);
	else
		write(1, &tmp, 1);
	tmp = (char)(0xFF & j >> 8);
	if (tmp < 32 || tmp > 126)
		write(1, &".", 1);
	else
		write(1, &tmp, 1);

}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i * 16 < size)
	{
		addr_write(addr + i * 16);
		j = -1;
		while (++j < 8)
		{
			if (i * 16 + j * 2 < size)
				hex_write(addr + 16 * i + 2 * j);
			else
				write(1, &"     ", 5);
		}
		j = -1;
		write(1, &" ", 1);
		while (++j < 8)
			if (i * 16 + j * 2 < size)
				text_write(addr + 16 * i + j * 2);
		write(1, &"\n", 1);
		i++;
	}
	return (addr);
}
