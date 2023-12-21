/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:12:41 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 14:21:37 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lowhexa(unsigned int lh, int *count)
{
	if (lh < 0)
	{
		if (ft_nputchar('-', count) == -1)
			return (-1);
		if (ft_lowhexa(-lh, count) == -1)
			return (-1);
	}
	if (lh > 15)
	{
		if (ft_lowhexa(lh / 16, count) == -1)
			return (-1);
		if (ft_lowhexa(lh % 16, count) == -1)
			return (-1);
	}
	if (lh >= 0 && lh <= 15)
	{
		if (ft_nputchar("0123456789abcdef"[lh], count) == -1)
			return (-1);
	}
	return (0);
}
