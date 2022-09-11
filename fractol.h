/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:01:56 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/05 11:37:46 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include"mlx.h"
# include<unistd.h>
# include<stdlib.h>
# define WIN_W 600.
# define WIN_H 600.
# define MAX_ITER 100

typedef struct s_complex{
	double	r;
	double	i;
}t_complex;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_str;
	t_complex			z;
	t_complex			c;
	t_complex			tmp;
	int					bpp;
	int					l;
	int					endian;
	int					t_x;
	int					t_y;
	int					color;
	int					newcolor;
	int					id;
	int					m_x;
	int					m_y;
	int					max_iter;
	double				r_min;
	double				r_max;
	double				i_min;
	double				i_max;
	double				interp;
	double				zoom;
}t_mlx;

int		ft_strcmp(const char *s1, const char *s2);
void	mandelbrot(t_mlx *mlx);
void	my_mlx_pixel_put(int *img_str, int x, int y, int color);
int		mouse_move(int x, int y, t_mlx *z);
int		mouse_press(int button, int x, int y, t_mlx *z);
int		key_press(int keycode, t_mlx *z);
void	ft_clear_img(int *img_str);
int		ft_close(t_mlx *z);
void	ft_putstr(char *s);
void	julia(t_mlx *mlx);

#endif
