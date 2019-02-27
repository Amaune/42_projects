/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 11:38:46 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 11:38:47 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_color(t_fdf *fdf)
{
	fdf->color.red = 255;
	fdf->color.green = 255;
	fdf->color.blue = 255;
	fdf->color.startc = 0xFFFFFF;
	fdf->color.endc = 0xFF69FF;
}

void	hud_com(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 70, fdf->color.endc,
	"ROT X : 8 | 2");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 98, fdf->color.endc,
	"ROT Y : A | D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 126, fdf->color.endc,
	"ROT Z : 4 | 6");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 154, fdf->color.endc,
	"MOVE : FLECHES");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 182, fdf->color.endc,
	"ZOOM : MOLETTE");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 210, fdf->color.endc,
	"ELEV : PAGE UP/DOWN");
}

void	fill_box(t_fdf *fdf)
{
	int x;
	int y;
	int x1;
	int y1;

	x = 51;
	y = 51;
	x1 = 299;
	y1 = 51;
	while (y < 250)
	{
		fdf->start.x = x;
		fdf->start.y = y;
		fdf->end.x = x1;
		fdf->end.y = y1;
		bresenham(fdf);
		y++;
		y1++;
	}
}

void	box(t_fdf *fdf)
{
	fdf->start.x = 50;
	fdf->start.y = 50;
	fdf->end.x = 50;
	fdf->end.y = 250;
	bresenham(fdf);
	fdf->start.x = 50;
	fdf->start.y = 50;
	fdf->end.x = 300;
	fdf->end.y = 50;
	bresenham(fdf);
	fdf->start.x = 300;
	fdf->start.y = 50;
	fdf->end.x = 300;
	fdf->end.y = 250;
	bresenham(fdf);
	fdf->start.x = 50;
	fdf->start.y = 250;
	fdf->end.x = 300;
	fdf->end.y = 250;
	bresenham(fdf);
}

void	set_hud(t_fdf *fdf)
{
	box(fdf);
	fill_box(fdf);
}
