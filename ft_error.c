/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:07:11 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 16:36:49 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int error)
{
	if (error == -1)
		ft_printf("ERROR\nThe map is not surrounded by walls.");
	if (error == -2)
		ft_printf("ERROR\nThe map is not rectangular.");
	if (error == -3)
		ft_printf("ERROR\nStar, exit or collectibles are not properly defined.");
	if (error == -4)
		ft_printf("ERROR\nTheir is no valid path in the map.");
	if (error == -5)
		ft_printf("ERROR\nTheir is a non valid caracter in the map.");
}
