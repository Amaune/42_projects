/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 15:51:00 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 15:51:01 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

void	map_free(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->tab[i]));
		i++;
	}
	ft_memdel((void **)&(map->tab));
}

/*void	list_free(t_lst *list)
{
	t_lst *tmp;
	
	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}*/

void list_free(t_lst *list)
{
	int i;
	t_lst *tmp;

	while (list)
	{
		i = 0;
		while (list->data[i])
			free(list->data[i++]);
		free(list->data[i]);
		list->data = NULL;
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
	free(tmp);
}