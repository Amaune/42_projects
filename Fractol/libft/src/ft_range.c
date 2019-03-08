/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:51:14 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 11:56:02 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *dest;

	i = 0;
	if (min >= max)
		return (0);
	if (!(dest = ft_memalloc(max - min)))
		return (0);
	while (min < max)
	{
		dest[i] = min;
		min++;
		i++;
	}
	return (dest);
}
