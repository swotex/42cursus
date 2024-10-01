#include <stdio.h>
#include <stdlib.h>

extern int ft_atoi_base(char *str, char *base);
extern int power(int base, int exponent);

int main(void)
{
    int back = ft_atoi_base(" ---+--+7CE", "0123456789ABCDEF");
    printf("here : %d\n", back);
    int t = power(16, 0);
    printf("power : %d", t);
    return (0);
}