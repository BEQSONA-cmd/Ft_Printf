/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:08:51 by btvildia          #+#    #+#             */
/*   Updated: 2024/04/14 22:24:25 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_num(int n, int i);
int	ft_char(int c, int i);
int	ft_str(char *a, int i);
int	ft_hexl(size_t n, int i);
int	ft_hexu(size_t n, int i);
int	ft_printf(const char *a, ...);
int	ft_uns(unsigned int n, int i);
int	ft_ptr(unsigned long nb, int j);
int	ft_ptr(unsigned long ptr, int j);
int	ft_next_precent(const char *format, va_list args, int j, int i);

#endif
