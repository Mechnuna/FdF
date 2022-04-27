/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:17 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 15:00:05 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	len_wight(char *file)
{
	int		fd;
	char	*line;
	int		wight;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	wight = ft_wdcounter(line, ' ');
	close(fd);
	free(line);
	return (wight);
}

int	len_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while ((get_next_line(fd, &line)))
	{
		height++;
		free(line);
	}
	close(fd);
	free(line);
	return (height);
}

void	fill_matfix(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
	{
		ft_error("file does not exist", data);
		exit (-1);
	}
	data->wight = len_wight(file);
	data->height = len_height(file);
	data->z_matrix = malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
		data->z_matrix[i++] = malloc(sizeof(int *) * (data->wight + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matfix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
