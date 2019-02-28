/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   plus.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 11:16:36 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 11:16:37 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_lst(t_fdf *fdf)
{
	t_flst *tmp;

	tmp = fdf->map;
	while (tmp)
	{
		fdf->map = fdf->map->next;
		free(fdf->map->i_tab);
		free(tmp);
		tmp = fdf->map;
	}
}

int		mouse_press(int key, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key == 4)
		fdf->zoom += 0.5;
	if (key == 5)
		fdf->zoom -= 0.5;
	fdf_display(fdf);
	return (0);
}
