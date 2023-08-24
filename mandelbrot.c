/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:06:43 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/21 23:55:45 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_vars *vars)
{
	int a = 0;
	int px = 0;
	while ( px < WINDOW_WIDTH)
	{
		int py = 0;
		while( py < WINDOW_HEIGHT)
		{
			a = mandelbrot(px,py,(*vars));
			double clr = 255 * a /vars->iter * 3;

			if(a == vars->iter)
			{
				my_mlx_pixel_put(vars,px,py,0x000000);
			}
			else
			{
				my_mlx_pixel_put(vars,px,py,create_trgb(0,0,clr/3,clr/2));
			}
			py++;
		}
		px++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 4, 0, hop, vars);
	mlx_hook(vars->win, 2, 0, ft_close, vars);
}

int	mandelbrot(int px, int py, t_vars vars)
{
	double	x_0;
	double	y_0;
	double	x;
	double	y;
	int	i;
	double	a;
	double	b;

	i = 0;
	x = x_0;
	y = y_0;
	x_0 = (vars.x_max - vars.x_min) * px / WINDOW_WIDTH + vars.x_min;
	y_0 = (vars.y_max - vars.y_min) * py / WINDOW_HEIGHT + vars.y_min;
	while (i < vars.iter && x * x + y * y <= 16)
	{
		a = x * x - y * y +x_0;
		b = 2 * x * y +y_0;
		x = a;
		y = b;
		i++;
	}
	return (i);
}

int	hop(int button, int x, int y, t_vars *vars)
{
	double x_0 = (vars->x_max - vars->x_min) * x / WINDOW_WIDTH + vars->x_min;
	double y_0 = (vars->y_max - vars->y_min) * y / WINDOW_HEIGHT + vars->y_min;
	double new_x = 0;
	double new_y = 0;
	int a = 0;
	if (button == 4)
	{
		vars->iter -= 2;
		new_x = (vars->x_max - vars->x_min) * 10 / 8 - (vars->x_max - vars->x_min);
		vars->x_max = vars->x_max + new_x / 2;
		vars->x_min = vars->x_min - new_x / 2;
		new_y = (vars->y_max - vars->y_min) * 10 / 8 - (vars->y_max - vars->y_min);
		vars->y_max = vars->y_max + new_y / 2;
		vars->y_min = vars->y_min - new_y / 2;
	}
	if (button == 5)
	{
		vars->iter += 2;
		vars->x_max = vars->x_max - ((vars->x_max - x_0) * 0.1);
		vars->x_min = vars->x_min + ((x_0 - vars->x_min) * 0.1);
		vars->y_max = vars->y_max - ((vars->y_max - y_0) * 0.1);
		vars->y_min = vars->y_min + ((y_0 - vars->y_min) * 0.1);
	}
	ft_mandelbrot(vars);
	return (0);
}

void	init_m(t_vars *vars)
{
	vars->x_min = -2.0;
	vars->x_max = 2.0;
	vars->y_min = -1.4;
	vars->y_max = 1.4;
	vars->iter = MAX_ITERATION;
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->a_0 = 0;
	vars->b_0 = 0;
}
