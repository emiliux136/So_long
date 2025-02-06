/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:40:37 by emilgarc          #+#    #+#             */
/*   Updated: 2024/12/30 14:35:24 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(char const *s, ...);
int		ft_putchar(int c);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsigned(unsigned int n);
int		ft_putptr(uintptr_t ptr);
int		ft_hexa(unsigned int n, char x);

#endif