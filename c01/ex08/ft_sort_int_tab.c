void ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				tab[i] ^= tab[j];
				tab[j] ^= tab[i];
				tab[i] ^= tab[j];
			}
		}
	}
}