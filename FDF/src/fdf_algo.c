/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_algo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-201.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 11:37:14 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 11:37:20 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf1.h"

void       fdf_algo_x(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width - 1)
		{
			fdf->start.x = fdf->f_tab[i][j].x * fdf->zoom + fdf->decal_x;
			fdf->start.y = fdf->f_tab[i][j].y * fdf->zoom - (fdf->f_tab[i][j].z * fdf->elev) + fdf->decal_y;
			fdf->end.x = fdf->f_tab[i][j + 1].x * fdf->zoom + fdf->decal_x;
			fdf->end.y = fdf->f_tab[i][j + 1].y * fdf->zoom - (fdf->f_tab[i][j + 1].z * fdf->elev) + fdf->decal_y;
			bresenham(fdf);
			j++;
		}
		i++;
	}
}

void	fdf_algo_y(t_fdf *fdf)
{
	int i;
	int j;
	
	i = 0;
	while (i + 1 < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			fdf->start.x = fdf->f_tab[i][j].x * fdf->zoom + fdf->decal_x;
			fdf->start.y = fdf->f_tab[i][j].y * fdf->zoom - (fdf->f_tab[i][j].z * fdf->elev) + fdf->decal_y;
			fdf->end.x = fdf->f_tab[i + 1][j].x * fdf->zoom + fdf->decal_x;
			fdf->end.y = fdf->f_tab[i + 1][j].y * fdf->zoom - (fdf->f_tab[i + 1][j].z * fdf->elev) + fdf->decal_y;
			bresenham(fdf);
			j++;
		}
		i++;
	}
}

void	fdf_algo(t_fdf *fdf)
{
	fdf_algo_x(fdf);
	fdf_algo_y(fdf);
}