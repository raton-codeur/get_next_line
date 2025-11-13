/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:09:23 by qhauuy            #+#    #+#             */
/*   Updated: 2023/12/04 16:49:09 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

/* get_next_line_bonus.c */
char	*get_next_line(int fd);
int		ft_update_buffer(char **buffer, int fd);
int		ft_init(char **buffer, char **to_add_to_buffer);
char	*ft_get_line(char *buffer);
void	ft_update_buffer_2(char **buffer);

/* get_next_line_utils_bonus.c */
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif
