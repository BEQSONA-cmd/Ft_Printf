/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:45:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/15 22:52:04 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, int j)
{
	j++;
	write(1, &c, 1);
	return (j);
}

int	ft_char_width_before(char c, int j, t_flags flags)
{
	j = ft_print_space(flags.width_before - 1, j, flags.fill);
	j = ft_char(c, j);
	return (j);
}

int	ft_char_width_after(char c, int j, int width_after)
{
	j = ft_char(c, j);
	j = ft_print_space(width_after - 1, j, ' ');
	return (j);
}
