/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:00:09 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/23 16:29:26 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**SYNOPSIS: #include <string.h>
**DESCRIPTION: Function lexicographically
**compare the null terminated strings s1 and s2. 
**strncmp dunction does not compare more than 
**n characters.
**RETURN VALUE: Returns an int greater, less or equal to 0.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main(void)
{
    char    s1[40] = "abcde";
    char    s2[40] = "abcdE";

    if (ft_strncmp(s1, s2, 5) > 0)
        printf("s1 is greater than s2 %d\n", ft_strncmp(s1, s2, 5));
    else if (ft_strncmp(s1, s2, 5) < 0)
        printf("s2 is greater than s1 %d\n", ft_strncmp(s1, s2, 5));
    else
        printf("s1 and s2 are equal %d\n", ft_strncmp(s1, s2, 5));
}
*/
