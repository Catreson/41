int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && i < n && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}