#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;




extern int ft_atoi_base(char *str, char *base);
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());

int main(void)
{
    int back = ft_atoi_base(" ---+--+7CE", "0123456789ABCDEF");
    printf("here : %d\n", back);

    t_list *test = NULL;
    ft_list_push_front(&test, "aa");
    ft_list_push_front(&test, "ab");

    int lst_size = ft_list_size(test);

    printf("list size : %d\n", lst_size);

    ft_list_sort(&test, &strcmp);

    t_list *lst = test;
    while(lst)
    {
        printf("list : %s\n", (char *)lst->data);
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }
    return (0);
}