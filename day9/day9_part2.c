#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void	lst_add_back(coordinates **head, coordinates *list)
{
	coordinates *ptr;

	if (head && *head)
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = list;
	}
	else if (head)
		*head = list;
}

coordinates	*new_list(int x_t, int y_t)
{
	coordinates	*new;

	new = malloc(sizeof(coordinates));
	if (new == NULL)
		return (NULL);
	new->x = x_t;
	new->y = y_t;
	new->next = NULL;
	return (new);
}

int	*move(int direction, int *xy)
{
	if (direction == 'U')
		xy[1]++;
	else if (direction == 'D')
		xy[1]--;
	else if (direction == 'R')
		xy[0]++;
	else if (direction == 'L')
		xy[0]--;
	return (xy);
}

int	*move_straight(int *xy_h, int *xy_t, int direction)
{
	if ((xy_h[direction] - 1 == xy_t[direction]) || xy_h[direction] + 1 == xy_t[direction])
		return (xy_t);
	else if (xy_h[direction] > xy_t[direction])
		xy_t[direction]++;
	else if (xy_h[direction] < xy_t[direction])
		xy_t[direction]--;
	return (xy_t);
}

int	*move_diagonally(int *xy_h, int *xy_t, int direction, int var)
{
	if (xy_h[direction] == xy_t[direction] + 1 || xy_h[direction] == xy_t[direction] - 1)
		return (xy_t);
	else if (xy_h[direction] == xy_t[direction] + 2)
	{
		xy_t[direction]++;
		if (xy_t[var] < xy_h[var])
			xy_t[var]++;
		else if (xy_t[var] > xy_h[var])
			xy_t[var]--;
	}
	else if (xy_h[direction] == xy_t[direction] - 2)
	{
		xy_t[direction]--;
		if (xy_t[var] < xy_h[var])
			xy_t[var]++;
		else if (xy_t[var] > xy_h[var])
			xy_t[var]--;
	}
	return (xy_t);
}

int *move_diagonally_not_attached(int *xy_h, int *xy_t)
{
	if (xy_h[0] > xy_t[0])
		xy_t[0]++;
	else if (xy_h[0] < xy_t[0])
		xy_t[0]--;
	if (xy_h[1] > xy_t[1])
		xy_t[1]++;
	else if (xy_h[1] < xy_t[1])
		xy_t[1]--;
	return (xy_t);
}

int	*move_tail(int *xy_h, int *xy_t)
{
	if (xy_h[0] == xy_t[0])
		return (move_straight(xy_h, xy_t, 1));
	else if (xy_h[1] == xy_t[1])
		return (move_straight(xy_h, xy_t, 0));
	else if (xy_h[0] == xy_t[0] + 1 || xy_h[0] == xy_t[0] - 1) //
		return (move_diagonally(xy_h, xy_t, 1, 0));
	else if (xy_h[1] == xy_t[1] + 1  || xy_h[1] == xy_t[1] - 1) //changed last 2
		return (move_diagonally(xy_h, xy_t, 0, 1));
	else if (xy_h[0] == xy_t[0] + 2 || xy_h[0] == xy_t[0] - 2)
		return (move_diagonally_not_attached(xy_h, xy_t));
	return (xy_t);
}

int	compare_list(int x, int y, coordinates **head)
{
	coordinates	*temp;

	temp = *head;
	if (temp->next == NULL)
		return (temp->x == x && temp->y == y);
	while (temp->next != NULL)
	{
		if (temp->x == x && temp->y == y)
			return (1);
		temp = temp->next;
	}
	if (temp->x == x && temp->y == y)
		return (1);
	return (0);
}

void print_list(coordinates **head)
{
	coordinates *temp;
	int	count;

	count = 0;
	temp = *head;
	while (temp->next != NULL)
	{
		count++;
		printf("%d, %d\n", temp->x, temp->y);
		temp = temp->next;
	}
	printf("%d, %d\n", temp->x, temp->y);
	printf("count: %d\n", count + 1);
}

int	main(void)
{
	coordinates		*initial;
	coordinates		*list;
	char	line[10];
	FILE	*fp;
	int		**xy;
	int		amount;
	int		i;

	xy = malloc(10 * sizeof(int *));
	if (xy == NULL)
		return (0);
	amount = 0;
	while (amount < 10)
	{
		xy[amount] = calloc(2, sizeof(int));
		if (xy[amount] == NULL)
			return (0);
		amount++;
	}
	fp = fopen("input_day9.txt", "r");
	if (fp == NULL)
		return (0);
	initial = new_list(0, 0);
	if (initial == NULL)
		return (0);
	while (fgets(line, 10, fp) != NULL)
	{
		amount = atoi(&line[2]);
		while (amount > 0)
		{
			i = 0;
			xy[i++] = move(line[0], xy[0]);
			while (i < 10)
			{
				xy[i] = move_tail(xy[i - 1], xy[i]);
				i++;
			}
			if (!compare_list(xy[9][0], xy[9][1], &initial))
			{
				list = new_list(xy[9][0], xy[9][1]);
				lst_add_back(&initial, list);
			}
			amount--;
		}
	}
	print_list(&initial);
}