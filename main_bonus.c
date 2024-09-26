#include <stdio.h>

extern int ft_atoi_base(char *str, char *base);

int main(void)
{
    int back = ft_atoi_base("   ---+--+123qwe", "21584");
    printf("here : %d", back);
    return (0);
}