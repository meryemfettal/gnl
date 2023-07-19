/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfettal <mfettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:10:17 by mfettal           #+#    #+#             */
/*   Updated: 2023/07/19 03:04:04 by mfettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

char	*readed(int fd, char *rest)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			free(rest);
			rest = NULL;
			return (NULL);
		}
		buffer[r] = 0;
		rest = str_join(rest, buffer);
		if (ft_strchr(rest))
			break ;
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rest = readed(fd, rest);
	if (!rest)
		return (NULL);
	line = get_line1(rest);
	rest = get_rest(rest);
	return (line);
}

// int main(){
// 	int fd = open("./test", O_CREAT | O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
