/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:24:04 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/22 00:17:24 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	ft_swap(int keycode, t_vars *vars)
{
	double	a;
	double	b;

	a = vars->x_max-vars->x_min;
	b = vars->y_max-vars->y_min;
	printf("selam\n");
	if (keycode == 124)
	{
		vars->x_max+=a/10;
		vars->x_min+=a/10;
	}
	if (keycode == 123)
	{
		vars->x_max-=a/10;
		vars->x_min-=a/10;
	}
	if (keycode == 125)
	{
		vars->y_max+=b/10;
		vars->y_min+=b/10;
	}
	if (keycode == 126)
	{
		vars->y_max-=b/10;
		vars->y_min-=b/10;
	}
	if (vars->a_0 == 0)
	ft_mandelbrot(vars);
	else
	ft_julia(vars);
	return(0);
}

int	ft_close(int keycode, t_vars *vars)
{
	ft_swap(keycode, vars);
	printf("selam2\n");
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

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 12)
		||!ft_strncmp(av[1], "Julia", 12))
	{
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
		printf(" './fractal Mandelbrot or Julia' \n");
		exit(0);
	}
}
