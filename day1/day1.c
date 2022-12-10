#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	rank_this(int count, int *top_three)
{
	if (count <= top_three[2])
		return ;
	else if (count <= top_three[1])
		top_three[2] = count;
	else if (count <= top_three[0])
	{
		top_three[2] = top_three[1];
		top_three[1] = count;
	}
	else
	{
		top_three[2] = top_three[1];
		top_three[1] = top_three[0];
		top_three[0] = count;
	}
}

int	main(void)
{
	FILE	*fp;
	char	line[10];
	int		count;
	int		*top_three;

	top_three = calloc(3, sizeof(int));
	if (top_three == NULL)
		return (1);
	fp = fopen("input.txt", "r");
	if (fp == NULL)
		return (1);
	while (fgets(line, 10, fp) != NULL)
	{
		count = 0;
		while (line[0] != '\n')
		{
			count += atoi(line);
			if (fgets(line, 10, fp) == NULL)
				break ;
		}
		rank_this(count, top_three);
	}
	printf("top #1		%d\ntop #3		%d\n", top_three[0], top_three[0] + top_three[1] + top_three[2]);
	free(top_three);
	return (0);
}