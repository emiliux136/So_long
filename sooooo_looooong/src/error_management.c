/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:08:32 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/18 17:56:35 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrongwall()
{
	ft_printf("%s", WALL_MSG);
	return(FALSE);
}

char	**emptymsg()
{
	ft_printf("%s", EMPTY_MSG);
	return(0);
}
