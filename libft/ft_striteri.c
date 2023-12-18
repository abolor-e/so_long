/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:59:38 by abolor-e          #+#    #+#             */
/*   Updated: 2023/10/22 15:49:04 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void modifychar(unsigned int index, char *c) 
{
    if (*c >= 65 && *c <= 90)
        *c = *c - 'A' + 'a';
}

int main() 
{
    char str[] = "HELLO WORLD";
    
    ft_striteri(str, modifychar);
    printf("%s\n", str);

    return 0;
}
*/
