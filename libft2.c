/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:09 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 14:26:15 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;
	size_t	len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!(temp))
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	char	*sub;
	int		i;

	if (s && start > ft_strlen(s))
		len = 0;
	ss = (char *)s;
	if (ss)
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (!(sub))
			return (0);
		i = 0;
		while (len--)
			sub[i++] = ss[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (n > a)
	{
		((unsigned char *)destination)[a] = c;
		++a;
	}
	return (destination);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*mem ;

	mem = malloc(num * size);
	if (!(mem))
		return (NULL);
	ft_memset(mem, 0, num * size);
	return (mem);
}

int	ft_atoi(const char *str)
{
	unsigned long int	i;
	int					num;
	int					minus;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return (num * minus);
}
