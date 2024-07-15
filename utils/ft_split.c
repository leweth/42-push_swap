#include "../includes/push_swap.h"

static bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static int	count_words(const char *str)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *c)
{
	
}



/* #include <stdio.h>
int main()
{
	printf("%d\n", count_words("         how      doing !"));
} */