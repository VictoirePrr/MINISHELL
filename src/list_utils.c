
#include "minishell.h"

void	rot_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}

t_stack	*node_init(char *token)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!(new_node))
		return (NULL);
	new_node->token = token;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	fill_the_list(char *token, t_stack **stack)
{
	t_stack	*new_node;

	new_node = node_init(token);
	if (!new_node)
		return (1);
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
		rot_lstadd_back(stack, new_node);
	return (0);
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	printf("\n");
	while (1)
	{
		printf("node[%d] : %s\n", i, temp->token);
		i++;
		temp = temp->next;
		if (temp == *stack)
			break ;
	}
	printf("\n");
}
