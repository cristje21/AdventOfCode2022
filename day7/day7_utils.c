#include "header.h"

char *get_one_line(FILE *fp)
{
	char	*one_line;
	char	temp[30];
	int		i;

	i = 0;
	fgets(temp, 30, fp);
	if (temp[0] == '.')
		return (NULL);
	while (temp[i] != '\n')
		i++;
	one_line = malloc(i + 1);
	if (one_line == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\n')
	{
		one_line[i] = temp[i];
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

void	printallnames(t_list **head)
{
	t_list	*temp;
	int i;

	if (head)
		temp = *head;
	i = 1;
	while (temp->next)
	{
		printf("name %d: %s\n", i, temp->name);
		temp = temp->next;
		i++;
	}
}

t_list	*add_to_last(t_list **head, int to_add)
{
	t_list	*temp;

	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->size += to_add;
	}
	return (temp);
}


void	lst_add_back(t_list **head, t_list *list)
{
	t_list *ptr;

	if (head && *head)
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = list;
	}
	else if (head)
	{
		*head = list;
	}
}

int	add_count(t_list *list)
{
	int	i;
	int	local_count;

	i = 0;
	while (list->content[i] != NULL)
	{
		if (list->content[i][0] >= '0' && list->content[i][0] <= '9')
			local_count += atoi(list->content[i]);
		i++;
	}
	return(local_count);
}

void	lst_del_last(t_list **head)
{
	t_list	*temp;
	t_list	*del;

	temp = *head;
	if (*head == NULL)
		return ;
	else if (temp->next == NULL)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	del = temp->next;
	free(del);
	temp->next = NULL;
}

void	get_content(FILE *fp, t_list *list)
{
	int		i;
	char	temp[20][100];
	char	*t;
	char	**content;

	i = 0;
	t = get_one_line(fp);
	if (t == NULL)
		return ;
	while (t[0] != '$' && t[0] != '.')
	{
		strcpy(temp[i], t);
		i++;
		free(t);
		t = get_one_line(fp);
	}
	content = malloc((i * sizeof(char *) + 1));
	if (!content)
		return ;
	content[i] = NULL;
	i--;
	while (i >= 0)
	{
		content[i] = malloc(strlen(temp[i]) + 1);
		strcpy(content[i], temp[i]);
		i--;
	}
	list->first_command = t;
	list->content = content;
}