/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_screen_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:04:42 by faveline          #+#    #+#             */
/*   Updated: 2023/11/11 17:04:33 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_screen(mlx_t *wind, int i)
{
	static mlx_image_t	*img_b;
	char				*itoa;

	if (img_b != NULL)
		mlx_delete_image(wind, img_b);
	itoa = ft_itoa(i);
	img_b = mlx_put_string(wind, itoa, 32, 32);
	free(itoa);
}
