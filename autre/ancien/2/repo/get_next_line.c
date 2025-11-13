/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:25 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/21 15:55:33 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		get_next_line_2(char *buffer, int fd, char **result, int stop);
static int		ft_update_buffer(char *buffer, int fd);
static size_t	ft_position_stop(char *buffer, int *stop);
static int		ft_update_result(char **result, char *buffer, size_t i_stop);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*result;

	if (fd < 0)
		return (NULL);
	result = NULL;
	if (get_next_line_2(buffer, fd, &result, 0))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static int	get_next_line_2(char *buffer, int fd, char **result, int stop)
{
	size_t	i_stop;

	if (ft_update_buffer(buffer, fd) < 1)
		return (1);
	i_stop = ft_position_stop(buffer, &stop);
	if (ft_update_result(result, buffer, i_stop))
		return (1);
	ft_rewind_buffer(buffer, i_stop);
	if (stop)
		return (0);
	return (get_next_line_2(buffer, fd, result, stop));
}

static int	ft_update_buffer(char *buffer, int fd)
{
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE && buffer[i])
		i++;
	return (read(fd, buffer + i, BUFFER_SIZE - i));
}

static size_t	ft_position_stop(char *buffer, int *stop)
{
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[i] == '\n')
		*stop = 1;
	if (buffer[i] == '\n')
		i++;
	return (i);
}

/*
a b c d \0
istop 5

i 0
buffersize 4

*/

static int	ft_update_result(char **result, char *buffer, size_t i_stop)
{
	size_t	len_result;
	char	*new_result;
	size_t	i;

	len_result = ft_strlen(*result);
	new_result = malloc(sizeof(char) * (len_result + i_stop + 1));
	if (new_result == NULL)
		return (1);
	i = 0;
	while (*result && (*result)[i])
	{
		new_result[i] = (*result)[i];
		i++;
	}
	while (i - len_result < i_stop)
	{
		new_result[i] = buffer[i - len_result];
		i++;
	}
	new_result[i] = '\0';
	if (result != NULL)
		free(*result);
	*result = new_result;
	return (0);
}
