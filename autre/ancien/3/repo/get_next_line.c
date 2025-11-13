/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:25 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/23 14:33:39 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_analyse_buffer(char *buffer, int i_start, int *i_stop, int *stop, char *result);
int	ft_update_result(char **result, char *buffer, int i_stop);
void	ft_rewind_buffer(char *buffer, int i_stop);
size_t	ft_strlen(const char *s);
void	ft_rewind_buffer(char *buffer, int i_start);
size_t	ft_strlen_buffer(const char *s);
void	ft_strcpy(char *dst, char *src);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*result;
	int			i_start;
	int			n_read;
	int			stop;

	if (fd < 0)
		return (NULL);
	result = NULL;
	n_read = read(fd, buffer, BUFFER_SIZE);
	stop = ft_has_new_line(buffer);
	while (n_read > 0 && !stop)
	{
		if (ft_analyse_buffer(buffer, i_start, &i_stop, &stop, result)
			|| ft_update_result(&result, buffer, i_stop))
		{
			free(result);
			return (NULL);
		}
		ft_rewind_buffer(buffer, i_stop);
		i_start = ft_strlen(buffer);
		n_read = read(fd, buffer + i_start, BUFFER_SIZE - i_start);
	}
	if (n_read == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

int	ft_analyse_buffer(char *buffer, int i_start, int *i_stop, int *stop, char *result)
{
	int	i;

	if (*i_stop - i_start == -1)
		return (1);
	if (*i_stop != BUFFER_SIZE)
		*stop = 1;
	i = i_start;
	while (i < *i_stop)
	{
		if (buffer[i] == '\n')
		{
			*stop = 1;
			*i_stop = i + 1;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_update_result(char **result, char *buffer, int i_stop)
{
	int		len_previous_result;
	char	*new_result;
	int		i;

	len_previous_result = ft_strlen(*result);
	new_result = malloc(sizeof(char) * (len_previous_result + i_stop + 1));
	if (new_result == NULL)
		return (1);
	new_result = ft_strjoin(*result, buffer, i_stop);
	if ()
		return (1);
	ft_strcpy(new_result, *result);
	i = len_previous_result;
	while (i - len_previous_result < i_stop)
	{
		new_result[i] = buffer[i - len_previous_result];
		i++;
	}
	new_result[i] = '\0';
	free(*result);
	*result = new_result;
	return (0);
}

int	ft_strjoin(char **s1, char *s2, int i_stop)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (1);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

void	ft_strcpy(char *dst, char *src)
{
	if (src == NULL)
		return ;
	while (*src)
		*dst++ = *src++;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_rewind_buffer(char *buffer, int i_start)
{
	int	i_start_save;

	i_start_save = i_start;
	while (i_start < BUFFER_SIZE)
	{
		buffer[i_start - i_start_save] = buffer[i_start];
		i_start++;
	}
	if (i_start - i_start_save < BUFFER_SIZE)
		buffer[i_start - i_start_save] = '\0';
}
