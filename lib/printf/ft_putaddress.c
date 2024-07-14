/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:28:28 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/14 19:15:56 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putaddress(va_list args)
{
	unsigned long	num;

	num = va_arg(args, unsigned long);
	return (write(1, "0x", 2) + ft_puthexa(num, "0123456789abcdef"));
}
