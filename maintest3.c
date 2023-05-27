/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:40:18 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/27 19:18:23 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int check_dia(char *str)
{
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