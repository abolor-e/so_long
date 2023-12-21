/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:00:43 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 13:37:22 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	nlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
	}
	else
	{
		nlen = ft_strlen(s + start);
		if (!(nlen < len))
			nlen = len;
		dest = (char *)malloc(sizeof(char) * (nlen + 1));
		if (!dest)
			return (NULL);
		dest[nlen] = 0;
		while (nlen-- > 0)
			dest[nlen] = s[start + nlen];
	}
	return (dest);
}

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start + 1; //(hola, 1, 45);
	if (start >= ft_strlen(s))
		len = 1;
	dest = (char *)malloc(sizeof(char) * (len));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(void)
{
    char    s[12] = "hola";
    int     start;

    start = 2;
    printf("%s\n", ft_substr(s, start, 30));

}
*/
