/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 10:05:03 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 10:05:04 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->elev = 1;
	fdf->zoom = 30;
	fdf->decal_x = WIDTH / 2;
	fdf->decal_y = HEIGHT / 2;
	fdf->teta = 0.6;
	fdf->x_teta = -7.5;
	fdf->y_teta = 0;
}

void	fdf_display(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l,
		&fdf->endian);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	free_cord(fdf);
	creat_tab(fdf);
	fdf_algo(fdf);
	set_hud(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	hud_com(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
}

int		out(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	fonctions(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf");
	fdf_display(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, event, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, out, (void *)0);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	fd = 0;
	if (ac != 2)
		return (write(1, "usage: ./fdf map\n", 17));
	if (!(fdf = malloc(sizeof(t_fdf))))
		return (0);
	init(fdf);
	init_color(fdf);
	if ((fd = open(av[1], O_RDONLY)) < 1)
	{
		free(fdf);
		return (write(1, "file invalide\n", 14));
	}
	if (!(fdf_traitement(av[1], fdf)))
	{
		free(fdf);
		return (write(1, "map error\n", 10));
	}
	fonctions(fdf);
}
