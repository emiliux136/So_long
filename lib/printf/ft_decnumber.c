/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:50:58 by emilgarc          #+#    #+#             */
/*   Updated: 2025/04/29 10:08:49 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	knowlength(long int n)
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

static char	*memory(int len, int n)
{
	char	*dest;

	if (n < 0)
		dest = (char *)malloc((sizeof(char)) * (len + 2));
	dest = (char *)malloc((sizeof(char)) * (len + 1));
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*dest;
	long int	nb;

	nb = n;
	len = knowlength(nb);
	dest = memory(len, n);
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	dest[len] = '\0';
	while (nb > 0)
	{
		if (nb < 0 && (len--) == 1)
			break ;
		dest[(len--) - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dest);
}

int	ft_decnumber(int n)
{
	return (ft_putstr((char *)ft_itoa(n)));
}
