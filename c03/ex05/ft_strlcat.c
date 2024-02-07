int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	while (dest[j])
	{
		j++;
	}
	dlen = j;
	if (size == 0 || size - 1 < dest_len)
		return (src_len + size);
	while (src[i] && i < (size - dest_len - 1))
	{
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	return (dlen + slen);
}