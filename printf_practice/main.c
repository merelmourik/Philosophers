#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *str, ...);

int main(){
	printf("%d\n", 42);
	printf("%.1d\n", 42);
	printf("%.10d\n", 42);
	printf("%s\n", "kaas");
	printf("%.2s\n", "kaas");
	printf("%.6s\n", "kaas");
	printf("%.3x\n", 42);
	printf("%.30x\n\n", 42);
	
	ft_printf("%d\n", 42);
	ft_printf("%.1d\n", 42);
	ft_printf("%.10d\n", 42);
	ft_printf("%s\n", "kaas");
	ft_printf("%.2s\n", "kaas");
	ft_printf("%.6s\n", "kaas");
	ft_printf("%.3x\n", 42);
	ft_printf("%x\n", 42);
	ft_printf("%.30x\n", 42);
	// printf("%d.1\n", 1, 42);
	// printf("%d.10\n", 6, 42);
	// printf("%s.2\n", 2, "kaas");
	// printf("%s.6\n", 6, "kaas");
	// printf("%x.3\n", 3, 42);
	// printf("%x.30\n", 10, 42);
	return (0);
}