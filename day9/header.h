#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}					co;

#endif