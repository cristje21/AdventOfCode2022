#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	**make_grid(void)
{
	FILE	*fp;
	char	**grid;
	int		i;
	char	buffer[200];

	i = 0;
	fp = fopen("input_day8.txt", "r");
	if (fp == NULL)
		return (NULL);
	grid = malloc(100 * sizeof(char *));
	if (grid == NULL)
		return (NULL);
	while (fgets(buffer, 110, fp) != NULL)
	{
		grid[i] = malloc(100);
		if (grid[i] == NULL)
			return (NULL);
		strncpy(grid[i], buffer, 99);
		i++;
	}
	grid[i] = NULL;
	fclose(fp);
	return (grid);
}

int	check_visibility(char **grid, int i, int j)
{
	int	temp;

	temp = 0;
	if (i == 0 || j == 0 || i == 98 || j == 98)
		return (1);
	while (grid[i][temp])
	{
		if (temp == j)
			return (1);
		if (grid[i][temp] >= grid[i][j])
			break ;
		temp++;
	}
	temp = j + 1;
	while (grid[i][temp])
	{
		if (grid[i][temp] >= grid[i][j])
			break ;
		temp++;
	}
	if (grid[i][temp] == '\0')
		return (1);
	temp = 0;
	while (grid[temp])
	{
		if (temp == i)
			return (1);
		if (grid[temp][j] >= grid[i][j])
			break ;
		temp++;
	}
	temp = i + 1;
	while (grid[temp])
	{
		if (grid[temp][j] >= grid[i][j])
			return (0);
		temp++;
	}
	return (1);
}

int	main(void)
{
	char	**grid;
	int		i, j;
	int		count;

	i = 0;
	count = 0;
	grid = make_grid();
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (check_visibility(grid, i, j))
				count++;
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	return (0);
}