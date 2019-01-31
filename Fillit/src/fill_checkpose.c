/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_checkpose.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 13:45:36 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 13:45:38 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	checkfree(int i, int j, t_lst *list, t_map *map)
{
	int count;

	count = 0;
	while (count < 4)
	{
		if (!(map->size > i + list->coord[count].x && map->size >
		j + list->coord[count].y &&
		map->tab[i + list->coord[count].x][j + list->coord[count].y] == '.'))
			return (0);
		count++;
	}
	return (1);
}

static int	placeit(int i, int j, t_lst *list, t_map *map)
{
	int count;

	count = 0;
	if (checkfree(i, j, list, map))
	{
		while (count < 4)
		{
			map->tab[i + list->coord[count].x][j + list->coord[count].y] =
			65 + list->id;
			count++;
		}
	}
	else
	{
		return (0);
	}
	return (1);
}

void		erase(int i, int j, t_lst *list, t_map *map)
{
	int count;

	count = 0;
	while (count < 4)
	{
		map->tab[i + list->coord[count].x][j + list->coord[count].y] = '.';
		count++;
	}
}

int			fill_alg(t_lst *list, t_map *map)
{
	int i;
	int j;

	i = 0;
	if (list == NULL)
		return (1);
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (placeit(i, j, list, map))
			{
				if (!fill_alg(list->next, map))
				{
					erase(i, j, list, map);
				}
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
