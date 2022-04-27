/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:12 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 14:24:27 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_error(char const *s, t_fdf *data)
{
	size_t	i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	ft_putchar('\n');
	free(data);
	exit(-1);
	return (i);
}
