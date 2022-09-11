/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:19:15 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/03 21:19:22 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_mlx *z)
{
	if (keycode == 53)
	{
		free (z);
		exit (0);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *z)
{
	x = 0;
	y = 0;
	ft_clear_img(z->img_str);
	if (button == 5)
		z->zoom--;
	else if (button == 4)
		z->zoom++;
	if (z->id == 1)
		mandelbrot (z);
	else if (z->id == 2)
		julia (z);
	mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	return (0);
}

int	mouse_move(int x, int y, t_mlx *z)
{
	z->m_x = x;
	z->m_y = y;
	if (z->id == 2)
	{
		ft_clear_img(z->img_str);
		julia (z);
		mlx_put_image_to_window(z->mlx_ptr, z->win_ptr, z->img_ptr, 0, 0);
	}
	return (0);
}
