#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;




extern int ft_atoi_base(char *str, char *base);
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());

extern int ft_strcmp(const char *s1, const char *s2);

void putnumber(int n) {
    // Gestion des nombres négatifs
    if (n < 0) {
        write(1, "-", 1); // Affiche le signe moins
        n = -n; // Rend le nombre positif
    }
    
    // Gérer le nombre 0 séparément
    if (n == 0) {
        write(1, "0", 1);
        return;
    }

    // Variable pour stocker les chiffres
    char buffer[12]; // 11 caractères pour un int et 1 pour le '\0'
    int i = 0;

    // Extraire les chiffres et les stocker dans le buffer
    while (n > 0) {
        buffer[i++] = (n % 10) + '0'; // Obtenir le dernier chiffre
        n /= 10; // Réduire le nombre
    }

    // Afficher les chiffres en ordre inverse
    for (int j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1); // Utiliser write pour afficher chaque chiffre
    }
}

int testee(void *str1, void *str2)
{
    write(1, str1, strlen(str1));
    write(1, " | ", 3);
    write(1, str2, strlen(str2));
    int tt = strcmp((char *)str1, (char *)str2);
    putnumber(tt);
    write(1, "\n", 1);
    return (tt);
}

int main(void)
{
    int back = ft_atoi_base(" ---+--+7CE", "0123456789ABCDEF");
    printf("here : %d\n", back);

    t_list *test = NULL;
    ft_list_push_front(&test, "11");
    ft_list_push_front(&test, "22");
    ft_list_push_front(&test, "33");

    int lst_size = ft_list_size(test);

    printf("list size : %d\n", lst_size);

    // ft_list_sort(&test, &testee);
    // ft_list_sort(&test, &strcmp);
    ft_list_sort(&test, &ft_strcmp);

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