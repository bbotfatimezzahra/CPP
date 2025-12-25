#include "PmergeMe.hpp"
#include <cstring>

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_issign(int c)
{
	if (c != '+')
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if (c != 32 && (c < 9 || c > 13))
		return (0);
	return (1);
}

int	worth_check(char *arg)
{
	char	c;

	c = '0';
	while (c <= '9')
		if (strchr(arg, c++))
			return (1);
	return (0);
}

int	checkArgs(char **argv)
{
	int		i;
	int		j;
	char	*c;

	i = 1;
	while (argv[i])
	{
		if (!worth_check(argv[i]))
			return (0);
		c = argv[i];
		j = 0;
		while (c[j])
		{
			if (!ft_isdigit(c[j]) && !ft_isspace(c[j]) && !ft_issign(c[j]))
				return (0);
			if (ft_issign(c[j]) && !ft_isdigit(c[j + 1]))
				return (0);
			if (ft_issign(c[j]) && !ft_isspace(c[j - 1]) && j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


