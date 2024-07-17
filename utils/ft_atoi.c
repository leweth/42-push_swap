/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:52:43 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/17 21:45:14 by mben-yah         ###   ########.fr       */
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
		// ft_printf("%i\n", *conv);
		if (*conv > 217483647 && sign == 1)
			return (NUMBER_EXCCED_INT_MAX);
		else if (*conv > 217483648 && sign == -1)
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
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') * (-1) + (str[i] == '+'); 
	if (str[i] == '+' || str[i] == '-')
			i++;
	if (!ft_isdigit(str[i]))
		return (*err = WRONG_NUMBER_FORMAT, FAILURE);
	// ft_printf("%s\n", str);
	// ft_printf("%d\n", conv);
	*err = ft_convert(str, &conv, &i, sign);
	if (*err < 0)
		return (FAILURE);
	if (str[i] && !ft_isdigit(str[i]))
		return (*err = WRONG_NUMBER_FORMAT, FAILURE);
	return (conv * sign);
}
