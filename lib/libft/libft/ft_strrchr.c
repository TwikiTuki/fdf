
char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *) s);
	return ((char *) ret);
}
