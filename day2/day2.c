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

int	next_game(char *line)
{
	int	my_answer = line[2] - 87;
	int	oponent = line[0] - 64;

	if (my_answer == oponent)
		return (my_answer + 3);
	else if (my_answer == oponent + 1 || my_answer == oponent - 2)
		return (my_answer + 6);
	return (my_answer);
}

int	main(void)
{
	int		fd;
	char	line[4];
	int		result_part_one;
	int		result_part_two;

	result_part_one = 0;
	result_part_two = 0;
	fd = open("input_day2.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	read(fd, line, 4);
	while (line[0] != '.')
	{
		result_part_one += next_game(line);
		result_part_two += actual_next_game(line);
		read(fd, line, 4);
	}
	close(fd);
	printf("part 1: %d\npart 2: %d\n", result_part_one, result_part_two);
	return (0);
}