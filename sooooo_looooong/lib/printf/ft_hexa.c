/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:05:38 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/30 16:12:31 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenhexa(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	printhexaminus(unsigned int n)
{
	if (n >= 16)
	{
		printhexaminus(n / 16);
		printhexaminus(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar((n - 10) + 'a');
	}
}

static void	printhexamayus(unsigned int n)
{
	if (n >= 16)
	{
		printhexamayus(n / 16);
		printhexamayus(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar((n - 10) + 'A');
	}
}

int	ft_hexa(unsigned int n, char x)
{
	int	len;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		len = lenhexa (n);
		if (x == 'x')
			printhexaminus(n);
		else if (x == 'X')
			printhexamayus (n);
	}
	return (len);
}
