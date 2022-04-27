/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:02 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 14:24:30 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_read(int fd, char **str)
{
	char	*buff;
	int		read_size;
	char	*t;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
	{
		free (buff);
		return (0);
	}
	if (*str == NULL)
		*str = ft_strdup("");
	read_size = 1;
	while (!(find_new_line(*str)) && read_size != 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if ((read_size) < 0)
			return (0);
		buff[read_size] = '\0';
		t = ft_strjoin(*str, buff);
		free(*str);
		*str = t;
	}
	free(buff);
	return (*str);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*temp;
	char		*t;

	str[fd] = ft_read(fd, &str[fd]);
	if (!line || !(str[fd]))
		exit (0);
	temp = find_new_line(str[fd]);
	if (temp)
	{
		t = str[fd];
		*line = ft_substr(str[fd], 0, temp - str[fd]);
		str[fd] = ft_strdup(str[fd] + (temp - str[fd]) + 1);
		free(t);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}

void	trhee_d(t_fdf *data, float *x, float *y, float z)
{
	if (data->two_three_d == 1)
	{
		*x = (*x - *y) * cos(data->cos);
		*y = (*x + *y) * sin(data->sin) - z;
	}
}
