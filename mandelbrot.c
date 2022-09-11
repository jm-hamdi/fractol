/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:03:58 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/05 13:10:11 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_calcul(int x, int y, t_mlx *mlx)
{
	int		iter;

	iter = 1;
	mlx->c.r = mlx->r_min + (x + mlx->t_x) / WIN_W * (mlx->zoom);
	mlx->c.i = mlx->i_min + (y + mlx->t_y) / WIN_H * (mlx->zoom);
	mlx->z.r = 0.0;
	mlx->z.i = 0.0;
	mlx->tmp = mlx->z;
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4
		&& iter < mlx->max_iter)
	{
		mlx->tmp.r = mlx->z.r * mlx->z.r - mlx->z.i * mlx->z.i + mlx->c.r;
		mlx->tmp.i = 2 * mlx->z.r * mlx->z.i + mlx->c.i;
		mlx->z = mlx->tmp;
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_mlx *mlx)
{
	int			x;
	int			y;
	int			iter;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			iter = mandelbrot_calcul(x, y, mlx);
			if (iter == mlx->max_iter)
				mlx->color = 0x000000;
			else
				mlx->color = iter * mlx->newcolor ;
			my_mlx_pixel_put(mlx->img_str, x, y, mlx->color);
			x++;
		}
		y++;
	}
}
