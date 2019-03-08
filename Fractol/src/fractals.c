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

/*void		get_smooth_color(t_file *file, double sc)
{
	int		clr1;
	int		clr2;
	double	t1;
	double	t2;

	clr1 = (int)sc;
	t2 = sc - clr1;
	t1 = 1 - t2;
	clr1 = clr1 % 255;
	clr2 = (clr1 + 1) % 255;
	file->color.red = (int)(clr1 * t1 + clr2 * t2);
	file->color.green = (int)(clr1 * t1 + clr2 * t2);
	file->color.blue = (int)(clr1 * t1 + clr2 * t2);
}*/

double	smooth_coloring(t_file *file, int i)
{
	double	sc;
	double	p;
	double	fman;

	fman = (file->frac.newIm * file->frac.newIm) + (file->frac.newRe * file->frac.newRe);
	//sc = (i - log(log(file->frac.newRe * file->frac.newRe))) / log(log(file->radius));
	p = log(fman * fman) / log((fman - 1) * (fman - 1));
	sc = i - (log(0.5 * fman)) - (log(0.5 * log(file->radius)) / log(p));
	return (sc);
}

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

void julia(t_file *file, int x, int y)
{
	int		i;
	double	sc;

	file->frac.newRe = 1.5 * (x - WIDTH / 2) / (0.5 * file->frac.zoom * WIDTH) + file->frac.moveX;
	file->frac.newIm = (y - HEIGHT / 2) / (0.5 * file->frac.zoom * HEIGHT) + file->frac.moveY;
	i = 0;
	while (i < file->frac.maxIterations)
	{
		file->frac.oldRe = file->frac.newRe;
		file->frac.oldIm = file->frac.newIm;
		file->frac.newRe = file->frac.oldRe * file->frac.oldRe - file->frac.oldIm * file->frac.oldIm + file->frac.cRe;
		file->frac.newIm = 2 * file->frac.oldRe * file->frac.oldIm + file->frac.cIm;
		if ((file->frac.newRe * file->frac.newRe + file->frac.newIm * file->frac.newIm) > 4)
			break;
		i++;
	}
	//sc = i + 1 - log(log(file->frac.newIm)) / log(3);
	//get_smooth_color(file, sc);
	sc = smooth_coloring(file, i);
	file->color.blue = ((int)sc) % 255 * file->frac.maxIterations;
	file->color.green = ((int)sc) % 255 * i % file->frac.maxIterations;
	file->color.red = ((int)sc) % 255 % file->frac.maxIterations;
	fill_pixel(x, y, file);
}

void	mandelbrot(t_file *file, int x, int y)
{
	int		i;
	double	sc;
	
	file->frac.cRe = 1.5 * (x - WIDTH / 2) / (0.5 * file->frac.zoom * WIDTH) + file->frac.moveX;
	file->frac.cIm = (y - HEIGHT / 2) / (0.5 * file->frac.zoom * HEIGHT) + file->frac.moveY;
	file->frac.newRe = file->frac.newIm = file->frac.oldRe = file->frac.oldIm = 0;
	i = 0;
	while (i < file->frac.maxIterations)
	{
		file->frac.oldRe = file->frac.newRe;
		file->frac.oldIm = file->frac.newIm;
		file->frac.newRe = file->frac.oldRe * file->frac.oldRe - file->frac.oldIm * file->frac.oldIm + file->frac.cRe;
		file->frac.newIm = 2 * file->frac.oldRe * file->frac.oldIm + file->frac.cIm;
		if((file->frac.newRe * file->frac.newRe + file->frac.newIm * file->frac.newIm) > 4)
			break;
		i++;
	}
	sc = smooth_coloring(file, i);
	file->color.blue = ((int)sc) % 255 * file->frac.maxIterations;
	file->color.green = ((int)sc) % 255 * i % file->frac.maxIterations;
	file->color.red = ((int)sc) % 255 % file->frac.maxIterations;
	fill_pixel(x, y, file);
}

void	burningship(t_file *file, int x, int y)
{
	int i;
	
	file->frac.cRe = 1.5 * (x - WIDTH / 2) / (0.5 * file->frac.zoom * WIDTH) + file->frac.moveX;
	file->frac.cIm = (y - HEIGHT / 2) / (0.5 * file->frac.zoom * HEIGHT) + file->frac.moveY;
	file->frac.newRe = file->frac.newIm = file->frac.oldRe = file->frac.oldIm = 0;
	i = 0;
	while (i < file->frac.maxIterations)
	{
		file->frac.oldRe = file->frac.newRe;
		file->frac.oldIm = file->frac.newIm;
		file->frac.newRe = fabs(file->frac.oldRe) * fabs(file->frac.oldRe) - fabs(file->frac.oldIm) * fabs(file->frac.oldIm) + file->frac.cRe;
		file->frac.newIm = 2 * fabs(file->frac.oldRe) * fabs(file->frac.oldIm) + file->frac.cIm;
		if((file->frac.newRe * file->frac.newRe + file->frac.newIm * file->frac.newIm) > 4)
			break;
		i++;
	}
	file->color.blue = i % 255 * (i / file->frac.maxIterations);
	file->color.green = i % 255;
	file->color.red = i % 255;
	fill_pixel(x, y, file);
}