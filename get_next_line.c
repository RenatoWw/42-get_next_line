/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:34:56 by ranhaia-          #+#    #+#             */
/*   Updated: 2025/07/29 19:58:02 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tempbuffer;
	char		*line;
	char		*sobra;
	int			iread;

	if (buffer == NULL)
		buffer = ft_strdup("");
	tempbuffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	iread = 1;
	while (ft_strchr(buffer, '\n') == NULL || iread == 0)
	{
		iread = read(fd, tempbuffer, BUFFER_SIZE);
		tempbuffer[iread] = '\0';
		if (iread == 0 || iread == -1)
			break ;
		buffer = ft_strjoin(buffer, tempbuffer);
	}
	free(tempbuffer);
	while (buffer[iread] != '\n' && buffer[iread])
		iread++;
	line = ft_substr(buffer, 0, iread + 1);
	sobra = ft_substr(buffer, iread + 1, ft_strlen(buffer));
	buffer = sobra;
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("arquivo.txt", O_RDONLY);
	line = get_next_line(fd);
	// printf("%s", line);
	free(line);
	line = get_next_line(fd);
	free(line);
	// printf("%s", line);
	line = get_next_line(fd);
	free(line);
	// printf("%s", line);
	line = get_next_line(fd);
	free(line);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// line = get_next_line(fd);
	return (0);
}
