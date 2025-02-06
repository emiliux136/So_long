/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:05:48 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/30 17:02:39 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_variety(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, uintptr_t)));
	else if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(args, unsigned int), c));
	return (1);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_variety(s[i], args);
			i++;
		}
		else
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end (args);
	return (len);
}
