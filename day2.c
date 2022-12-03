#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	actual_next_game(char *line)
{
	int	my_answer = line[2] - 87;
	int	oponent = line[0] - 64;

	if (my_answer == 1)
	{
		if (oponent == 2 || oponent == 3)
			return (oponent - 1);
		return (3);
	}
	else if (my_answer == 2)
		return (oponent + 3);
	if (oponent == 1 || oponent == 2)
		return (oponent + 1 + 6);
	return (7);
}

// int	next_game(char *line)
// {
// 	int	my_answer = line[2] - 87;
// 	int	oponent = line[0] - 64;

// 	// printf("my_answer: %c\nopponent: %c\n", line[2], line[0]);
// 	// printf("my_answer: %d\nopponent: %d\n", my_answer, oponent);
// 	if (my_answer == oponent)
// 		return (my_answer + 3);
// 	else if (my_answer == oponent + 1 || my_answer == oponent - 2)
// 		return (my_answer + 6);
// 	return (my_answer);
// }

int	main(void)
{
	int		fd;
	char	*line = malloc(4);
	int		result;

	result = 0;
	if (line == NULL)
		return (1);
	fd = open("input.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	read(fd, line, 4);
	while (line[0] != '.')
	{
		result += actual_next_game(line);
		read(fd, line, 4);
	}
	free(line);
	close(fd);
	printf("%d\n", result);
	return (result);
}