/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 12:50:40 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 12:50:44 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		rot(int key, t_fdf *fdf)
{
	if (key == 86)
		fdf->teta -= 0.05;
	if (key == 88)
		fdf->teta += 0.05;
	if (key == 91)
		fdf->x_teta -= 0.05;
	if (key == 84)
		fdf->x_teta += 0.05;
	if (key == 2)
		fdf->y_teta -= 0.05;
	if (key == 0)
		fdf->y_teta += 0.05;
	fdf_display(fdf);
	return (0);
}

int		iso(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		fdf->teta = 0.8;
		fdf->x_teta = -7.3;
		fdf->y_teta = 0;
		fdf->elev = 0.09;
	}
	fdf_display(fdf);
	return (0);
}

int		reset(int key, t_fdf *fdf)
{
	if (key == 15)
	{
		fdf->teta = 0;
		fdf->x_teta = 0;
		fdf->y_teta = 0;
	}
	fdf_display(fdf);
	return (0);
}

int		zoom(int key, t_fdf *fdf)
{
	if (key == 6)
		fdf->zoom = 30;
	fdf_display(fdf);
	return (0);
}

int		event(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 121)
		fdf->elev -= 0.05;
	if (key == 116)
		fdf->elev += 0.05;
	if (key == 123)
		fdf->decal_x -= 10;
	if (key == 124)
		fdf->decal_x += 10;
	if (key == 125)
		fdf->decal_y += 10;
	if (key == 126)
		fdf->decal_y -= 10;
	if (key == 18)
		fdf->color.startc = rand();
	if (key == 19)
		fdf->color.endc = rand();
	rot(key, fdf);
	reset(key, fdf);
	iso(key, fdf);
	zoom(key, fdf);
	fdf_display(fdf);
	return (0);
}
