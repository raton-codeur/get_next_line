/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:45:02 by qhauuy            #+#    #+#             */
/*   Updated: 2023/12/04 16:47:43 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	**result;
	size_t	test_overflow;

	if (count * size == 0)
		return (malloc(0));
	test_overflow = count * size;
	if (test_overflow / count != size)
		return (NULL);
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, '\0', count * size);
	return (result);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = c;
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
