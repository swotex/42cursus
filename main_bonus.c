#include <stdio.h>
#include <stdlib.h>

extern int ft_atoi_base(char *str, char *base);

int main(void)
{
    int back = ft_atoi_base(" ---+--+7CF", "0123456789ABCDEF");
    printf("here : %d", back);
    return (0);
}