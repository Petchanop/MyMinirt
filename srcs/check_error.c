/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:38:28 by lkaewsae          #+#    #+#             */
/*   Updated: 2023/06/03 23:41:05 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	write_error(char *err)
{
	write(2, err, ft_strlen(err));
	write (2, "Error !!\n", 9);
	exit (1);
}

int	check_fd(char *av, t_cam *cam, t_object *ob)
{
	int			fd;

	if (file_extension(av))
		write_error("file extension not .rt ");
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		perror(av);
		free(cam);
		free(ob);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
