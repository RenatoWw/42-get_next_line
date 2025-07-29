/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:31:39 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/07/28 21:33:44 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	s1len = 0;
	s2len = 0;
	while (s1[s1len])
		s1len++;
	while (s2[s2len])
		s2len++;
	newstr = malloc((s1len + s2len) + 1 * sizeof(char));
	i = 0;
	while (i < s1len)
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < s2len)
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		else
			s++;
	}
	while (*s == '\0' && (unsigned char) c == '\0')
		return ((char *)s);
	return (NULL);
}
