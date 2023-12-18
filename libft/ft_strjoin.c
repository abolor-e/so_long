/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:59:50 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/22 15:39:24 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	char	*ns;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	a = ft_strlen(s2);
	ns = (char *)malloc(sizeof(char) * (i + a + 1));
	if (!ns)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		ns[a] = s1[a];
		a++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ns[a + i] = s2[i];
		i++;
	}
	ns[a + i] = '\0';
	return (ns);
}
/*
int main(void)
{
    char    s1[20] = "Hello World!";
    char    s2[20] = "Hello Saturn!";

    printf("%s\n", ft_strjoin(s1, s2));
}
*/
