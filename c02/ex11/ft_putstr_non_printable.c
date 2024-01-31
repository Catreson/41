#include <unistd.h>

void	hd_write(char c)
{
	write(1, ("0123456789abcdef" + c / 16), 1);
	write(1, ("0123456789abcdef" + c % 16), 1);
}

void	non_printable(char c)
{
	write(1, &"\\", 1);
	hd_write(c);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			non_printable(*str);
		else
			write(1, str, 1);
		str++;
	}
}