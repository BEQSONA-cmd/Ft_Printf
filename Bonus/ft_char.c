/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:45:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/16 18:31:43 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_precent(int j, t_flags flags)
{
	if (flags.width_before > 0)
		j = ft_char_width_before('%', j, flags);
	else if (flags.width_after > 0)
		j = ft_char_width_after('%', j, flags.width_after);
	else
		j = ft_char('%', j);
	return (j);
}

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

int	handle_format_c(va_list args, int j, t_flags flags)
{
	if (flags.width_before > 0)
		j = ft_char_width_before(va_arg(args, int), j, flags);
	else if (flags.width_after > 0)
		j = ft_char_width_after(va_arg(args, int), j, flags.width_after);
	else
		j = ft_char(va_arg(args, int), j);
	return (j);
}
