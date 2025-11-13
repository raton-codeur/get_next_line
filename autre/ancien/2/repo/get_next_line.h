/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:09:23 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/20 12:59:26 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
void	ft_rewind_buffer(char *buffer, size_t i_stop);

#endif
