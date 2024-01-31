unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	i = -1;
	if (size != 0)
	{
		while (src [++i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (len);
}

