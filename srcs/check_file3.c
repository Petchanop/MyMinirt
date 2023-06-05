/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:01:11 by npiya-is          #+#    #+#             */
/*   Updated: 2023/06/05 22:49:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	count_dup_envrev(char *str)
{
	static unsigned int	acount = 0;
	static unsigned int	ccount = 0;
	static unsigned int	lcount = 0;

	if (!ft_strncmp(str, "a", 2))
		return (2);
	else if (!ft_strncmp(str, "c", 2))
		return (2);
	else if (!ft_strncmp(str, "l", 2))
		return (2);
	else if (acount >= 1 && !ft_strncmp(str, "A", 2))
		return (1);
	else if (ccount >= 1 && !ft_strncmp(str, "C", 2))
		return (1);
	else if (lcount >= 1 && !ft_strncmp(str, "L", 2))
		return (1);
	else if (ft_strncmp(str, "#", 1)
		&& ft_strncmp(str, "\n", 1))
		return (0);
	return (0);
}

int	count_dup_objectrev(char *str)
{
	static unsigned int	plc = 0;
	static unsigned int	spc = 0;
	static unsigned int	cyc = 0;
	static unsigned int	coc = 0;

	if (!ft_strncmp(str, "pl", 3))
		plc++;
	else if (!ft_strncmp(str, "sp", 3))
		spc++;
	else if (!ft_strncmp(str, "cy", 3))
		cyc++;
	else if (!ft_strncmp(str, "co", 3))
		coc++;
	else if (plc >= 1 && !ft_strncmp(str, "PL", 2))
		return (1);
	else if (spc >= 1 && !ft_strncmp(str, "SP", 2))
		return (1);
	else if (cyc >= 1 && !ft_strncmp(str, "CY", 2))
		return (1);
	else if (coc >= 1 && !ft_strncmp(str, "CO", 2))
		return (1);
	return (0);
}

int	count_other(char *str)
{
	if (!ft_strncmp(str, "pl", 3) || !ft_strncmp(str, "PL", 3))
		return (0);
	else if (!ft_strncmp(str, "sp", 3) || !ft_strncmp(str, "SP", 3))
		return (0);
	else if (!ft_strncmp(str, "cy", 3) || !ft_strncmp(str, "CY", 3))
		return (0);
	else if (!ft_strncmp(str, "co", 3) || !ft_strncmp(str, "CO", 3))
		return (0);
	if (!ft_strncmp(str, "a", 2) || !ft_strncmp(str, "A", 2))
		return (0);
	else if (!ft_strncmp(str, "c", 2) || !ft_strncmp(str, "C", 2))
		return (0);
	else if (!ft_strncmp(str, "l", 2) || !ft_strncmp(str, "L", 2))
		return (0);
	else if (!ft_strncmp(str, "#", 1) || !ft_strncmp(str, "\n", 1))
		return (0);
	else
		return (1);
}
