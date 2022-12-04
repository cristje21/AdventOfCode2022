#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//7,7-5,8;

int	check_for_full_overlap(int *pair)
{
	if (pair[0] >= pair[2] && pair[1] <= pair[3])
		return (1);
	else if (pair[0] <= pair[2] && pair[1] >= pair[3])
		return (1);
	return (0);
}

int	part_one_func(FILE *fp)
{
	char	line[15];
	int		pair[4];
	int		i, j;
	int		result;

	fgets(line, 15, fp);
	result = 0;
	while (line[0] != '.')
	{
		i = 0;
		j = 0;
		while (i < 4)
		{
			pair[i++] = atoi(&line[j]);
			while (isdigit(line[j]))
				j++;
			j++;
		}
		result += check_for_full_overlap(pair);
		fgets(line, 15, fp);
	}
	return (result);
}

int	main(void)
{
	FILE	*fp;
	int		part_one;

	part_one = 0;
	fp = fopen("input_day4.txt", "r");
	if (fp == NULL)
	{
		printf("something went wrong opening the file.\n");
		return (1);
	}
	part_one = part_one_func(fp);
	printf("%d\n", part_one);
	fclose(fp);
	return (0);
}