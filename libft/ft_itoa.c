/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:56:45 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/23 15:58:34 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	i;
	int			digits;

	i = n;
	digits = ft_digits(n);
	if (n < 0)
	{
		i *= -1;
		digits++;
	}
	res = (char *)malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (NULL);
	*(res + digits) = 0;
	while (digits--)
	{
		*(res + digits) = i % 10 + '0';
		i = i / 10;
	}
	if (n < 0)
		*(res + 0) = '-';
	return (res);
}
/*
int main(void)
{
    printf("%s\n", ft_itoa(-2147483648));
}
*/
