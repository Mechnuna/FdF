/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:05 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 17:11:31 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	who_big(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return (x);
	return (y);
}

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	a;

	a = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (a < n)
	{
		((unsigned char *) destination)[a] = ((unsigned char *) source)[a];
		++a;
	}
	return (destination);
}

char	*find_new_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*dp;
	int		i;

	s = (char *)s1;
	dp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dp == 0)
		return (0);
	if (!s)
	{
		*dp = '\0';
		return (dp);
	}
	i = 0;
	while (*s)
	{
		dp[i] = *s;
		s++;
		i++;
	}
	dp[i] = '\0';
	return (dp);
}
