/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:18:40 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:30:13 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	j;

	j = 0;
	if (s == 0)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[j] != 0 && s[j] && f)
	{
		dst[j] = f(j, s[j]);
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
