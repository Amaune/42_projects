/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 12:56:47 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:31:21 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tab;

	if (!(tab = (char *)malloc(sizeof(size_t) * size)))
		return (NULL);
	while (size > 0)
		tab[--size] = 0;
	return ((void *)tab);
}
