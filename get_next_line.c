/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:56 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/07/28 21:37:25 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tempbuffer;
	int			iread;
	char		*str;
	// int		i;
	// int		start;
	// int		end;

	str = NULL;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	tempbuffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	// iread = 1;
	// buffer[iread] = '\0';
	iread = read(fd, tempbuffer, BUFFER_SIZE);
	tempbuffer = ft_strjoin(tempbuffer, buffer);
	printf("%s", tempbuffer);
	return (buffer);
}

int	main(void)
{
	int		fd;

	fd = open("arquivo.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}
