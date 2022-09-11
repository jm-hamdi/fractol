/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <jm-hamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:04:23 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/08/05 12:10:42 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	my_mlx_pixel_put(int *img_str, int x, int y, int clr)
{
	img_str[y * (int)WIN_H + x] = clr;
}

int	ft_close(t_mlx *z)
{
	free (z);
	exit (0);
	return (0);
}

void	ft_clear_img(int *img_str)
{
	int	i;

	i = 0;
	while (i < WIN_H * WIN_W)
		img_str[i++] = 0xffffff;
}
