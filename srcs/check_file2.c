/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:03:13 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 23:08:20 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	count_dup_env(char *str)
{
	static unsigned int	acount = 0;
	static unsigned int	ccount = 0;
	static unsigned int	lcount = 0;

	if (!ft_strncmp(str, "A", 2))
		acount++;
	else if (!ft_strncmp(str, "C", 2))
		ccount++;
	else if (!ft_strncmp(str, "L", 2))
		lcount++;
	else if (acount == 1 && !ft_strncmp(str, "a", 2))
		return (1);
	else if (ccount == 1 && !ft_strncmp(str, "c", 2))
		return (1);
	else if (lcount == 1 && !ft_strncmp(str, "l", 2))
		return (1);
	if (lcount > 1 || acount > 1 || ccount > 1)
		return (1);
	else if (!ft_strncmp(str, "#", 1)
		|| !ft_strncmp(str, "\n", 1))
		return (0);
	return (0);
}

int	count_dup_object(char *str)
{
	static unsigned int	plc = 0;
	static unsigned int	spc = 0;
	static unsigned int	cyc = 0;
	static unsigned int	coc = 0;

	if (!ft_strncmp(str, "PL", 3))
		plc++;
	else if (!ft_strncmp(str, "SP", 3))
		spc++;
	else if (!ft_strncmp(str, "CY", 3))
		cyc++;
	else if (!ft_strncmp(str, "CO", 3))
		coc++;
	else if (plc == 1 && !ft_strncmp(str, "pl", 2))
		return (1);
	else if (spc == 1 && !ft_strncmp(str, "sp", 2))
		return (1);
	else if (cyc == 1 && !ft_strncmp(str, "cy", 2))
		return (1);
	else if (coc == 1 && !ft_strncmp(str, "co", 2))
		return (1);
	if (plc > 1 || spc > 1 || cyc > 1 || coc > 1)
		return (1);
	return (0);
}

int	count_dup(char *str)
{
	if (count_dup_env(str) || (count_dup_envrev(str) == 1))
		return (1);
	else if (count_dup_object(str) || count_dup_objectrev(str))
		return (1);
	else if (count_other(str) || (count_dup_envrev(str) == 2))
		return (2);
	return (0);
}

void	exit_dup(char **split_space)
{
	int	result;

	result = count_dup(split_space[0]);
	if (result == 1)
	{
		free2p(split_space);
		write_error("Duplicate object ");
	}
	else if (result == 2)
	{
		free2p(split_space);
		write_error("Invalid Object ");
	}
}
