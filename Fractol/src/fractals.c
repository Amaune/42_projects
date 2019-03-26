/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractals.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 17:04:05 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 17:04:06 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	fill_pixel(int x, int y, t_file *file)
{
	int i;

	i = (x * 4) + (y * (file->size_l));
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		file->img[i] = (char)file->color.blue;
		file->img[i + 1] = (char)file->color.green;
		file->img[i + 2] = (char)file->color.red;
	}
}

void	color(double sc, t_file *file)
{
	file->color.blue = (sc / file->frac.maxit) * 2 * (file->color.b % 255);
	file->color.green = (sc / file->frac.maxit) * 2 * (file->color.g % 255);
	file->color.red = (sc / file->frac.maxit) * 2 * (file->color.r % 255);
}

void	julia(t_file *file, int x, int y)
{
	int		i;
	double	sc;

	file->frac.newre = x / file->frac.zoom + file->frac.movex;
	file->frac.newim = y / file->frac.zoom + file->frac.movey;
	i = 0;
	while (i < file->frac.maxit)
	{
		file->frac.oldre = file->frac.newre;
		file->frac.oldim = file->frac.newim;
		file->frac.newre = file->frac.oldre * file->frac.oldre -
		file->frac.oldim * file->frac.oldim + file->frac.cre;
		file->frac.newim = 2 * file->frac.oldre * file->frac.oldim +
		file->frac.cim;
		if ((file->frac.newre * file->frac.newre + file->frac.newim *
		file->frac.newim) > 4)
			break ;
		i++;
	}
	sc = smooth_coloring(file, i);
	color(sc, file);
	fill_pixel(x, y, file);
}

void	mandelbrot(t_file *file, int x, int y)
{
	int		i;
	double	sc;

	file->frac.cre = x / file->frac.zoom + file->frac.movex;
	file->frac.cim = y / file->frac.zoom + file->frac.movey;
	init2(file);
	i = 0;
	while (i < file->frac.maxit)
	{
		file->frac.oldre = file->frac.newre;
		file->frac.oldim = file->frac.newim;
		file->frac.newre = file->frac.oldre * file->frac.oldre -
		file->frac.oldim * file->frac.oldim + file->frac.cre;
		file->frac.newim = 2 * file->frac.oldre * file->frac.oldim
		+ file->frac.cim;
		if ((file->frac.newre * file->frac.newre + file->frac.newim
		* file->frac.newim) > 4)
			break ;
		i++;
	}
	sc = smooth_coloring(file, i);
	color(sc, file);
	fill_pixel(x, y, file);
}

void	burningship(t_file *file, int x, int y)
{
	int		i;
	double	sc;

	file->frac.cre = x / file->frac.zoom + file->frac.movex;
	file->frac.cim = y / file->frac.zoom + file->frac.movey;
	init2(file);
	i = 0;
	while (i < file->frac.maxit)
	{
		file->frac.oldre = file->frac.newre;
		file->frac.oldim = file->frac.newim;
		file->frac.newre = fabs(file->frac.oldre) * fabs(file->frac.oldre) -
		fabs(file->frac.oldim) * fabs(file->frac.oldim) + file->frac.cre;
		file->frac.newim = 2 * fabs(file->frac.oldre) * fabs(file->frac.oldim)
		+ file->frac.cim;
		if ((file->frac.newre * file->frac.newre + file->frac.newim *
		file->frac.newim) > 4)
			break ;
		i++;
	}
	sc = smooth_coloring(file, i);
	color(sc, file);
	fill_pixel(x, y, file);
}
