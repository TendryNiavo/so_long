/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tenandri <tenandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:52 by tenandri          #+#    #+#             */
/*   Updated: 2024/10/22 15:26:21 by tenandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_next_line(char *buffer)
{
	char			*new_line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free (buffer), NULL);
	new_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (new_line == NULL)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	free(buffer);
	return (new_line);
}

static char	*check_newline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2 + 1, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*ft_join_buffer(char *buffer, char *line)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, line);
	free(buffer);
	return (new_buffer);
}

static char	*take_buffer(char *buffer, int fd)
{
	char	*tmp;
	int		byte_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte_read] = 0;
		buffer = ft_join_buffer(buffer, tmp);
		if (ft_strchr(buffer, "\n"))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = take_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = check_newline(buffer);
	buffer = extract_next_line(buffer);
	if (buffer == NULL)
		buffer = NULL;
	else if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
