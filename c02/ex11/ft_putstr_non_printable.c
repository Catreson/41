#include <unistd.h>

void	hd_write(char c)
{
	char	tmp;
	char	tmp2;

	tmp2 = c / 16;
	if (tmp2 <= 9)
		tmp = '0' + tmp2;
	else
		tmp = 'a' + tmp2 - 10;
	write(1, &tmp, 1);
	tmp2 = c % 16;
	if (tmp2 <= 9)
		tmp = '0' + tmp2;
	else
		tmp = 'a' + tmp2 - 10;
	write(1, &tmp, 1);

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
