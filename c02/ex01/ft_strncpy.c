char	*ft_strncpy(char *dest, char *src, unsigned int i)
{
	int	i;

	i = -1;
	while (src[++i] && i < n)
	{
		dest[i] = src[i];
	}
	while (i < n)
		dest[i++] = 0;
}