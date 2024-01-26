/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:43 by mito              #+#    #+#             */
/*   Updated: 2024/01/25 18:44:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static size_t	count_words(char const *s, char c) //コレジャナイと動かない
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
// 	size_t	i; //各文字のインデックス
// 	size_t	j; //各ワードのインデックス

// 	i = 0;
// 	j = 0;

// 	array[0] = malloc(sizeof(char));
// 	if (!array[0])
// 	{
// 		free_array(0, array);
// 		return (NULL); // free array必要？
// 	}
// 	array[0][0] = '\0';
// 	i++;
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
// 	result = (char **)malloc(sizeof(char *) * (words + 2)); //最初のヌルと最後のヌル
// 	if (!result)
// 		return (NULL);
// 	result = split(s, c, result, words + 1); //ここもプラスにした
// 	return (result);
// }

// int main()
// {
// 	char *str = "Hello split me please";
// 	int i = 0;
// 	int j = 0;
// 	char c = ' ';
// 	char **res = ft_split(str, c);
// 	while (i < 7)
// 	{
// 		printf("%p\n", res[i][j]);
// 		i++;
// 	}
// 	return (0);
// }