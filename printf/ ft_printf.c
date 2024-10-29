#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int ft_str(char *str)
{
	int i;
	if(!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void ft_nbr(int nbr, int *i)
{
	char c;

	if (nbr == -2147483648)
	{
		*i += ft_str("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		(*i)++;
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_nbr(nbr / 10, i);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	(*i)++;
}

void ft_hix(unsigned int hix, int *i)
{
	char c;

	if (hix > 15)
		ft_hix(hix / 16, i);
	c = "0123456789abcdef"[hix % 16];
	write(1, &c, 1);
	(*i)++;	
}

int ft_printf(const char *format, ... )
{
	int i;
	va_list v_lst;

	va_start(v_lst, format);
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if(*format == 's')
				i += ft_str((char *)va_arg(v_lst, char *));
			else if(*format == 'd')
				ft_nbr((int)va_arg(v_lst, int), &i);
			else if(*format == 'x')
				ft_hix((unsigned int)va_arg(v_lst, unsigned int), &i);
			else
			{
				write(1, format, 1);
				i++;
			}
		}
		else
		{
			write(1, format, 1);
			i++;
		}
		format++;
	}
	va_end(v_lst);
	return (i);
}


// int main()
// {
// 	ft_printf("write this %x\n", -5788578);
// 	printf("write this %x\n", -5788578);
// }