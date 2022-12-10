#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	print_screen(char **screen)
{
	int	i;

	i = 0;
	while (screen[i])
	{
		printf("%s\n", screen[i]);
		i++;
	}
}

void	free_all(char **screen)
{
	int	i;

	i = 0;
	while(screen[i])
	{
		free(screen[i]);
		i++;
	}
	free(screen);
}

char	**make_screen(void)
{
	char	**screen;
	int		i;

	screen = malloc(7 * sizeof(char *));
	if (screen == NULL)
		return (NULL);
	i = 0;
	while (i < 6)
	{
		screen[i] = calloc(41, 1);
		if (screen[i] == NULL)
			return(free_all(screen), NULL);
		memset(screen[i], '.', 40);
		i++;
	}
	screen[i] = NULL;
	return (screen);
}

void	assign_screen(char **screen, int addx)
{
	static int	pos = 1;
	static int	cycle = 0;
	static int	i = 0;
	int			amount;

	amount = 2;
	if (addx == 0)
		amount--;
	if (cycle == 40)
	{
		cycle = 0;
		i++;
	}
	while (amount)
	{
		if (cycle >= pos - 1 && cycle <= pos + 1)
			screen[i][cycle] = '#';
		cycle++;
		amount--;
	}
	pos += addx;
}

int	main(void)
{
	char	**screen;
	FILE	*fp;
	char	line[10];

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		return (0);
	screen = make_screen();
	if (screen == NULL)
		return (fclose(fp), 0);
	while (fgets(line, 10, fp) != NULL)
	{
		if (!strncmp(line, "addx", 4))
			assign_screen(screen, atoi(&line[5]));
		else
			assign_screen(screen, 0);
	}
	print_screen(screen);
	return (free(screen), 0);
}
