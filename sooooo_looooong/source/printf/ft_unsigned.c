/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:08:18 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/26 13:28:14 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	knowlength(unsigned int n)
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

int	ft_unsigned(unsigned int n)
{
	unsigned int	div;
	unsigned int	mod;
	char			a;
	int				len;

	len = knowlength(n);
	div = n / 10;
	mod = n % 10;
	if (div > 0)
	{
		ft_unsigned(div);
	}
	a = mod + '0';
	write(1, &a, 1);
	return (len);
}
