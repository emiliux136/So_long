/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:02:27 by emilgarc          #+#    #+#             */
/*   Updated: 2025/02/06 18:56:56 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h> 

char	*get_next_line(int fd);
char	*ftgnl_strjoin(char *str1, char *str2);
char	*ftgnl_strchr(char *s, int c);
size_t	len(char *s);
char	*ft_alloc(int fd, char *str);
char	*rline(char *line);
char	*nline(char *str);

#endif