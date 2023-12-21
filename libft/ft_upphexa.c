/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upphexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:39:33 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 14:19:05 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_upphexa(unsigned int uh, int *count)
{
	if (uh < 0)
	{
		if (ft_nputchar('-', count) == -1)
			return (-1);
		if (ft_upphexa(-uh, count) == -1)
			return (-1);
	}
	if (uh > 15)
	{
		if (ft_upphexa(uh / 16, count) == -1)
			return (-1);
		if (ft_upphexa(uh % 16, count) == -1)
			return (-1);
	}
	if (uh >= 0 && uh <= 15)
	{
		if (ft_nputchar("0123456789ABCDEF"[uh], count) == -1)
			return (-1);
	}
	return (0);
}
