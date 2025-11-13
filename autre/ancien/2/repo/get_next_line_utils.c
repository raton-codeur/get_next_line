/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:18:43 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/21 15:59:09 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_rewind_buffer(char *buffer, size_t i)
{
	size_t	i_start;

	i_start = i;
	while (i < BUFFER_SIZE)
	{
		buffer[i - i_start] = buffer[i];
		i++;
	}
}
