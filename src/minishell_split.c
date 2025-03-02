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

static size_t	ft_reslen(const char *s1, char c)
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
		if (s1[i] != c && (s1[i + 1] == c || s1[i + 1] == '\0'))
		{
			if (quotes == ERROR)
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_countword(const char *s1, size_t i, char c)
{
	size_t	count;
	int		quotes;

	count = 0;
	quotes = ERROR;
	while (s1[i] == c)
		i++;
	while (s1[i])
	{
		quotes = handle_quotes(s1[i], quotes);
		if (s1[i] == c && quotes == ERROR)
			return (count);
		else
			count++;
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
	while (j < size && s1[i])
	{
			dup[j] = s1[i];
			j++;
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

char	**minishell_split(char const *s, char c)
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
	res = malloc((ft_reslen(s, c) + 1) * sizeof(char *));
	if (!(res))
		return (0);
	res[ft_reslen(s, c)] = NULL;
	while (s[i] && j < ft_reslen(s, c))
	{
		quotes = handle_quotes(s[i], quotes);
		if (s[i] != c || quotes == SUCCESS)
		{
			res[j] = ft_newtab(s, ft_countword(s, i, c), i);
			if (!(res[j]))
				return (ft_free(res));
			i += ft_countword(s, i, c);
			j++;
		}
		i++;
	}
	return (res);
}
