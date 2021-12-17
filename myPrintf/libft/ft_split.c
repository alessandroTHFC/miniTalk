/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:48:55 by apangraz          #+#    #+#             */
/*   Updated: 2021/10/12 11:48:55 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:20:42 by apangraz          #+#    #+#             */
/*   Updated: 2021/09/28 14:20:42 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:48:27 by apangraz          #+#    #+#             */
/*   Updated: 2021/09/28 10:32:35 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static size_t	w_count(char const *s, char c)
{
	int	wcount;
	int	i;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wcount++;
		i++;
	}
	return (wcount);
}

static void	*fn_free(char **arr, size_t wcount)
{
	size_t	i;

	i = 0;
	while (i < wcount)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**fill(char const *s, char c, size_t wcount, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	while (++i < wcount)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
			return (fn_free(arr, i));
		j = 0;
		while (j < len)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wcount;

	if (!s)
		return (NULL);
	wcount = w_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!arr)
		return (NULL);
	arr = fill(s, c, wcount, arr);
	return (arr);
}
