/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:17:07 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 17:19:33 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos_del/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include <unistd.h>
# include <math.h>

# define BUFFER_SIZE 1
# define HEIGH 2500
# define WIGHT 1920

typedef struct s_fdf
{
	int		wight;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		col;
	int		shift_y;
	int		shift_x;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		two_three_d;
	float	cos;
	float	sin;

	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
	float	z2;
	float	max_y;
	float	max_x;

	void	*ptr;
	void	*mlx_win;
}			t_fdf;

void	draw(t_fdf *data);
int		who_big(float x, float y);
void	*ft_memcpy(void *destination, const void *source, size_t n);
char	*find_new_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *destination, int c, size_t n);
char	*ft_read(int fd, char **str);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t num, size_t size);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_wdcounter(char const *s, char c);
int		len_wight(char *file);
int		len_height(char *file);
void	fill_matfix(int	*z_line, char *line);
void	read_file(char *file, t_fdf *data);
int		deal_key(int key, t_fdf *data);
void	trhee_d(t_fdf *data, float *x, float *y, float z);
void	ft_putchar(char c);
int		ft_error(char const *s, t_fdf *data);

#endif