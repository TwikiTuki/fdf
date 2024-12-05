
int	ft_isprint(int c)
{
	if (c >= 040 && c <= 077)
		return (1);
	if (c >= 0100 && c <= 0176)
		return (1);
	return (0);
}
