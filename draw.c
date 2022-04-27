/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:23:47 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 17:31:04 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *data, float y1, float x1)
{
	data->z = data->z_matrix[(int)(data->y)][(int)(data->x)];
	data->z2 = data->z_matrix[(int)(y1)][(int)(x1)];
	data->x *= data->zoom;
	data->x1 = x1 * data->zoom;
	data->y *= data->zoom;
	data->y1 = y1 * data->zoom;
	data->col = 0x00FFFF00;
	if (data->z || data->z2)
	{
		data->col = 0x00228B22;
		data->z2 /= data->z1;
		data->z /= data->z1;
	}
}

void	init2(t_fdf *data)
{
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}

void	two_dots(float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	init(data, y1, x1);
	trhee_d(data, &data->x, &data->y, data->z);
	trhee_d(data, &data->x1, &data->y1, data->z2);
	init2(data);
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	max = who_big(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->ptr, data->mlx_win, data->x, data->y, data->col);
		data->y += y_step;
		data->x += x_step;
		if (data->y > HEIGH || data->x > WIGHT)
			break ;
	}
}

void	print_menu(t_fdf param)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(param.ptr, param.mlx_win, 10, 20, 0x03fc35, menu);
	menu = "spase: 3d/2d mode; +, -: zoom";
	mlx_string_put(param.ptr, param.mlx_win, 10, 35, 0x03fc35, menu);
	menu = "w,s,a,d: turn";
	mlx_string_put(param.ptr, param.mlx_win, 10, 50, 0x03fc35, menu);
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;

	print_menu(*data);
	y = 0;
	while (data->height > y)
	{
		x = 0;
		while (data->wight > x)
		{
			data->x = x;
			data->y = y;
			if (data->wight - 1 > x)
				two_dots(x + 1, y, data);
			data->x = x;
			data->y = y;
			if (data->height - 1 > y)
				two_dots(x, y + 1, data);
			++x;
		}
		++y;
	}
}
