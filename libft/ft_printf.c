/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:34:43 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 14:19:54 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(unsigned long args, char c, int *count)
{
	int	a;

	a = 0;
	if (c == 'c')
		a = ft_nputchar((char)args, count);
	if (c == 'd')
		a = ft_nputnbr((int)args, count);
	if (c == 'i')
		a = ft_nputnbr((int)args, count);
	if (c == 'x')
		a = ft_lowhexa((unsigned int)args, count);
	if (c == 'X')
		a = ft_upphexa((unsigned int)args, count);
	if (c == 'u')
		a = ft_pputnbr((unsigned int)args, count);
	if (c == 's')
	{
		if (args)
			a = ft_nputstr((char *)args, count);
		else
			a = ft_nputstr("(null)", count);
	}
	if (c == 'p')
		a = ft_putaddr((void *)args, count);
	return (a);
}

int	ft_vprintf(const char *fmt, va_list args, int *count)
{
	int	i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			if (ft_nputchar(fmt[i], count) == -1)
				return (-1);
		}
		else if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if (check(va_arg(args, unsigned long), fmt[i + 1], count) == -1)
				return (-1);
			i++;
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%')
		{
			if (ft_nputchar('%', count) == -1)
				return (-1);
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!fmt)
		return (0);
	va_start(args, fmt);
	if (ft_vprintf(fmt, args, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}
