#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_stack
{
	char			*token;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					handle_operators(char *args, int i);
int					add_whitespace(char b, char a, int quotes);
int					handle_quotes(char argv, int quotes);

// parsing
int					parsing_argv(char *argv);
char				*separate_commands(char *args, int size);
char				*rm_whitespaces(char *argv, int size);

// parsing_utils
int					len_without_whitespaces(char *argv);
int					len_for_cleaned_args(char *args);
int					check_num_of_quotes(char *argv);

// parsing_char_utils
int					ft_iswhitespace(int c);
int					ft_is_operator(int c);
int					ft_is_quotes(char c);

// list_utils
int					fill_the_list(char *content, t_stack **stack);
t_stack				*node_init(char *content);
void				rot_lstadd_back(t_stack **stack, t_stack *new_node);
void				print_stack(t_stack **stack);

#endif