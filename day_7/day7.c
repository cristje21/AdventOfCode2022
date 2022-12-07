#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

t_list	*create_new(FILE *fp, char *first_command)
{
	t_list	*list;

	list = NULL;
	if (first_command[5] != '.')
	{
		list = malloc(sizeof(t_list));
		if (list == NULL)
			return (NULL);
		list->size = 0;
		list->next = NULL;
		list->name = strdup(&first_command[5]);
	}
	else
		return (NULL);
	first_command = get_one_line(fp);
	if (first_command[2] == 'l')
	{		
		get_content(fp, list);
		list->size = add_count(list);
		return (list);
	}
	return (list);
}

void	get_count_recursively(t_list *list, t_list **head, FILE *fp)
{

	t_list	*new_list;
	int		temp;
	

	if (list->first_command[1] == '$')
		return ;
	else
	{
		new_list = create_new(fp, list->first_command);
		if (new_list != NULL)
		{
			lst_add_back(head, new_list);
			get_count_recursively(new_list, head, fp);
		}
		else
		{
			if (list->size <= 100000)
				printf("%d			%s\n", list->size,list->name);
			temp = list->size;
			lst_del_last(head);
			list = add_to_last(head, temp);
			list->first_command = get_one_line(fp);
			get_count_recursively(list, head, fp);
		}
	}
}

int	main(void)
{
	t_list	*list;
	FILE	*fp;
	char	*temp;

	fp = fopen("input_day7.txt", "r");
	if (fp == NULL)
		return (1);
	temp = get_one_line(fp);
	list = create_new(fp, temp);
	get_count_recursively(list, &list, fp);
	return (0);
}
