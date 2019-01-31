/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_color.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 12:13:27 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 12:13:28 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	hextorgb(int hex, t_fdf *fdf)
{
	fdf->color.red = (hex >> 16) & 255;
	fdf->color.green = (hex >> 8) & 255;
	fdf->color.blue = (hex) & 255;
}

double	percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_brese *bres, t_fdf *fdf)
{
	double  percentage;

	if (fdf->color.color == fdf->color.endc)
		return (1);
	if (bres->x > bres->y)
		percentage = percent(fdf->start.x, fdf->end.x, bres->x);
	else
		percentage = percent(fdf->start.y, fdf->end.y, bres->y);
	if (fabs(fdf->z) < fabs(fdf->z_1))
	{
		fdf->color.red = get_light((fdf->color.startc >> 16) & 0xFF, (fdf->color.endc >> 16) & 0xFF, percentage);
		fdf->color.green = get_light((fdf->color.startc >> 8) & 0xFF, (fdf->color.endc >> 8) & 0xFF, percentage);
		fdf->color.blue = get_light(fdf->color.startc & 0xFF, fdf->color.endc & 0xFF, percentage);
	}
	else
	{
		fdf->color.red = get_light((fdf->color.endc >> 16) & 0xFF, (fdf->color.startc >> 16) & 0xFF, percentage);
		fdf->color.green = get_light((fdf->color.endc >> 8) & 0xFF, (fdf->color.startc >> 8) & 0xFF, percentage);
		fdf->color.blue = get_light(fdf->color.endc & 0xFF, fdf->color.startc & 0xFF, percentage);
	}
	return (1);
}