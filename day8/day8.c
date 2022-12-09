#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int check_left_right(char **grid, int i, int j);

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
	while (i < 100)
	{
		grid[i] = malloc(100);
		if (grid[i] == NULL)
			return (NULL); //free all
		fgets(buffer, 200, fp);
		strncpy(grid[i], buffer, 99);
		grid[99] = '\0';
		i++;
	}
	grid[i] = NULL;
	fclose(fp);
	return (grid);
}

// int	check_left_right(char **grid, int i, int j)
// {
// 	int	temp;

// 	temp = 0;
// 	if (i == 0  || i == 98 || j == 0 || i == 0)
// 		return (1);
// 	while (temp < j)
// 	{
// 		if (grid[i][temp] < grid[i][j])
// 		{
// 			temp++;
// 			continue ;
// 		}
// 		break ;
// 	}
// 	if (temp == j)
// 		return (1);
// 	temp = 98;
// 	while (temp > j)
// 	{
// 		if (grid[i][temp] < grid[i][j])
// 		{
// 			temp--;
// 			continue ;
// 		}
// 		break;
// 	}
// 	if (temp == j)
// 		return (1);
// 	return (0);
// }

// int	check_up_down(char **grid, int i, int j)
// {
// 	int	temp;

// 	temp = 0;
// 	if (i == 0  || i == 98 || j == 0 || i == 0)
// 		return (1);
// 	while (temp < j)
// 	{
// 		if (grid[temp][j] < grid[i][j])
// 		{
// 			temp++;
// 			continue ;
// 		}
// 		break ;
// 	}
// 	if (temp == i)
// 		return (1);
// 	temp = 98;
// 	while (temp > i)
// 	{
// 		if (grid[temp][j] < grid[i][j])
// 		{
// 			temp--;
// 			continue ;
// 		}
// 		break;
// 	}
// 	if (temp == i)
// 		return (1);
// 	return (0);
// }

int	visibily(char **grid, int i, int j)
{
	if (check_left_right(grid, i, j))
		return (1);
	// else if (check_up_down(grid, i, j))
	// 	return (1);
	return (0);
}

char	**do_all_sides(char **my_grid, char **grid)
{
	int	i, j;
	static int count = 0;

	i = 0;
	while (i < 99)
	{
		j = 0;
		while (j < 99)
		{
			if (visibily(grid, i, j))
			{
				my_grid[i][j] = 'v';
				count++;
				printf("%d, ", count);
			}
			else
				my_grid[i][j] = 'x';
			j++;
		}
		i++;
	}
	return (my_grid);
}

int check_left_right(char **grid, int i, int j)
{
	int	temp;

	temp = 0;
	if (i == 0 || j == 0 || (i == (int)strlen(grid[0]) - 1) || (j == (int)strlen(grid[0]) - 1))
		return (1);
	printf("check");
	while (temp < (int)strlen(grid[0]))
	{
		if (grid[temp][j] < grid[i][j])
			temp++;
		else if (grid[temp][i] >= grid[i][j] && temp > i)
			break ;
		else if (temp == i)
			return (1);
	}
	if (temp == (int)strlen(grid[0]))
		return (1);
	temp = 0;
	while (temp < 99)
	{
		if (grid[i][temp] < grid[i][j])
			temp++;
		else if (grid[i][temp] >= grid[i][j] && temp > j)
			break ;
		else if (temp == i)
			return (1);
	}
	if (temp == 99)
		return (1);
	return (0);
}
int	count_v(char **grid)
{
	int	i, j, count;

	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while ((grid[i][j] == 'v' || grid[i][j] == 'x') && (grid[i][j] && grid[i][j] != '\n'))
		{
			if (grid[i][j] == 'v')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	main(void)
{
	char	**grid;
	char	**my_grid;
	int		i;

	i = 0;
	grid = make_grid();
	my_grid = malloc(100 * sizeof(char *));
	if (my_grid == NULL)
		return (0);
	while (grid[i])
	{
		my_grid[i] = strdup(grid[i]);
		i++;
	}
	my_grid[i] = NULL;
	my_grid = do_all_sides(my_grid, grid);
	// for (int j = 1; j < 2; j++)
	// 	printf("%s", grid[j]);
	// printf("\n");
	// for (int j = 1; j < 2; j++)
	// 	printf("%s", my_grid[j]);
	// printf("\n");
	// printf("%ld\n", strlen(grid[1]));
	// i = count_v(my_grid);
	// printf("count: %d\n", i);
	return (0);
}