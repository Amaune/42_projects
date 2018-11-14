/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 10:49:57 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:05:36 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(int size, char *tab)
{
	int		i;
	int		last_size;
	char	*tab3;

	i = 0;
	last_size = size / 2;
	if (!(tab3 = ft_memalloc(size)))
		return (0);
	while (i < last_size)
	{
		tab3[i] = tab[i];
		i++;
	}
	free(tab);
	return (tab3);
}
