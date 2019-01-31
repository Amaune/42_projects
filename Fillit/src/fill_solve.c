/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_solve.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 13:42:15 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 13:42:17 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	*place(int p[2], t_lst *list)
{
	int		x;
	int		y;
	char	**tab;

	x = 0;
	tab = list->data;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == '#')
			{
				p[0] = x;
				p[1] = y;
				return (p);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void		l_origin(t_lst *list)
{
	int		x;
	int		y;
	int		p[2];
	int		numb;
	t_lst	*tab;

	x = 0;
	numb = 0;
	tab = list;
	place(p, list);
	while (tab->data[x])
	{
		y = -1;
		while (tab->data[x][++y])
			if (tab->data[x][y] == '#')
			{
				tab->coord[numb].x = x - p[0];
				tab->coord[numb].y = y - p[1];
				numb++;
			}
		x++;
	}
}

void origin(t_lst *list)
{
	t_lst *tmp;

	tmp = list;
	while (tmp)
	{
		l_origin(tmp);
		tmp = tmp->next;
	}
}

static int	l_sqrt(int nb)
{
	int size;

	size = 2;
	while (size < nb / size)
		size++;
	return (size);
}

t_map		*fill_solve(t_lst *list, t_map *map)
{
	t_lst *tmp;
	int		size;

	tmp = list;
	size = l_sqrt(lstcount(tmp) * 4);
	map = map_creator(size, map);
	while (!(fill_alg(tmp, map)))
	{
		map_free(map);
		size++;
		map = map_creator(size, map);
	}
	return (map);
}
