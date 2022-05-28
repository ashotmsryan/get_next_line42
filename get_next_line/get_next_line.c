/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:19:52 by amsryan           #+#    #+#             */
/*   Updated: 2022/04/05 19:11:12 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*mywhile(int fd, long readsize, char *sline)
{
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		buff[readsize] = '\0';
		if (readsize == -1)
			return (0);
		if (!sline)
			sline = ft_strdup(buff);
		else
			sline = ft_strjoin(sline, buff);
		if (ft_strchr(buff, '\n') || readsize == 0)
			break ;
	}
	return (sline);
}

char	*get_next_line(int fd)
{
	long		index;
	long		readsize;
	static char	*sline;
	char		*line;
	char		*tmp;

	readsize = 1;
	if (readsize == 0)
		return (NULL);
	sline = mywhile(fd, readsize, sline);
	index = ft_strlen(sline) - ft_strlen(ft_strchr(sline, '\n')) + 1;
	line = ft_substr(sline, 0, index);
	tmp = sline;
	sline = ft_substr(sline, index, ft_strlen(sline));
	free(tmp);
	return (line);
}
