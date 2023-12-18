/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:00:25 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/22 15:45:33 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**SYNOPSIS: #include <string.h>
**DESCRIPTION: The strnstr function locates the first
**occurence of the null-terminated string needle in the 
**null-terminated string haystack. Where not more than len 
**characters are searched.
**RETURN VALUE: If needle is empty string, haystack is returned
**if needle occurs nowhere in haystack, NULL is returned.
**otherwise a pointer to the first character of the first occurence
**of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if (len == 0 && (!needle || !haystack))
		return (0);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			a = 0;
			while (haystack[i + a] == needle[a] && (i + a) < len)
			{
				if (needle[a + 1] == '\0')
					return ((char *)&haystack[i]);
				a++;
			}
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char    haystack[50] = "Hello World, Hello People!";
    char    needle[50] = "World";

    printf("%s\n", ft_strnstr(haystack, needle, 11));
}
*/
