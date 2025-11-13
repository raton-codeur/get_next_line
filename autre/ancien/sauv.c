#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 25
#endif

size_t custom_strlen(const char* s)
{
	if (s == NULL)
		return 0;
	return strlen(s);
}

char* custom_strjoin(const char* s1, const char* s2)
{
    char* result = calloc(custom_strlen(s1) + custom_strlen(s2) + 1, sizeof(char));
    if (result == NULL)
        return NULL;
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int has_line(const char* s)
{
	if (s == NULL)
		return 0;
	while (*s)
	{
		if (*s == '\n')
			return 1;
		s++;
	}
	return 0;
}

char* read_(int fd, char* buffer)
{
	char buffer_read[BUFFER_SIZE + 1];
	int n;

	n = 1;
	while (n > 0 && has_line(buffer) == 0)
	{
		n = read(fd, buffer_read, BUFFER_SIZE);
		if (n == -1)
			return free(buffer), NULL;
		buffer_read[n] = '\0';
		buffer = custom_strjoin(buffer, buffer_read);
		if (buffer == NULL)
			return NULL;
	}
	return buffer;
}

char* get_line(char* buffer)
{
	char* line = NULL;
	char* newline = custom_strchr(buffer, '\n');
	if (newline)
	{
		size_t len = newline - buffer + 1;
		line = calloc(len + 1, sizeof(char));
		if (line)
		{
			strncpy(line, buffer, len);
			line[len] = '\0';
		}
	}
	return line;
}

char* update(char* buffer)
{}

char* get_next_line(int fd)
{
	static char* buffer;
	char* result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_(fd, buffer);
	result = get_line(buffer);
	buffer = update(buffer);
	return result;
}

int main()
{
	char* line = get_next_line(0);
	printf("%s", line);
	free(line);
	return 0;
}
