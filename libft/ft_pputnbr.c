/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:47:44 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 14:20:01 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pputnbr(unsigned int n, int *count)
{
	if (n > 9)
	{
		if (ft_pputnbr(n / 10, count) == -1)
			return (-1);
		if (ft_pputnbr(n % 10, count) == -1)
			return (-1);
	}
	if (n >= 0 && n <= 9)
	{
		if (ft_nputchar(n + 48, count) == -1)
			return (-1);
	}
	return (0);
}
