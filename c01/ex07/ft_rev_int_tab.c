void ft_rev_int_tab(int *tab, int size)
{
	size--;
	while (tab < tab + size)
	{
		*tab ^= *(tab + size);
		*(tab + size) ^= *tab;
		*tab ^= *(tab + size);
		tab++;
		size -= 2;
	}
}
