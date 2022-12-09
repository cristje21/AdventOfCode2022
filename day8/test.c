#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	check_left_right(char *grid, int i)
{
	int	temp;

	temp = 0;
	if (i == 0  || i == strlen(grid) - 1)
		return (1);
	while (temp < i)
	{
		if (grid[temp] < grid[i])
		{
			temp++;
			continue ;
		}
		break ;
	}
	if (temp == i)
		return (1);
	temp = i + 1;
	while (temp < strlen(grid))
	{
		if (grid[temp] < grid[i])
		{
			temp++;
			continue ;
		}
		break;
	}
	if (temp == strlen(grid))
		return (1);
	return (0);
}

int main(void)
{
	char *line;
	char *otherline;
	int     i;

	i = 0;
	line = strdup("12345678555555555555555987654321");
	otherline = strdup(line);
	while (line[i])
	{
		if (check_left_right(line, i))
			otherline[i] = 'v';
		i++;
	}
	printf("%s\n%s\n", otherline, line);
}