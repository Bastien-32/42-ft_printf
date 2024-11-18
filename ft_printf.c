/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:50 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/18 17:17:23 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdarg.h>

int	ft_putnbr(int n)
{
	int		i;
	char	c;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);		
}

int	ft_putnbr_base(int nb, char *base)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	if (nb >= ft_strlen(base))
		ft_putnbr_base(nb / ft_strlen(base), base);
	c = base[nb % ft_strlen(base)];
	write(1, &c, 1);
}


int	callconv(va_list args, const char *format)
{
	int	i;

	if (*format == 'c')
		i = i + ft_putchar(va_arg(args, int));
	else if (*format == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (*format == 'x')
		i = ft_putnbr_base(va_arg(args, unsigned int),"0123456789abcdef");
	else if (*format == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned int),"0123456789ABCDEF");
	return (i);
}
int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i = i + callconv(args, *format);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Hello, 42! My lucky number is %i.\n", 42);
	ft_printf("The numbers are: %d, %d, and %d.\n", 7, -42, 2147483647);
	ft_printf("Testing zero: %d\n", 0);
	ft_printf("Testing negative numbers: %d, %d\n", -1, -2147483648);
	ft_printf("This is a plain text without numbers.\n");
	ft_printf("Hello, 42! My lucky char is %c.\n", 'a');
	ft_printf("the alphabet go from %c to %c letter and count %d letters\n", 'a', 'z', 26);

	return (0);
}