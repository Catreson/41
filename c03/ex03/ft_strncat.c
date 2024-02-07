char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = dest;
	while (*dest)
	{
		dest++;
	}
	while (j < nb && src[i])
	{
		*(dest++) = src[i++];
	}
	*(dest) = '\0';
	return (tmp);
}