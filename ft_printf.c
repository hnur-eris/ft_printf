/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:51:04 by haeris            #+#    #+#             */
/*   Updated: 2022/03/16 16:33:11 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//scanf inputtaki değeri alıyor d , i
//is_upper büyük harf ise
#include "ft_printf.h"

int	ft_control(char c, va_list variable)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(variable, int));
	else if (c == 's')
		count += ft_str(va_arg(variable, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(variable, int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr(va_arg(variable, unsigned int), 16, 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(variable, unsigned int), 10, 0);
	else if (c == 'p')
		count += ft_pointer(va_arg(variable, unsigned long), 16, 0);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;

	val = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			val += ft_control(*(str + 1), ap);
			str++;
		}
		else
			val += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (val);
}
/*int main()
{
	char *c = "%d";
	printf("2%d",printf(c,123));
}*/
/*int main()
{
	ft_printf("%h", "aha");
}*/
