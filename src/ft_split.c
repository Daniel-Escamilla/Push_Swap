/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:00:12 by descamil          #+#    #+#             */
/*   Updated: 2024/12/04 11:06:21 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen_mod(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_strlcpy_mod(char *s, char c, int *new_start, int size)
{
	char	*string;
	int		start;
	int		j;

	j = 0;
	start = *new_start;
	string = (char *)malloc(size + 1);
	if (string == NULL)
		return (NULL);
	while (s[start] == c && s[start] != '\0')
		start++;
	while (s[start] != '\0' && j < size)
		string[j++] = s[start++];
	string[j] = '\0';
	*new_start = start;
	return (string);
}

void	*free_memory(int a, char **arr)
{
	int	f;

	f = 0;
	while (f < a)
		free(arr[f++]);
	free(arr);
	return (NULL);
}

int	ft_words(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	*cpy_mod;
	char	**arr;
	int		len;
	int		i;
	int		a;

	i = 0;
	a = 0;
	len = 0;
	arr = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (a < ft_words(s, c))
	{
		len = ft_strlen_mod(s, i, c);
		cpy_mod = ft_strlcpy_mod((char *)s, c, &i, len);
		if (cpy_mod == NULL)
			return (free_memory(a, arr));
		arr[a] = cpy_mod;
		a++;
	}
	arr[a] = NULL;
	return (arr);
}
