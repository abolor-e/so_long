/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:03:51 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/16 11:30:51 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	a;

	a = 0;
	if (c > 47 && c < 58)
	{
		++a;
		return (a);
	}
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isdigit('a'));
}
*/