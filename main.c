#include "ft_printf.h"
#include <stdio.h>  // for comparison

int main(void)
{
    int count_ft;
    int count_std;
    char c = 'A';
    char *str = "Hello, morning!";
    int num = -3456;
    unsigned int unum = 7878;
    void *ptr = &num;

    printf("%%c\n");
    count_ft = ft_printf("ft_printf: [%c]\n", c);
    count_std = printf("printf   : [%c]\n", c);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%s\n");
    count_ft = ft_printf("ft_printf: [%s]\n", str);
    count_std = printf("printf   : [%s]\n", str);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%d %%i\n");
    count_ft = ft_printf("ft_printf: [%d] [%i]\n", num, num);
    count_std = printf("printf   : [%d] [%i]\n", num, num);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%u\n");
    count_ft = ft_printf("ft_printf: [%u]\n", unum);
    count_std = printf("printf   : [%u]\n", unum);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%x / %%X\n");
    count_ft = ft_printf("ft_printf: [%x] [%X]\n", unum, unum);
    count_std = printf("printf   : [%x] [%X]\n", unum, unum);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%p\n");
    count_ft = ft_printf("ft_printf: [%p]\n", ptr);
    count_std = printf("printf   : [%p]\n", ptr);
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    printf("%%\n");
    count_ft = ft_printf("ft_printf: [%%]\n");
    count_std = printf("printf   : [%%]\n");
    printf("return values -> ft_printf: %d | printf: %d\n\n", count_ft, count_std);

    return (0);
}
