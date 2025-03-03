#include "minishell.h"

static char	**ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	return (0);
}

static size_t	ft_reslen(const char *s1)
{
	size_t	i;
	size_t	count;
	int		quotes;

	i = 0;
	count = 0;
	quotes = ERROR;
	while (s1[i])
	{
		quotes = handle_quotes(s1[i], quotes);
		if ((ft_is_operator(s1[i]) == ERROR && ft_is_operator(s1[i
					+ 1]) == SUCCESS) || s1[i + 1] == '\0'
			|| ft_is_operator(s1[i]) == SUCCESS)
		{
			if (quotes == ERROR)
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_countword(const char *s1, size_t i)
{
	size_t	count;
	int		quotes;

	count = 0;
	quotes = ERROR;
	if (ft_is_operator(s1[i]) == SUCCESS)
	{
		while (ft_is_operator(s1[i]) == SUCCESS)
		{
			i++;
			count++;
		}
		return (count);
	}
	while (s1[i])
	{
		quotes = handle_quotes(s1[i], quotes);
		if (ft_is_operator(s1[i + 1]) == ERROR || quotes == SUCCESS)
			count++;
		else
			return (count);
		i++;
	}
	return (count);
}

static char	*ft_newtab(const char *s1, size_t size, size_t i)
{
	char	*dup;
	size_t	j;

	dup = malloc((size + 1) * sizeof(char));
	j = 0;
	if (!(dup))
		return (0);
	while (j <= size && s1[i])
	{
		dup[j] = s1[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

char	**minishell_split(char const *s)
{
	char	**res;
	int		quotes;
	size_t	i;
	size_t	j;

	quotes = ERROR;
	i = 0;
	j = 0;
	if (!(s))
		return (0);
	res = malloc((ft_reslen(s) + 1) * sizeof(char *));
	if (!(res))
		return (0);
	res[ft_reslen(s)] = NULL;
	printf("num of lines : %lu\n", ft_reslen(s) + 1);
	while (s[i]) //&& j < ft_reslen(s)
	{
		quotes = handle_quotes(s[i], quotes);
		// if (ft_is_operator(s[i]) == ERROR || quotes == SUCCESS)
		// {
		res[j] = ft_newtab(s, ft_countword(s, i), i);
		printf("words : %lu\n", ft_countword(s, i));
		if (!(res[j]))
			return (ft_free(res));
		i += ft_countword(s, i);
		j++;
		// }
		i++;
	}
	return (res);
}
