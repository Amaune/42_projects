/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_bresenham.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 17:59:01 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:59:02 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "fdf1.h"

void	fill_pixel(t_fdf *fdf, int x, int y)
{
	int i;

	i = (x * 4) + (y * (fdf->size_l));
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		fdf->img[i] = (char)fdf->color.b;
		fdf->img[i + 1] = (char)fdf->color.g;
		fdf->img[i + 2] = (char)fdf->color.r;
	}
}

void    premiercas(t_brese bres, t_fdf *fdf)
{
	bres.cumul = bres.dx / 2;
	while (bres.i <= bres.dx)
	{
		bres.x += bres.xinc;
		bres.cumul += bres.dy;
		if (bres.cumul >= bres.dx)
		{
			bres.cumul -= bres.dx;
			bres.y += bres.yinc;
		}
		fill_pixel(fdf, (double)bres.x, (double)bres.y);
		bres.i++;
	}
}

void    secondcas(t_brese bres, t_fdf *fdf)
{
	bres.cumul = bres.dy / 2;
	while (bres.i <= bres.dy) 
	{
		bres.y += bres.yinc;
		bres.cumul += bres.dx;
		if (bres.cumul >= bres.dy) 
		{
			bres.cumul -= bres.dy;
			bres.x += bres.xinc; 
		}
		fill_pixel(fdf, (double)bres.x, (double)bres.y);
		bres.i++;
	}
	
}

void    bresenham(t_fdf *fdf)
{
	t_brese	bres;

	bres.i = 1;
	bres.x = fdf->start.x;
	bres.y = fdf->start.y;
	bres.dx = fdf->end.x - fdf->start.x;
	bres.dy = fdf->end.y - fdf->start.y;
	bres.xinc = (bres.dx > 0) ? 1 : -1;
	bres.yinc = (bres.dy > 0) ? 1 : -1;
	bres.dx = fabs(bres.dx);
	bres.dy = fabs(bres.dy);
	fill_pixel(fdf, (double)bres.x, (double)bres.y);
	if (bres.dx > bres.dy)
		premiercas(bres, fdf);
	else 
		secondcas(bres, fdf);
}
