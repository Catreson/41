int 	ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
		str++;
	return (str - tmp);
}
