#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_data
{
	int precision;
	int width;
	int has_precision;
	int count;
	va_list ap;
}			t_data;

void reset_struct(t_data *data){
	data->precision = 0;
	data->width = 0;
	data->has_precision = 0;
}

void ft_putchar(char c, t_data *data){
	write(1, &c, 1);
	data->count++;
}

void ft_putnumber(long n, t_data *data){
	if (n > 9){
		ft_putnumber(n / 10, data);
		ft_putnumber(n % 10, data);
	}
	else
		ft_putchar(n + 48, data);
}

void ft_puthex(long n, t_data *data){
	int i = 0;
	if (n >= 16){
		ft_puthex(n / 16, data);
		ft_puthex(n % 16, data);
	}
	else if (n > 9){
		while (n > 9){
			n--;
			i++;
		}
		ft_putchar(96 + i, data);
	}
	else
		ft_putchar(n + 48, data);
}

void	print_s(char *str, t_data *data){
	int i = 0;
	int len = 0;
	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	if (data->has_precision && data->precision < len)
		len = data->precision;
	while (data->width > len){
		ft_putchar(' ', data);
		data->width--;
	}
	while (len > 0){
		ft_putchar(str[i], data);
		i++;
		len--;
	}
}

void	print_d(long n, t_data *data){
	int len = 0;
	long copy = n;
	int negative = 0;
	if (n == 0)
		len = 1;
	if (n < 0){
		negative = 1;
		data->width--;
		n *= -1;
	}
	while(copy > 0){
		copy /= 10;
		len++;
	}
	if (data->has_precision && data->precision > len)
		data->width = data->width - data->precision - len;
	while (data->width > len){
		ft_putchar(' ', data);
		data->width--;
	}
	if (negative == 1 && data->precision >= len)
		ft_putchar('-', data);
	while(data->precision > len){
		ft_putchar('0', data);
		data->precision--;
	}
	if (negative == 1 && data->precision < len)
		ft_putchar('-', data);
	if (data->has_precision && data->precision == 0 && n == 0){
		if (data->width > 0)
			ft_putchar(' ', data);
		return ;
	}
	ft_putnumber(n, data);
}

void	print_x(long n, t_data *data){
	int len = 0;
	long copy = n;
	if (n == 0)
		len = 1;
	while(copy > 0){
		copy /= 16;
		len++;
	}
	if (data->has_precision && data->precision > len)
		data->width = data->width - data->precision - len;
	while (data->width > len){
		ft_putchar(' ', data);
		data->width--;
	}
	while(data->precision > len){
		ft_putchar('0', data);
		data->precision--;
	}
	if (data->has_precision && data->precision == 0 && n == 0){
		if (data->width > 0)
			ft_putchar(' ', data);
		return ;
	}
	ft_puthex(n, data);
}

void check_flags(const char **str, t_data *data){
	while(**str >= 0 && **str <= 9){
		data->width = data->width * 10 + (**str - 48); 
		(*str)++;
	}
	if (**str == '.'){
		data->has_precision = 1;
		(*str)++;
		while(**str >= '0' && **str <= '9'){
			data->precision = data->precision * 10 + (**str - 48);
			(*str)++;
		}
	}
	if (**str == 's')
		print_s(va_arg(data->ap, char*), data);
	if (**str == 'd')
		print_d(va_arg(data->ap, int), data);
	if (**str == 'x')
		print_x(va_arg(data->ap, unsigned int), data);
	(*str)++;
}

int ft_printf(const char *str, ...)
{
	t_data data;
	
	va_start(data.ap, str);
	data.count = 0;
	while (*str != '\0'){
		if(*str == '%'){
			str++;
			reset_struct(&data);
			check_flags(&str, &data);
		}
		if (*str != '\0' && *str != '%'){
			ft_putchar(str[0], &data);
			str++;
		}
	}
	va_end(data.ap);
	return(data.count);
}
