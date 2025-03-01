/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:01:14 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:27:28 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_putchar2(char c)
{
	return (write(1, &c, 1));
}

int	ft_puthexa(unsigned long num, char *base)
{
	if (num < 16)
		return (ft_putchar2(base[num]));
	else
		return (ft_puthexa(num / 16, base) + ft_puthexa(num % 16, base));
}
