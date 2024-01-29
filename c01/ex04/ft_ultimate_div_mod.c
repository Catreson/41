void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp[2];

	tmp[0] = a / b;
	tmp[1] = a % b;
	*a = tmp[0];
	*b = tmp[1];
}