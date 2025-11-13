#include "get_next_line.h"

char* join_and_free(char* s1, const char* s2)
{
	if (s1 == NULL || s2 == NULL)
		return NULL;

    char* result = calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
    if (result == NULL)
    {
		free(s1);
		return NULL;
	}

    strcpy(result, s1);
    strcat(result, s2);
	free(s1);
    return result;
}

char* fill_buffer(int fd, char* buffer)
{
	char buffer_read[BUFFER_SIZE + 1];
	ssize_t n;

	while (strchr(buffer, '\n') == NULL)
	{
		n = read(fd, buffer_read, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return NULL;
		}
		if (n == 0)
			break;
		buffer_read[n] = '\0';
		buffer = join_and_free(buffer, buffer_read);
		if (buffer == NULL)
			return NULL;
	}
	if (buffer[0] == '\0')
	{
		free(buffer);
		return NULL;
	}
	return buffer;
}

char* extract_line(char* buffer)
{
	size_t i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	char* result = calloc(i + 1, sizeof(char));
	if (result == NULL)
		return NULL;
	strncpy(result, buffer, i);
	return result;
}

char* update_buffer(char* buffer)
{
	size_t i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0' || buffer[i + 1] == '\0')
	{
		free(buffer);
		return NULL;
	}
	memmove(buffer, buffer + i + 1, strlen(buffer + i + 1) + 1);
	return buffer;
}

char* get_next_line(int fd)
{
	static char* buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	if (buffer == NULL)
	{
		buffer = strdup("");
		if (buffer == NULL)
			return NULL;
	}

	buffer = fill_buffer(fd, buffer);
	if (buffer == NULL)
		return NULL;

	char* result = extract_line(buffer);
	if (result == NULL)
		return NULL;

	buffer = update_buffer(buffer);

	return result;
}
