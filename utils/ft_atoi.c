/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:52:43 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/23 18:32:25 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

static int	ft_convert(char *str, long long int *conv, size_t *i, int sign)
{
	while (ft_isdigit(str[*i]))
	{
		*conv = *conv * 10 + str[(*i)++] - '0';
		if (*conv > 2147483647 && sign == 1)
			return (NUMBER_EXCCED_INT_MAX);
		else if (*conv > 2147483648 && sign == -1)
			return (NUMBER_LOWER_THAN_INT_MIN);
	}
	return (SUCCESS);
}

int	ft_atoi(char *str, int *err)
{
	size_t			i;
	long long int	conv;
	int				sign;

	i = 0;
	conv = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (*err = WRONG_NUMBER_FORMAT, FAILURE);
	*err = ft_convert(str, &conv, &i, sign);
	if (*err < 0)
		return (FAILURE);
	if (str[i] && !ft_isdigit(str[i]))
		return (*err = WRONG_NUMBER_FORMAT, FAILURE);
	return (conv * sign);
}
