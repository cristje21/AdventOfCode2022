#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_list
{
	int				size;
	char			*name;
	char			**content;
	char			*first_command;
	struct s_list	*next;
}					t_list;

char	*get_one_line(FILE *fp);
void	get_content(FILE *fp, t_list *list);
void	lst_del_last(t_list **head);
int		add_count(t_list *list);
void	lst_add_back(t_list **head, t_list *list);
void	printallnames(t_list **head);
t_list	*add_to_last(t_list **head, int to_add);

#endif