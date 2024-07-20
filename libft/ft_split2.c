/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:00:51 by mkwizera          #+#    #+#             */
/*   Updated: 2024/07/20 16:33:03 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_word_count(const char *s, char c)
{
	int	count;
	int	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = 1;
			}
			s++;
		}
	}
	return (count);
}

static char	*ft_fill_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **new_word, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(new_word[i]);
		i++;
	}
	free(new_word);
}

static void	initailizer(int *j, size_t *i, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**split(const char *s, char c)
{
	size_t	i;
	int		s_word;
	int		j;
	char	**new_word;

	initailizer(&j, &i, &s_word);
	new_word = malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			new_word[j] = ft_fill_word(s, s_word, i);
			if (!new_word)
				ft_free(new_word, j);
			j++;
			s_word = -1;
		}
		i++;
	}
	new_word[j] = NULL;
	return (new_word);
}

// int main()
// {
//     char *name = " kwizera marius Tresor";
//     char c = ' ';
//     char **words;

//     words = split(name, c);
//     for (int i = 0; words[i] != NULL; i++)
//     {
//         printf("%s\n", words[i]);
//         free(words[i]);
//     }
//     free(words);

//     return (0);
// }
