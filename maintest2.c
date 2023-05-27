/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:16:10 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/27 22:45:09 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int count(char **str)
{
    int i = 0;
    while (str[i] != NULL)
       i++;
    return (i);
}

int check_range_FOV(int n)
{
    if (n >= 0 && n <= 180)
        return (1);
    return (0);
}

int ft_isdigit(int n)
{
    if(n >= '0' && n <= '9')
        return (1);
    return (0);
}

int check_range_vec(int n)
{
    if (n >= -1 && n <= 1)
        return (1);
    return (0);
}

int ft_isspace(char c)
{
	if(c==' ' || c=='\t' || c== '\n')
		return(1);
	return(0);
}

static	int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**splitword;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	splitword = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (splitword == NULL)
		return (NULL);
	while (s[i] != '\0' && k < (unsigned int)count_word(s, c))
	{
		j = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i + j] != c && s[i + j] != 0)
				j++;
		splitword[k++] = ft_substr(s, i, j);
		i = i + j;
	}
	splitword[k] = (NULL);
	return (splitword);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if ((start + len) > ft_strlen(s) && (start + 1) <= ft_strlen(s))
		len = ft_strlen(s) - start;
	else if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < len && s[start + j] != '\0')
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
int main()
{
	char **str = "12";
    unsigned int i = 0;
    while (str[i] != NULL)
    {
        unsigned int j = 0;
        int count = 0;
        while (str[i][j] != '\0')
        {
            if (!ft_isdigit(str[i][j]) && str[i][j] != '.')
            {
                write(2, "Error !!\n", 9);
                exit (1);
            }
            else if (str[i][j] == '.')
            {
                count++;
                if (count > 1)
                {
                    write(2, "Error !!\n", 9);
                    exit (1);
                }
            }
            j++;
        }
        i++;
    }
}