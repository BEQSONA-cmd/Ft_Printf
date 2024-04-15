/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:38:31 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:31:57 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long nb, int j)
{
	if (nb >= 16)
	{
		j = ft_print_ptr((nb / 16), j);
		j = ft_print_ptr((nb % 16), j);
	}
	else
	{
		if (nb <= 9)
			j = ft_char((nb + '0'), j);
		else
			j = ft_char((nb - 10 + 'a'), j);
	}
	return (j);
}

int	ft_ptr(unsigned long ptr, int j)
{
	j = ft_str("0x", j);
	if (ptr == 0)
		j = ft_char('0', j);
	else
	{
		j = ft_print_ptr(ptr, j);
	}
	return (j);
}

int	ft_ptr_width_before(unsigned long ptr, int j, int width_before)
{
	j = ft_print_space(width_before - ft_hexlen(ptr) - 2, j);
	j = ft_ptr(ptr, j);
	return (j);
}

int	ft_ptr_width_after(unsigned long ptr, int j, int width_after)
{
	j = ft_ptr(ptr, j);
	j = ft_print_space(width_after - ft_hexlen(ptr) - 2, j);
	return (j);
}
