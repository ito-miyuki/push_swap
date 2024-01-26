/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:54:50 by mito              #+#    #+#             */
/*   Updated: 2024/01/25 18:36:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	count_words(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	counter;

// 	i = 0;
// 	counter = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			counter++;
// 			while (s[i] != c && s[i] != '\0')
// 				i++;
// 		}
// 		else if (s[i] == c)
// 			i++;
// 	}
// 	return (counter);
// }

// static size_t	ft_word_len(char const *s, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			s++;
// 			i++;
// 		}
// 		else
// 			return (i);
// 	}
// 	return (i);
// }

// static void	free_array(size_t i, char **array)
// {
// 	while (i > 0)
// 	{
// 		i--;
// 		free(array[i]);
// 	}
// 	free(array);
// }

// static char	**split(char const *s, char c, char **array, size_t words_count)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < words_count)
// 	{
// 		while (*(s + j) && *(s + j) == c)
// 			j++;
// 		array[i] = ft_substr(s, j, ft_word_len(&*(s + j), c));
// 		if (!array[i])
// 		{
// 			free_array(i, array);
// 			return (NULL);
// 		}
// 		while (*(s + j) && *(s + j) != c)
// 			j++;
// 		i++;
// 	}
// 	*(array + i) = NULL;
// 	return (array);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**result;
// 	size_t	words;

// 	if (!s)
// 		return (NULL);
// 	words = count_words(s, c);
// 	result = (char **)malloc(sizeof(char *) * (words + 1));
// 	if (!result)
// 		return (NULL);
// 	result = split(s, c, result, words);
// 	return (result);
// }


static size_t    count_tokens(char const *s, char c)
{
    size_t        count;
    char const    *prev;

    if (c == '\0')
        return (1);
    count = 0;
    prev = NULL;
    while (*s != '\0')
    {
        if (*s != c)
        {
            if (prev == NULL || *prev == c)
                count++;
        }
        prev = s;
        s++;
    }
    return (count);
}

static char    *get_next_token(char const **s, char c, int *error)
{
    size_t        token_size;
    char const    *temp;
    char        *token;

    *error = 0;
    token_size = 0;
    while (**s == c && **s != '\0')
        *s = *s + 1;
    temp = *s;
    while (*temp != c && *temp != '\0')
    {
        temp++;
        token_size++;
    }
    if (token_size == 0)
        return (NULL);
    token = (char *)malloc((token_size + 1) * sizeof(char));
    if (token == NULL)
    {
        *error = 1;
        return (NULL);
    }
    ft_strlcpy(token, *s, token_size + 1);
    *s = temp;
    return (token);
}

static int    init(char **tokens, char const *s, char c, size_t tokens_length)
{
    size_t    i;
    int        error;

    i = 0;
    while (i < tokens_length)
    {
        tokens[i] = get_next_token(&s, c, &error);
        if (tokens[i] == NULL && error)
        {
            while (i != 0)
            {
                if (tokens[i] != NULL)
                    free(tokens[i]);
                i--;
            }
            if (tokens[i] != NULL)
                free(tokens[i]);
            return (0);
        }
        i++;
    }
    return (1);
}

char    **ft_split(char const *s, char c)
{
    size_t    count;
    char    **tokens;

    if (s == NULL)
        return (NULL);
    count = count_tokens(s, c);
    tokens = (char **)malloc((count + 1) * sizeof(char *));
    if (tokens == NULL)
        return (NULL);
    if (!init(tokens, s, c, count + 1))
    {
        free(tokens);
        tokens = NULL;
    }
    return (tokens);
}