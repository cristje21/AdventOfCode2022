#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	check_case(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 96);
	else if (c >= 'A' && c <= 'Z')
		return (c - 38);
	return (0);
}

int	get_value(char *line)
{
	int		start;
	int		end;
	char	*s;

	end = 0;
	start = 0;
	while (line[end] != '\n')
		end++;
	line[end] = '\0';
	while (start < end / 2)
	{
		s = strchr(&line[end / 2], line[start]);
		if (s == NULL)
		{
			start++;
			continue ;
		}
		return (check_case(line[start]));
		start++;
	}
	return(0);
}

int	get_badge(char line[100][100])
{
	int		i;
	char	*s;

	i = 0;
	while (line[0][i] != '\n')
	{
		s = strchr(line[1], line[0][i]);
		if (s == NULL)
		{
			i++;
			continue ;
		}
		s = strchr(line[2], line[0][i]);
		if (s == NULL)
		{
			i++;
			continue ;
		}
		return (check_case(line[0][i]));
	}
	return (0);
}

int	main(void)
{
	FILE	*fp;
	char	line[100][100];
	int		result[2] = {0, 0};
	int		value;
	int		i;

	i = 0;
	fp = fopen("input_day3.txt", "r");
	if (fp == NULL)
		return (-1);
	while (i < 100)
	{
		fgets(line[0], 100, fp);
		result[0] += get_value(line[0]);
		fgets(line[1], 100, fp);
		result[0] += get_value(line[1]);
		fgets(line[2], 100, fp);
		result[0] += get_value(line[2]);
		value = get_badge(line);
		result[1] += value;
		i++;
	}
	fclose(fp);
	printf("part 1: %d\npart 2: %d\n", result[0], result[1]);
	return (0);
}
