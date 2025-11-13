#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char* line;

	line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		fflush(stdout); // lorsqu'on lit le début d'une ligne sur l'entrée standard, on force l'affichage après 2 "ctrl + d". sinon, printf écrit dans un buffer qui ne s'affiche pas tout de suite
		free(line);
		line = get_next_line(0);
	}
	return 0;
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	char* line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return 0;
// }
