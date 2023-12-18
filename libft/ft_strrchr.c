/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:50 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/23 16:32:55 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**SYNOPSIS: #include <string.h>
**DESCRIPTION: The strrchr() function is identical to
**strchr(), except it locates the last occurence of c.
**RETURN VALUES: The function strrchr return a pointer
to the located character, or NULL if the character does not appear
**in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
    char    s[50] = "Hello World!";
    int     c;
    char    *res;

    c = 'g';
    res = ft_strrchr(s, c);
    printf("%s\n", res);
}
*/
