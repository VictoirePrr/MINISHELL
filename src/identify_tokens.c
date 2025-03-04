#include "minishell.h"

void	define_type(t_stack **temp, char *cmd, int i)
{
	if (cmd[i] == '|' && cmd[i + 1] != '|')
		temp->cmd[i]->token->PIPE;
	else if ((cmd[i] == '|' && cmd[i + 1] == '|'))
		temp.cmd[i]->token->OR;
}

int	identify_token_type(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		j;

	temp = *stack;
	while (1)
	{
		i = 0;
		while (temp->cmd[i])
		{
			j = 0;
			while (temp->cmd[i][j])
			{
				if (ft_is_operator(temp->cmd[i][j]) == SUCCESS)
					define_type(temp, temp->cmd[i], j);
				else
					temp->token = CMD;
				j++;
			}
			i++;
		}
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
}
