/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:57:22 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/23 15:22:34 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
/*
int main(void)
{
    char    src[30] = "Hello, World!";
 
    ft_memmove(src + 2, src, 13);
    printf("%s\n", src);
}
*/
