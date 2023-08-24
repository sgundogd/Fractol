/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:22:41 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/25 01:57:11 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_vars *vars)
{
	int		a;
	int		px;
	int		py;
	double	clr;

	a = 0;
	px = 0;
	while (px < WINDOW_WIDTH)
	{
		py = 0;
		while (py < WINDOW_HEIGHT)
		{
			a = julia(px, py, (*vars));
			clr = 255 * a / vars->iter;
			if (a == vars->iter)
			{
				my_mlx_pixel_put(vars, px, py, 0x000000);
			}
			else
			{
				my_mlx_pixel_put(vars, px, py, create_trgb(0, 0, clr, 0));
			}
			py++;
		}
		px++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 4, 0, hop_j, vars);
	mlx_hook(vars->win, 2, 0, change, vars);
}

void	init_j(t_vars *vars)
{
	vars->x_min = -2.0;
	vars->x_max = 2.0;
	vars->y_min = -1.4;
	vars->y_max = 1.4;
	vars->iter = MAX_ITERATION;
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->a_0 = 0.285;
	vars->b_0 = 0.01;
	vars->flag = 0;
}

int	julia(int px, int py, t_vars vars)
{
	double	x;
	double	y;
	int		i;
	double	a;
	double	b;

	i = 0;
	x = (vars.x_max - vars.x_min) * px / WINDOW_WIDTH + vars.x_min;
	y = (vars.y_max - vars.y_min) * py / WINDOW_HEIGHT + vars.y_min;
	while (i < vars.iter && x * x + y * y <= 16)
	{
		a = x * x - y * y + vars.a_0;
		b = 2 * x * y + vars.b_0;
		x = a;
		y = b;
		i++;
	}
	return (i);
}

int	hop_j(int button, int x, int y, t_vars *vars)
{
	double	x_0;
	double	y_0;
	double	new_x;
	double	new_y;
	int		a;

	x_0 = (vars->x_max - vars->x_min) * x / WINDOW_WIDTH + vars->x_min;
	y_0 = (vars->y_max - vars->y_min) * y / WINDOW_HEIGHT + vars->y_min;
	new_x = 0;
	new_y = 0;
	a = 0;
	if (button == 4)
	{
		vars->iter -= 1;
		new_x = (vars->x_max - vars->x_min) * 10 / 8
			- (vars->x_max - vars->x_min);
		vars->x_max = vars->x_max + new_x / 2;
		vars->x_min = vars->x_min - new_x / 2;
		new_y = (vars->y_max - vars->y_min) * 10 / 8
			- (vars->y_max - vars->y_min);
		vars->y_max = vars->y_max + new_y / 2;
		vars->y_min = vars->y_min - new_y / 2;
	}
	if (button == 5)
	{
		vars->iter += 1;
		vars->x_max = vars->x_max - ((vars->x_max - x_0) * 0.1);
		vars->x_min = vars->x_min + ((x_0 - vars->x_min) * 0.1);
		vars->y_max = vars->y_max - ((vars->y_max - y_0) * 0.1);
		vars->y_min = vars->y_min + ((y_0 - vars->y_min) * 0.1);
	}
	ft_julia(vars);
	return (0);
}

int	change(int keycode, t_vars *vars)
{
	ft_key(keycode, vars);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21)
	{
		init_j(vars);
		if (keycode == 18)
		{
			vars->a_0 = 0.285;
			vars->b_0 = 0.01;
		}
		if (keycode == 19)
		{
			vars->a_0 = -0.70176;
			vars->b_0 = -0.3842;
		}
		if (keycode == 20)
		{
			vars->a_0 = -0.835;
			vars->b_0 = -0.2321;
		}
		if (keycode == 21)
		{
			vars->a_0 = -0.7269;
			vars->b_0 = 0.1889;
		}
		ft_julia(vars);
	}
	return (0);
}
