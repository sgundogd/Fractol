/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:09:35 by sgundogd          #+#    #+#             */
/*   Updated: 2023/08/25 11:53:23 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include <math.h>

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
# define MAX_ITERATION 50

typedef struct s_vars {
	void	*mlx;
	void	*win;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iter;
	double	a_0;
	double	b_0;
	int		flag;
}				t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		mandelbrot(int px, int py, t_vars vars);
int		hop(int button, int x, int y, t_vars *vars);
void	ft_julia(t_vars *vars);
void	init_j(t_vars *vars);
int		julia(int px, int py, t_vars vars);
int		hop_j(int button, int x, int y, t_vars *vars);
int		mandelbrot(int px, int py, t_vars vars);
void	init_m(t_vars *vars);
void	ft_mandelbrot(t_vars *vars);
int		change(int keycode, t_vars *vars);
int		ft_key(int keycode, t_vars *vars);
void	ft_hook(t_vars *vars);
int		ft_swap(int keycode, t_vars *vars);
void	ft_color(int px, int py, t_vars *vars);
void	zoom_out(t_vars *vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_exit(t_vars *vars);

#endif
