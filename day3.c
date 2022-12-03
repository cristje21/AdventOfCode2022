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
	return (-1);
}

// int	get_value(char *line)
// {
// 	int		start;
// 	int		end;
// 	char	*s;

// 	end = 0;
// 	start = 0;
// 	while (line[end] != '\n')
// 		end++;
// 	line[end] = '\0';
// 	while (start < end / 2)
// 	{
// 		s = strchr(&line[end / 2], line[start]);
// 		if (s == NULL)
// 		{
// 			start++;
// 			continue ;
// 		}
// 		return (check_case(line[start]));
// 		start++;
// 	}
// 	return(-1);
// }

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
	return (-1);
}

int	main(void)
{
	FILE	*fp;
	char	line[100][100];
	int		result;
	int		value;
	int		i;

	result = 0;
	i = 0;
	fp = fopen("input_day3.txt", "r");
	if (fp == NULL)
		return (-1);
	while (i < 100)
	{
		fgets(line[0], 100, fp);
		fgets(line[1], 100, fp);
		fgets(line[2], 100, fp);
		value = get_badge(line);
		if (value == -1)
			break ;
		result += value;
		i++;
	}
	if (value == -1)
		printf("something went wrong on attempt number %d!\nbut up until then, this is the ", i + 1);
	printf("result: %d\n", result);
	return (0);
}

// int	main(void)
// {
// 	FILE	*fp;
// 	char	line[100];
// 	int		result;
// 	int		value;

// 	result = 0;
// 	fp = fopen("input.txt", "r");
// 	if (fp == NULL)
// 		return (-1);
// 	while (fgets(line, 100, fp) != NULL)
// 	{
// 		value = get_value(line);
// 		if (value == -1)
// 		{
// 			printf("something went wrong!\n");
// 			break ;
// 		}
// 		result += value;
// 	}
// 	printf("result = %d\n", result);
// 	return (0);
// }
