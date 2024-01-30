char *ft_strlowcaser(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	is_new;
	int	i;

	is_new = 1;
	i = -1;
	str = ft_strlowcaser(str);
	while (str[++i])
	{
		if (is_new && str[i] >= 'a' && str[i] <= 'z')
			str[i] += 'A' - 'a';
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '-' || str[i] == '+')
			is_new = 1;
		else
			is_new = 0;
	}
	return (str);
}