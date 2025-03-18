/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:20:08 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/30 16:32:43 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenptr(uintptr_t ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	printptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		printptr(ptr / 16);
		printptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar((ptr - 10) + 'a');
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (len += (write (1, "(nil)", 5)));
	else
	{
		len = 2;
		write(1, "0x", 2);
		printptr(ptr);
		len += lenptr(ptr);
	}
	return (len);
}
