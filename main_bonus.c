#include <stdio.h>
#include <stdlib.h>

extern int ft_atoi_base(char *str, char *base);

int main(void)
{
    int back = ft_atoi_base(" ---+--+a28awe", "21584a");
    printf("here : %d", back);
    return (0);
}