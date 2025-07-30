/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:31:39 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/07/29 17:04:56 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s1)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*newstr;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	newstr = malloc(len + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while ((size_t)i < len)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*newstr;

	len = ft_strlen(s);
	newstr = malloc(len + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
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
