/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:53:35 by mito              #+#    #+#             */
/*   Updated: 2024/01/20 18:39:20 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> // I put this lib for printf, test purpose
#include <stdlib.h> // I put this lib for malloc, test purpose

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[len] = '\0';
	return (res);
}


static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (counter);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		array[i] = ft_substr(s, j, ft_word_len(&*(s + j), c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result = split(s, c, result, words);
	return (result);
}

// // FOR TESTING, ftt_lstiter
void	ftt_lstiter(t_stack_node *lst)
{
	//if (!lst || !f)
	//	return ;
	while (lst)
	{
		//f(lst->target_node);
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}
// これより上はテストのためだから必要ない

int main(int argc, char **argv)
{	
	// argc = 7;

	// argv = malloc((7 + 1) * sizeof(char *));
	// argv[0] = "push_swap";
	// argv[1] = "4";
	// argv[2] = "3";
	// argv[3] = "2";
	// argv[4] = "1";
	// argv[5] = "5";
	// argv[6] = "6";
	// argv[7] = NULL;

	t_stack_node	*a; 
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0])) //数字がなかったら
		return (1);
	// (validate(argv + 1) == false)
	// 	return (0);
	// initialize list a and list b
	// throw a and b to sorting function
	// --> all sorted a now is sorted and b now is empty
	
	// cleanup both a and b
	else if (argc == 2) //argvが２ってことは、数字が文字列で渡されたってこと
		argv = ft_split(argv[1], ' ');	//だからsplitする
    /* delet it it's a test if it's splitting correctly
    int i = 0; 
    while (argv[i] != '\0')
    {
        printf("%s\n", argv[i]);
        i++;
    }
    */
//    init_stacks(&a, &b, argv + 1);
//    sort_stacks(&a, &b);
	init_stack_a(&a, argv + 1); //a.outをスキップする
	if (!stack_sorted(a)) //もうすでに順番通りか確認
	{
		if (stack_len(a) == 2) //もし二つの数字しかないならただswapする
			{
				printf("-inside a condition: stack_len(a) == 2\n");
				sa(&a, false);
			}
		else if (stack_len(a) == 3)
		{
			printf("-inside a condition: stack_len(a) == 3\n");
			sort_three(&a);
		}
		else
		{
			b = (t_stack_node *)malloc(sizeof(t_stack_node)); // this is needed but initializing each member might not be needed 
			// b = new_stack_node();
			// new_stack_node() {
				//t_stack_node *new_node;
				//new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
				//if (new_node != NULL) {
					b->next = NULL;
					b->prev = NULL;
					b->target_node = NULL;
					b->above_median = 0;
					b->cheapest = 0;
					b->index = 0;
					b->nbr = 0;						
				//}
				//return (new_node);	
			printf("-start sorting algo\n");
			printf("-a: %p\n-b: %p\n", a, b); //この時点でbがもうNULLだ
			sort_stacks(&a, &b);
		}
	}
	else //delete it
		printf("-number were sorted already\n"); //delete it
	printf("-sorted number\n");
	ftt_lstiter(a); //delete this
	free_errors(&a);
	// free_errors(b); if we will allocate memory for B
	return (0);
}

