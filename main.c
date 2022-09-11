/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:02:29 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/05 13:05:59 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	notif(void)
{
	ft_putstr("Invalid number of arguments, try again:\n");
	ft_putstr("./fractol Mandelbrot or ./fractol julia");
}

void	ft_init(t_mlx *z)
{
	z->t_x = 0;
	z->t_y = 0;
	z->r_max = 2;
	z->r_min = -2;
	z->i_max = 2;
	z->i_min = -2;
	z->m_x = 0;
	z->m_y = 0;
	z->color = 0x3186C7;
	z->newcolor = 0x3186C7;
	z->max_iter = 50;
	z->zoom = 4;
}

void	init(t_mlx *z, char *str)
{
	ft_init(z);
	if (ft_strcmp("mandelbrot", str) == 0)
		z->id = 1;
	else if (ft_strcmp("julia", str) == 0)
		z->id = 2;
	else
	{
		write(1, " ./fractol [mandelbrot | julia]\n", 32);
		free(z);
		exit(0);
	}
	z->mlx_ptr = mlx_init();
	z->win_ptr = mlx_new_window(z->mlx_ptr, WIN_W, WIN_H, "fractol");
	z->img_ptr = mlx_new_image(z->mlx_ptr, WIN_W, WIN_H);
	z->img_str = (int *)mlx_get_data_addr
		(z->img_ptr, &z->bpp, &z->l, &z->endian);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit (EXIT_FAILURE);
	if (ac == 2)
	{
		init(mlx, av[1]);
		if (mlx->id == 1)
			mandelbrot(mlx);
		if (mlx->id == 2)
			julia(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		mlx_hook (mlx->win_ptr, 17, 0, ft_close, mlx);
		mlx_hook (mlx->win_ptr, 2, 0, key_press, mlx);
		mlx_hook (mlx->win_ptr, 4, 0, mouse_press, mlx);
		mlx_hook (mlx->win_ptr, 6, 0, mouse_move, mlx);
		mlx_loop (mlx->mlx_ptr);
	}
	else
		notif();
	free(mlx);
	return (0);
}
