/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   plus.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 13:32:24 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 13:32:25 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	init2(t_file *file)
{
	file->frac.newre = 0;
	file->frac.newim = 0;
	file->frac.oldre = 0;
	file->frac.oldim = 0;
}

void	init_julia(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.movex = -1.6;
	file->frac.movey = -0.9;
	file->frac.maxit = 250;
	file->frac.cre = -0.7;
	file->frac.cim = 0.27015;
	file->color.r = 150;
	file->color.b = 250;
	file->color.g = 100;
}

void	init_mandelbrot(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.movex = -2;
	file->frac.movey = -0.9;
	file->frac.maxit = 250;
	file->color.r = 150;
	file->color.b = 250;
	file->color.g = 100;
}

void	init_burningship(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.movex = -1.8;
	file->frac.movey = -1.3;
	file->frac.maxit = 100;
	file->color.r = 150;
	file->color.b = 250;
	file->color.g = 100;
}

void	selector(char *str, t_file *file)
{
	if (ft_strcmp(str, "julia") == 0)
	{
		init_julia(file);
		file->fct = &(julia);
	}
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		init_mandelbrot(file);
		file->fct = &(mandelbrot);
	}
	if (ft_strcmp(str, "burningship") == 0)
	{
		init_burningship(file);
		file->fct = &(burningship);
	}
}
