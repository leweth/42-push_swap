/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:52:43 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:30:58 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}
static int	ft_convert(char *str, size_t *conv, size_t *i, int sign)
{
	while (ft_isdigit(str[*i]))
	{	
		*conv = *conv * 10 + str[(*i)++] - '0';
		if (*conv > (size_t)INT_MAX && sign == 1)
			return (NUMBER_EXCCED_INT_MAX);
		else if (*conv > (size_t)INT_MAX + 1 && sign == -1)
			return (NUMBER_LOWER_THAN_INT_MIN);
	}
	return (SUCCESS);
}

int	ft_atoi(char *str, int *err)
{
	size_t	i;
	size_t	conv;
	int		sign;

	i = 0;
	sign = 1;
	conv = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
	if (!ft_isdigit(str[i]))
		*err = WRONG_NUMBER_FORMAT;
	*err = ft_convert(str, &conv, &i, sign);
	if (str[i] && !ft_isdigit(str[i]))
		*err = WRONG_NUMBER_FORMAT;
	return (conv * sign);
}
