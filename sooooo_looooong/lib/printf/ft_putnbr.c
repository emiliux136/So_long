/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:15:12 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/26 12:30:36 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	knowlength(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		div;
	int		mod;
	char	a;
	int		len;

	len = knowlength(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0 && n != -2147483648)
	{
		write (1, "-", 1);
		n = n * -1;
	}
	div = n / 10;
	mod = n % 10;
	if (div > 0)
	{
		ft_putnbr(div);
	}
	a = mod + '0';
	write(1, &a, 1);
	return (len);
}
