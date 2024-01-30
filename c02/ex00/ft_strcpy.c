char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
}