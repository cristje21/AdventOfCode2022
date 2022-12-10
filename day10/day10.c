#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	addx(int *sprite_position, int cycle_count, int x, int check)
{
	static int	result = 0;

	while (check)
	{
		cycle_count++;
		if (cycle_count == 20 || cycle_count == 60 || cycle_count == 100 ||
			cycle_count == 140 || cycle_count == 180 || cycle_count == 220)
		{
			result += cycle_count * (*sprite_position);
			if (cycle_count == 220)
				printf("result: %d\n", result);
		}
		check--;
	}
	*sprite_position += x;
	return (cycle_count);
}
int main(void)
{
	FILE	*fp;
	int		cycle_count;
	int		sprite_position;
	char	line[10];

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		return (0);
	cycle_count = 0;
	sprite_position = 1;
	while (fgets(line, 10, fp) != NULL)
	{
		if (!strncmp(line, "addx", (long unsigned)4))
			cycle_count = addx(&sprite_position, cycle_count, atoi(&line[5]), 2);
		else if (!strncmp(line, "noop", (long unsigned)4))
			cycle_count = addx(&sprite_position, cycle_count, 0, 1);
	}
	return (0);
}

//20 60 100 140 180 220