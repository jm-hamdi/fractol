/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:05:39 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/05 11:43:27 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	julia_calcul(int x, int y, t_mlx *mlx)
{
	int		iter;

	iter = 1;
	mlx->z.r = mlx->r_min + (x + mlx->t_x) / WIN_W * (mlx->zoom);
	mlx->z.i = mlx->i_min + (y + mlx->t_y) / WIN_H * (mlx->zoom);
	mlx->c.r = mlx->r_min + mlx->m_x / (WIN_W / (mlx->r_max - mlx->r_min));
	mlx->c.i = mlx->i_min + mlx->m_y / (WIN_H / (mlx->i_max - mlx->i_min));
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

void	julia(t_mlx *mlx)
{
	int				x;
	int				y;
	int				iter;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			iter = julia_calcul(x, y, mlx);
			if (iter == mlx->max_iter)
				mlx->color = 0x000000;
			else
				mlx->color = iter * mlx->newcolor;
			my_mlx_pixel_put(mlx->img_str, x, y, mlx->color);
			x++;
		}
		y++;
	}
}
