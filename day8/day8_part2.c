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
	int count[4];

	temp = j - 1;
	if (i == 0 || j == 0 || i == 98 || j == 98)
		return (0);
	while (temp >= 0)
	{
		if (grid[i][temp] >= grid[i][j])
		{
			count[0] = j - temp;
			break ;
		}
		if (temp == 0)
			count[0] = j;
		temp--;
	}
	temp = j + 1;
	while (temp <= 98)
	{
		if (grid[i][temp] >= grid[i][j])
		{
			count[1] = temp - j;
			break ;
		}
		else if (temp == 98)
			count[1] = temp - j;
		temp++;
	}
	temp = i - 1;
	while (temp >= 0)
	{
		if (grid[temp][j] >= grid[i][j])
		{
			count[2] = (i - temp);
			break ;
		}
		else if (temp == 0)
			count[2] = i;
		temp--;
	}
	temp = i + 1;
	while (temp <= 98)
	{
		if (grid[temp][j] >= grid[i][j])
		{
			count[3] = (temp - i);
			break ;
		}
		else if (temp == 98)
			count[3] = (temp - i);
		temp++;
	}
	return (count[0] * count[1] * count[2] * count[3]);
}

int	main(void)
{
	char	**grid;
	int		i, j;
	int		count;
	int		temp_count;

	i = 0;
	count = 0;
	grid = make_grid();
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			temp_count = check_visibility(grid, i, j);
			if (temp_count > count)
				count = temp_count;
			j++;
		}
		i++;
	}
	printf("%d\n", count);
	return (0);
}