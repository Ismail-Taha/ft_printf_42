#include "printf.h"
#include <stdio.h>
#include <limits.h>


int main(void) {

    void *ptr;
    ft_printf("\n%d\n",ft_printf("%                +p", ptr));
	printf("\n%d\n",printf("%                +p", ptr));
    /*char *str = "abc% s\n%            d\n%##  pdef\n";
    ft_printf("\n%d\n",ft_printf(str, "Hello World", INT_MAX, str));
	printf("\n%d\n",printf(str, "Hello World", INT_MAX, str));*/
    return 0;
}