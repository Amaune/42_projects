/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 16:22:27 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 16:22:30 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	file_display(t_file *file)
{
	file->img_ptr = mlx_new_image(file->mlx_ptr, WIDTH, HEIGHT);
	file->img = mlx_get_data_addr(file->img_ptr, &file->bpp, &file->size_l,
		&file->endian);
	mlx_clear_window(file->mlx_ptr, file->win_ptr);
	multithread(file);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->img_ptr, 0, 0);
	mlx_destroy_image(file->mlx_ptr, file->img_ptr);
}

int		main(int ac, char **av)
{
	t_file	*file;
	int		fd;

	fd = 0;
	if (ac != 2)
		return (write(1, 
		"usage: ./fractol [julia, mandelbrot, burningship]\n", 50));
	if (!((ft_strcmp(av[1], "julia") == 0) || (ft_strcmp(av[1],
		"mandelbrot") == 0) || (ft_strcmp(av[1], "burningship") == 0)))
		return (write(1, 
		"wrong name [julia, mandelbrot, burningship]\n", 44));
	if (!(file = malloc(sizeof(t_file))))
		return (0);
	file->mlx_ptr = mlx_init();
	file->win_ptr = mlx_new_window(file->mlx_ptr, WIDTH, HEIGHT, "fractol");
	selector(av[1], file);
	file->tmp_x = 0;
	file->tmp_y = 0;
	file->radius = 4;
	file_display(file);
	mlx_hook(file->win_ptr, 2, 0, event, file);
	mlx_hook(file->win_ptr, 17, 0, out, (void *)0);
	mlx_hook(file->win_ptr, 4, 0, mouse_press, file);
	mlx_hook(file->win_ptr, 6, 0, mouse_move, file);
	mlx_loop(file->mlx_ptr);
}
