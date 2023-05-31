/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:38:28 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 19:54:44 by lkaewsae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
//#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

void	write_error(void)
{
	write (2, "Error !!\n", 9);
	exit (1);
}

void	check_fd(char *av)
{
	char	*line;
	int		fd;	
	
	if (file_extension(av))
		write_error ();
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror(av);
		exit(EXIT_FAILURE);
	}
	t_object	*ob;
	ob = NULL;
	ob = malloc (sizeof(t_object));
	if (!ob)
		return (NULL);
    t_cam	*cam;
	cam = malloc(sizeof(t_cam));
	if (!cam)
			return (NULL);  
}