/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:24:04 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/25 10:53:58 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_swap(int keycode, t_vars *vars)
{
	if (keycode == 124)
	{
		vars->x_max += (vars->x_max - vars->x_min) / 10;
		vars->x_min += (vars->x_max - vars->x_min) / 10;
	}
	if (keycode == 123)
	{
		vars->x_max -= (vars->x_max - vars->x_min) / 10;
		vars->x_min -= (vars->x_max - vars->x_min) / 10;
	}
	if (keycode == 125)
	{
		vars->y_max += (vars->y_max - vars->y_min) / 10;
		vars->y_min += (vars->y_max - vars->y_min) / 10;
	}
	if (keycode == 126)
	{
		vars->y_max -= (vars->y_max - vars->y_min) / 10;
		vars->y_min -= (vars->y_max - vars->y_min) / 10;
	}
	if (vars->a_0 == 0)
		ft_mandelbrot(vars);
	else
		ft_julia(vars);
	return (0);
}

int	ft_key(int keycode, t_vars *vars)
{
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_swap(keycode, vars);
	if (keycode == 49)
	{
		if (vars->flag == 2)
			vars->flag = 0;
		else
			vars->flag += 1;
		if (vars->a_0 == 0)
			ft_mandelbrot(vars);
		else
			ft_julia(vars);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && (!ft_strncmp(av[1], "Mandelbrot", 12)
			|| !ft_strncmp(av[1], "Julia", 12)))
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH,
				WINDOW_HEIGHT, "Fractol");
		if ((!ft_strncmp(av[1], "Mandelbrot", 12)))
		{
			init_m(&vars);
			ft_mandelbrot(&vars);
		}
		if ((!ft_strncmp(av[1], "Julia", 12)))
		{
			init_j(&vars);
			ft_julia(&vars);
		}
		mlx_loop(vars.mlx);
	}
	else
	{
		printf(" './fractal_bonus Mandelbrot or Julia' \n");
		exit(0);
	}
}
