/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:04:50 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/25 02:05:36 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(int px, int py, t_vars *vars)
{
	int		iter;
	double	clr;

	iter = mandelbrot(px, py, (*vars));
	clr = 255 * iter / vars->iter;
	if (iter == vars->iter)
		my_mlx_pixel_put(vars, px, py, 0x000000);
	else if (vars->flag == 0)
		my_mlx_pixel_put(vars, px, py, create_trgb(0, clr, clr, clr));
	else if (vars->flag == 1)
		my_mlx_pixel_put(vars, px, py, create_trgb(0, clr, 0, clr));
	else if (vars->flag == 2)
		my_mlx_pixel_put(vars, px, py, create_trgb(0, clr, 0, clr / 2));
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
