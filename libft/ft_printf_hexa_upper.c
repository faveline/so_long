/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:45:41 by faveline          #+#    #+#             */
/*   Updated: 2023/11/02 09:49:14 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_hexa_upper(int nbr, char *hexa, char *str, int i)
{
	int	j;

	while (nbr != 0)
	{
		str[i] = hexa[nbr % 16];
		nbr /= 16;
		i++;
	}
	j = i;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}	
	return (j);
}

static int	ft_conv_hexa_upp_neg(int nbr, char *hexa, char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = 'F';
		i++;
	}
	i--;
	while (nbr != 0)
	{
		str[i] = hexa[16 - (nbr % 16)];
		if (nbr % 16 == 0 || nbr / 16 == 0)
			nbr /= 16;
		else
			nbr = nbr / 16 + 1;
		i--;
	}
	i = 0;
	while (i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (size);
}

static int	ft_size_nbr(int nbr, int j)
{
	while (nbr != 0)
	{
		nbr /= 16;
		j++;
	}
	return (j);
}

int	ft_printf_hexa_upper(va_list to_write)
{
	int		nbr;
	char	*str;
	int		j;

	nbr = va_arg(to_write, int);
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr == -2147483648)
		return (write(1, "80000000", 8));
	j = ft_size_nbr(nbr, 0);
	str = (char *)malloc((j + 1) * sizeof(int));
	if (str == NULL)
		return (-1);
	if (nbr >= 0)
		j = ft_conv_hexa_upper(nbr, "0123456789ABCDEF", str, 0);
	else
		j = ft_conv_hexa_upp_neg(-nbr, "0123456789ABCDEF0", str, 8);
	free(str);
	return (j);
}
