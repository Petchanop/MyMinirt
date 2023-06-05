/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 01:19:11 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/06 01:37:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

size_t	ft_strlen(char const *str);

static int	ft_charcmp(char c1)
{
	if (c1 < 33 && c1 != '\0' && c1 != '\n')
		return (1);
	return (0);
}

static size_t	ft_size(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) && *(s + i))
	{
		while (ft_charcmp(*(s + i)) && *(s + i))
			i++;
		if (!ft_charcmp(*(s + i)) && *(s + i))
			j++;
		while (!ft_charcmp(*(s + i)) && *(s + i))
			i++;
	}
	return (j);
}

static char	*ft_trim(char const *s, size_t start, size_t n)
{
	char	*spy;
	size_t	i;

	spy = malloc((n + 1) * sizeof(char));
	if (!spy)
		return (NULL);
	i = 0;
	while (i < n && *(s + start))
	{
			spy[i] = *(s + start);
		i++;
		start++;
	}
	spy[i] = '\0';
	return (spy);
}

char	**ft_split_space(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**spl;

	i = ft_size(s);
	spl = malloc((i + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + j) && j < ft_strlen(s))
	{
		k = 0;
		while (ft_charcmp(*(s + j)) && *(s + j))
			j++;
		while (!ft_charcmp(*(s + k + j)) && *(s + k + j))
			k++;
		if (k != 0)
			spl[i++] = ft_trim(s, j, k);
		j = j + k;
	}
	spl[i] = NULL;
	return (spl);
}
/*
int main(void){
	int i = 0;
	char **s = ft_split_space("cy 20.0,4,-5.0 	0.0,1.0,0.0 5.0 20 10,0,255");
	while (s[i])
		printf("%s\n", s[i++]);
}*/
