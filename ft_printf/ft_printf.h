/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:48:47 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/29 19:05:47 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		unsigned_decimal(unsigned int n, int base);
int		ft_printf(const char *format, ...);
int		hex_low(unsigned long n, int base);
int		hex_up(long long n, int base);
int		print_char(int c);
int		print_digit(int n, int base);
int		print_int(long long n);
int		print_pointer(void *ptr);
int		print_str(char *s);
#endif
