/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:38:28 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/05/31 21:16:05 by npiya-is         ###   ########.fr       */
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

int	check_fd(char *av, t_cam *cam, t_object *ob)
{
	t_object	*ob;
	t_cam		*cam;
	char		*line;
	int			fd;

	if (file_extension(av))
		write_error ();
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror(av);
		exit(EXIT_FAILURE);
	}
	ob = malloc (sizeof(t_object));
	if (!ob)
		return (NULL);
	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	return (fd);
}
