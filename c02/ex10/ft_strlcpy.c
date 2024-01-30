unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i++] = 0;
	}
	while (src[j])
		j++;
	if (size - 1 < j)
		return (size - 1);
	return (j);
}
