/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 13:08:48 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 13:08:49 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

t_map		*map_creator(int size, t_map *map)
{
	int		i;
	int		j;

	map->size = size;
	map->tab = (char **)malloc(sizeof(char *) * map->size + 1);
	i = 0;
	while (i < size)
	{
		map->tab[i] = ft_strnew(map->size);
		j = 0;
		while (j < size)
		{
			map->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	map->tab[i] = 0;
	return (map);
}

void		map_display(t_map *map)
{
	int i;

	i = 0;
	while (map->tab[i])
	{
		ft_putstr(map->tab[i]);
		ft_putchar('\n');
		i++;
	}
}
