/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:06:44 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:22:11 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (!ft_isspace(str[i]) && (ft_isspace(str[i + 1]) || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static void	ft_clean(char **ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
}
// #include <stdio.h>
static int	ft_fill(char **ptr, char *str, int count)
{
	int	i;
	int	a;
	int	len;

	a = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			str++;
		if (str[i])
			i++;
		if (!ft_isspace(str[i - 1]) && (ft_isspace(str[i]) || !str[i]))
		{
			ptr[a] = malloc(i + 1);
			if (!ptr[a])
				return (ft_clean(ptr, count), ptr = NULL, FAILURE);
			ft_memcpy(ptr[a], str, i);
			ptr[a++][i] = 0;
			str = str + i;
			i = 0;
		}
	}
	return (ptr[count] = NULL, SUCCESS);
}

char	**ft_split(char *str)
{
	char	**ptr;
	int		count;

	if (!str)
		return (NULL);
	count = count_words(str);
	ptr = malloc(sizeof(char **) * (count + 1));
	if (!ptr)
		return (NULL);
	ft_fill(ptr, str, count);
	return (ptr);
}

/* 
void leaks_check()
{
	system("leaks run");
	printf("-------------------------------------------------------\n");
}

#include <stdio.h>
int main()
{
	atexit(leaks_check);
	char **str = ft_split("^ ^ ^ --h^^^	^ ^^^^		f ");
	while (*str)
		printf("|%s|\n", *(str++));
	printf("-------------------------------------------------------\n");
}
 */