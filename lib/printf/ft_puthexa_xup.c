/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_xup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:10:58 by mben-yah          #+#    #+#             */
/*   Updated: 2024/07/16 18:27:25 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_puthexa_xup(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_puthexa(num, "0123456789ABCDEF"));
}
