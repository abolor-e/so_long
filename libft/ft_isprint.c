/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:51:06 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/22 14:47:13 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**SYNOPSIS: #include <ctype.h>
**The function tests for any printing character, including space ('\ ').
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
    printf("%d\n", ft_isprint('~'));
}
*/
