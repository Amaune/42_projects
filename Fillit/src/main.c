/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 10:53:32 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 11:02:56 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int ac, char **av)
{
	t_lst	*list;
	t_map	*map;

	list = NULL;
	if (ac != 2)
		return (write(1, "usage: fillit input_file\n", 25));
	if (!(list = fill_read_it(open(av[1], O_RDONLY), list)))
		return (write(1, "error\n", 6));
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map = fill_solve(list, map);
	map_display(map);
	list_free(list);
	map_free(map);
	free(map);
	return (0);
}
