/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:14:44 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/04/14 01:37:34 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*head;
	size_t	count;

	count = ft_strlen(s1);
	if (!count)
		return (NULL);
	p = malloc(sizeof(char) * (count + 1));
	if (!p)
		return (NULL);
	head = p;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (head);
}

size_t	ft_strchr_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (0);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*p;
	char	*head;

	p = malloc(ft_strlen(s1) + n + 1);
	if (!p)
		return (NULL);
	head = p;
	if (s1)
		while (*s1)
			*p++ = *s1++;
	if (s2)
		while (*s2 && n--)
			*p++ = *s2++;
	*p = '\0';
	return (head);
}
