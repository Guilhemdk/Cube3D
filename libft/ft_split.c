/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:14:06 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 16:14:06 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	ft_count_quotes(char *s, int *i)
{
	int	count_quotes;

	count_quotes = 0;
	while (s[*i] && (s[*i] == '\'' || s[*i] == '"'))
	{
		count_quotes = !count_quotes;
		(*i)++;
	}
	while (s[*i] && (s[*i] != '\'' && s[*i] != '"'))
		(*i)++;
	while (s[*i] && (s[*i] == '\'' || s[*i] == '"'))
	{
		count_quotes = !count_quotes;
		(*i)++;
	}
	if (count_quotes != 0)
		return (-1);
	return (1);
}

static size_t	ft_count_words(char *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			count++;
		if (s[i] == '"' || s[i] == '\'')
		{
			if (ft_count_quotes(s, &i) == -1)
				return (-1);
			count++;
		}
		else
		{
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static void	ft_count_len_quotes(char **s, size_t *len)
{
	size_t	i;

	i = 0;
	while ((*s)[i] && ((*s)[i] == '\'' || (*s)[i] == '"'))
	{
		(*len)++;
		i++;
	}
	while ((*s)[i] && ((*s)[i] != '\'' && (*s)[i] != '"'))
	{
		(*len)++;
		i++;
	}
	while ((*s)[i] && ((*s)[i] == '\'' || (*s)[i] == '"'))
	{
		(*len)++;
		i++;
	}
	return ;
}

static void	ft_count_len_word(char **s, char c, size_t *len)
{
	size_t	i;

	*s += *len;
	*len = 0;
	i = 0;
	while (**s && **s == c)
		(*s)++;
	if ((*s)[i] && ((*s)[i] == '"' || (*s)[i] == '\''))
	{
		ft_count_len_quotes(s, len);
		return ;
	}
	else
	{
		while ((*s)[i])
		{
			if ((*s)[i] == c)
				return ;
			(*len)++;
			i++;
		}
	}
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**ptr;
	size_t	word_len;
	int		count_word;

	count_word = ft_count_words(s, c);
	if (count_word == -1)
		return (NULL);
	ptr = (char **) malloc(sizeof(char *) * (count_word + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	word_len = 0;
	while (i < (size_t)count_word)
	{
		ft_count_len_word(&s, c, &word_len);
		ptr[i] = (char *) malloc(sizeof(char) * (word_len + 1));
		if (!ptr[i])
			return (NULL);
		ft_strlcpy(ptr[i], s, word_len + 1);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
