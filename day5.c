#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	print_stack(char **stacks);

char **move_one(int *instructions, char **stacks)
{
	int		i;
	char	temp;
	int		*all;

	instructions[1]--;
	instructions[2]--;
	all = calloc((instructions[0] + 1), sizeof(int));
	while (instructions[0])
	{
		i = 98;
		while((i > 2) && stacks[i - instructions[0]][instructions[1]])
		{
			if (stacks[i - 1][instructions[1]] == '\0')
				break ;
			i--;
		}
		if (i == 2)
		{
			printf("stack too big!\n");
			return (NULL);
		}
		int k;
		k = 0;
		while (instructions[0])
		{
			all[k] = stacks[i][instructions[1]];
			stacks[i][instructions[1]] = '\0';
			i--;
			instructions[0]--;
			k++;
		}
		i = 98;
		while((stacks[i][instructions[2]]) && (i > 2))
			i--;
		k = 0;
		while (all[k])
		{
			stacks[i][instructions[2]] = all[k];
			i--;
			k++;
		}
	}
	return (stacks);
}
// from 4 to 6
char **do_instructions(char **stacks, FILE *fp)
{
	int		i, j;
	char	one_line[50];
	int		*instructions;

	i = 0;
	fgets(one_line, 50, fp);
	fgets(one_line, 50, fp);
	while (one_line[i] != '.')
	{
		instructions = calloc(3, sizeof(int));
		j = 0;
		while (j < 3)
		{
			if (one_line[i] >= '0' && one_line[i] <= '9')
			{
				while (one_line[i] >= '0' && one_line[i] <= '9')
				{
					instructions[j] = instructions[j] * 10 + one_line[i] - 48;
					i++;
				}
				j++;
			}
			i++;
		}
		stacks = move_one(instructions, stacks);
		i = 0;
		fgets(one_line, 50, fp);
		free(instructions);
	}
	return (stacks);
}

char **create_stack(FILE *fp, char **stacks)
{
	int		i, j, k;
	char	one_line[50];

	i = 91;
	while (i < 100)
	{
		k = 1;
		j = 0;
		fgets(one_line, 50, fp);
		while (j < 9)
		{
			if (one_line[k] != ' ')
				stacks[i][j] = one_line[k];
			k += 4;
			j++;
		}
		stacks[i][j] = '\0';
		i++;
	}
	stacks[i] = NULL;
	return (stacks);
}

void	print_stack(char **stacks)
{
	int	i, j;

	j = 0;
	while (j < 9)
	{
		i = 99;
		while (stacks[i][j])
		{
			if (!stacks[i - 1][j])
				printf("%c", stacks[i][j]);
			i--;
		}
		j++;
	}
	printf("\n");
}

int	main(void)
{
	FILE	*fp;
	char	**stacks;
	int		i;

	i = 0;
	fp = fopen("input_day5.txt", "r");
	if (fp == NULL)
		return (0);
	stacks = malloc(100 * sizeof(char *));
	if (stacks == NULL)
		return (0);
	while (i < 100)
	{
		stacks[i] = calloc(10, 1);
		if (stacks[i] == NULL)
			return (0);
		i++;
	}
	stacks = create_stack(fp, stacks);
	stacks = do_instructions(stacks, fp);
	print_stack(stacks);
	return (0);
}