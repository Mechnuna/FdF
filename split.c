/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:24:20 by sstyx             #+#    #+#             */
/*   Updated: 2021/09/30 14:24:26 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_mass(char const *s, char c)
{
	int		spase;
	int		i;
	int		len;

	spase = 0;
	len = 0;
	i = 0;
	while (*s)
	{
		if (s[i] == c)
		{
			if (len != 0)
				++spase;
			len = 0;
		}
		else
			++len;
		s++;
	}
	if (len != 0)
	{
		return (spase + 1);
	}
	return (spase);
}

static char	*check_str(int len, char *str, int index, char const *s)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (!(str))
		return (NULL);
	ft_memcpy(str, s + index - len, len);
	return (str);
}

//каждое слово засовываем в массив
static void	split_mass(int count_array, char const *s, char c, char **mass)
{
	int		len;
	int		index;
	char	*str;
	int		i;

	index = 0;
	len = 0;
	i = 0;
	while (i < count_array)
	{
		if (s[index] == c || s[index] == '\0')
		{
			if (len != 0)
			{
				str = check_str(len, str, index, s);
				if (!(str))
					return ;
				mass[i++] = str;
			}
			len = 0;
		}
		else
			++len;
		++index;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**mass;
	size_t	count;

	if (!(s))
		return (NULL);
	count = count_mass(s, c);
	mass = malloc((count + 1) * sizeof(char *));
	if (!(mass))
		return (NULL);
	split_mass(count, s, c, mass);
	mass[count] = NULL;
	return (mass);
}

int	ft_wdcounter(char const *s, char c)
{
	size_t	count;

	if (!(s))
		return (0);
	count = count_mass(s, c);
	return (count);
}
