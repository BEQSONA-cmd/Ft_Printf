/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:19 by btvildia          #+#    #+#             */
/*   Updated: 2024/03/12 23:31:53 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_find_char(int c, int i);
int	ft_ptr(unsigned long nb, int j);
int	ft_find_str(char *a, int i);
int	ft_find_number(int n, int i);
int	ft_printf(const char *a, ...);
int	ft_find_hexup(size_t n, int i);
int	ft_find_hexlow(size_t n, int i);
int	ft_find_ptr(unsigned long ptr, int j);
int	ft_find_uns(unsigned int n, int i);
int	ft_next_precent(const char *format, va_list args, int j, int i);

#endif
