#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char	*check_char(char *line, int i)
{
	int	j;
	int	i_temp;

	i_temp = i - 13;
	while (i >= 0)
	{
		j = i_temp;
		while (j < i)
		{
			if (line[i] == line[j])
				return (line);
			j++;
		}
		i--;
	}
	free(line);
	return (NULL);
}

int	main(void)
{
	FILE	*fp;
	char	*line;
	int		i;

	i = 13;
	line = malloc(4096);
	if (line == NULL)
		return (0);
	fp = fopen("input_day6.txt", "r");
	if (fp == NULL)
		return (0);
	fgets(line, 4096, fp);
	while (line[i] != '\n')
	{
		line = check_char(line, i);
		if (line == NULL)
		{
			printf("%d\n", i + 1);
			break ;
		}
		i++;
	}
	printf("end\n");
	return (0);
}