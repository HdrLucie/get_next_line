/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciehdr <luciehdr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:31:33 by hlucie            #+#    #+#             */
/*   Updated: 2021/02/04 23:35:00 by luciehdr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_next_line(char **line, char **buff_pos, int fd)
{
	char	*buffer;
	int		flag;

	buffer = NULL;
	flag = 0;
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((flag = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		ft_free_plz(buff_pos);
		buffer[flag] = '\0';
		if ((flag = ft_fill_line(line, buffer, buff_pos)))
		{
			ft_free_plz(&buffer);
			return (flag);
		}
	}
	ft_free_plz(&buffer);
	return (flag);
}

int	ft_fill_line(char **line, char *buffer, char **adress_pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	if (!(*line = ft_malloc_ultra(*line, sizeof(char) * i)))
		return (-1);
	j = ft_strlen(*line);
	i = 0;
	while (buffer[i] != '\0' && i < BUFFER_SIZE && buffer[i] != '\n')
		(*line)[j++] = buffer[i++];
	(*line)[j] = '\0';
	if (buffer[i] == '\n')
	{
		*adress_pos = ft_strdup_custom(&(buffer[i + 1]), *adress_pos);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			flag;
	static char	*buff_pos = NULL;

	if (line)
		*line = NULL;
	flag = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (buff_pos && buff_pos[0] != '\0')
	{
		if ((flag = ft_fill_line(line, buff_pos, &buff_pos)))
			return (flag);
		ft_free_plz(&buff_pos);
		buff_pos = NULL;
	}
	if ((flag = ft_read_next_line(line, &buff_pos, fd)))
		return (flag);
	ft_free_plz(&buff_pos);
	if (!(*line))
	{
		if (!(*line = ft_malloc_ultra(*line, 1)))
			return (-1);
		**line = '\0';
	}
	return (0);
}
