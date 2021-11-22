/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:54:59 by hlucie            #+#    #+#             */
/*   Updated: 2021/02/04 23:31:04 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_malloc_ultra(char *ptr, size_t size)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	str = NULL;
	len = 0;
	if (!ptr)
	{
		if (!(str = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		*str = '\0';
		return (str);
	}
	len = size + ft_strlen(ptr);
	if (!(str = malloc(sizeof(char *) * (ft_strlen(ptr) + len + 1))))
		return (NULL);
	while (ptr[++i] != '\0')
		str[i] = ptr[i];
	str[i] = '\0';
	ft_free_plz(&ptr);
	ptr = NULL;
	return (str);
}

char	*ft_strdup_custom(char *s, char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	ft_free_plz(&str);
	return (dest);
}

void	ft_free_plz(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
