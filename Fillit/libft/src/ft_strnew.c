/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 13:29:55 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 13:40:00 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
		tab[i++] = 0;
	tab[i] = 0;
	return (tab);
}
