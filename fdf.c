/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:23:53 by sstyx             #+#    #+#             */
/*   Updated: 2021/10/12 16:56:53 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_a_key(int key)
{
	return (key == 123 || key == 124 || key == 125 || key == 126
		|| key == 24 || key == 27 || key == 2 || key == 0
		|| key == 1 || key == 13 || key == 49 || key == 53
		|| key == 47 || key == 43);
}

void	do_key2(int key, t_fdf *data)
{
	if (key == 49)
	{
		if (data->two_three_d == 1)
			data->two_three_d = 0;
		else
			data->two_three_d = 1;
	}
	if (key == 47)
	{
		data->z1 -= 0.1;
		if (data->z1 < 0.1)
			data->z1 = 0.1;
	}
	if (key == 43 )
		data->z1 += 0.1;
	if (key == 27)
	{
		data->zoom -= 1;
		data->max_x = 0;
		data->max_y = 0;
	}
}

void	do_key(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 124)
		data->shift_x += 20;
	if (key == 0)
		data->cos -= 0.1;
	if (key == 2)
		data->cos += 0.1;
	if (key == 1)
		data->sin += 0.1;
	if (key == 13)
		data->sin -= 0.1;
	if (key == 24)
		data->zoom += 1;
	do_key2(key, data);
}

int	deal_key(int key, t_fdf *data)
{
	if (is_a_key(key))
	{
		mlx_clear_window(data->ptr, data->mlx_win);
		do_key(key, data);
		draw(data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->ptr, data->mlx_win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = malloc(sizeof(t_fdf));
	data->zoom = 10;
	data->shift_x = 500;
	data->shift_y = 400;
	data->cos = 0.523599;
	data->sin = 0.523599;
	data->two_three_d = 1;
	data->z1 = 1;
	if (argc != 2)
		ft_error("usage: ./fdf map.fdf", data);
	read_file(argv[1], data);
	data->ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->ptr, HEIGH, WIGHT, "FDF");
	draw (data);
	mlx_key_hook(data->mlx_win, deal_key, data);
	mlx_loop(data->ptr);
}
