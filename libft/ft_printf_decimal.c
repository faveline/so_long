/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:36:45 by faveline          #+#    #+#             */
/*   Updated: 2023/11/02 10:43:48 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_decimal(va_list to_write)
{
	int	nbr;
	int	i;

	nbr = va_arg(to_write, int);
	ft_putnbr_fd(nbr, 1);
	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
