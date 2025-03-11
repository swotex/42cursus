#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET "\033[0m"
#define TITLE "\033[3;32m"
#define SUBTITLE "\033[3;35m"

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;




extern int ft_atoi_base(char *str, char *base);
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int ft_list_size(t_list *begin);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

extern int ft_strcmp(const char *s1, const char *s2);


// ########## Utils ##########

void printHeader(const char *str)
{
    int len = 36 - strlen(str);

    printf("\n########################################\n");

    printf("##");
    for(int i=0; i < len / 2; i++)
    {
        printf(" ");
    }
    printf(TITLE"%s"RESET,str);
    for(int i=0; i < ((len / 2) + len % 2); i++)
    {
        printf(" ");
    }
    printf("##\n");

    printf("########################################\n\n");
}


void print_list(t_list **lst)
{
    if (!lst)
        printf("no list given\n");
    t_list *tmp = *lst;
    if (!tmp)
        printf("list empty\n");
    int pos = 0;
    while(tmp)
    {
        printf("list[%d] : %s\n", pos, (char *)tmp->data);
        tmp = tmp->next;
        pos++;
    }
    
}

void free_list(t_list **lst)
{
    if (!lst)
        return ;
    t_list *tmp = *lst;
    while(tmp)
    {
        t_list *to_free = tmp;
        tmp = tmp->next;
        free(to_free);
    }
    
}
void double_free_list(t_list **lst)
{
    if (!lst)
        return ;
    t_list *tmp = *lst;
    while(tmp)
    {
        t_list *to_free = tmp;
        tmp = tmp->next;
        free(to_free->data);
        free(to_free);
    }
    
}

t_list *get_list(int size)
{
    t_list *lst = NULL;
    if (size >= 1)
        ft_list_push_front(&lst, "bad");
    if (size >= 2)
        ft_list_push_front(&lst, "small");
    if (size >= 3)
        ft_list_push_front(&lst, "champion");
    if (size >= 4)
        ft_list_push_front(&lst, "reputation");
    if (size >= 5)
        ft_list_push_front(&lst, "frequency");
    return (lst);
}

// ########## Tests ##########
void test_atoi_base()
{
    int back;
    printf("---------- "SUBTITLE"Test with NULL"RESET" ----------\n");
    back = ft_atoi_base(NULL, "0123456789ABCDEF"); // input NULL
    printf("(NULL, '0123456789ABCDEF') -> %d\n", back);
    back = ft_atoi_base(" ---+--+7CE", NULL); // Base NULL
    printf("(' ---+--+7CE', NULL)      -> %d\n", back);

    printf("\n---------- "SUBTITLE"Test with bad input"RESET" ----------\n");
    back = ft_atoi_base("", "0123456789"); // empty input
    printf("('', '0123456789')             -> %d\n", back);
    back = ft_atoi_base("       - 23", "0123456789"); // white-space after operand
    printf("('       - 23', '0123456789')  -> %d\n", back);
    back = ft_atoi_base("       -23RT", "0123456789"); // Out of Operand
    printf("('       -23RT', '0123456789') -> %d\n", back);

    printf("\n---------- "SUBTITLE"Test with bad base"RESET" ----------\n");
    back = ft_atoi_base("23", ""); // empty base
    printf("('23', '')        -> %d\n", back);
    back = ft_atoi_base("23", " 123456"); // White-space in base
    printf("('23', ' 123456') -> %d\n", back);
    back = ft_atoi_base("23", "1234526"); // Twice item in base
    printf("('23', '1234526') -> %d\n", back);
    back = ft_atoi_base("23", "-123456"); // Operand in base
    printf("('23', '-123456') -> %d\n", back);

    printf("\n---------- "SUBTITLE"Test multiple operands (Base 16)"RESET" ----------\n");
    back = ft_atoi_base("23", "0123456789ABCDEF"); // Simple test
    printf("('23', '0123456789ABCDEF')                    -> %d\n", back);
    back = ft_atoi_base(" ---+--+7CE", "0123456789ABCDEF"); // test with operand (negative)
    printf("(' ---+--+7CE', '0123456789ABCDEF')           -> %d\n", back);
    back = ft_atoi_base("      ---+--+++-+AE80", "0123456789ABCDEF"); // test with operand (positive)
    printf("('      ---+--+++-+AE80', '0123456789ABCDEF') -> %d\n", back);

    printf("\n---------- "SUBTITLE"Test Base 2"RESET" ----------\n");
    back = ft_atoi_base("1010", "01"); // Simple convert binary
    printf("('1010', '01')           -> %d\n", back);
    back = ft_atoi_base("00100101010001", "01"); // Other convert binary
    printf("('00100101010001', '01') -> %d\n", back);
}

void test_push_front()
{
    t_list *lst = NULL;

    printf("---------- "SUBTITLE"Test with NULL list"RESET" ----------\n");
    ft_list_push_front(NULL, "test");
    printf("(NULL, 'test') -> ");
    print_list(&lst);
    ft_list_push_front(&lst, NULL);
    printf("(&lst, NULL)   -> ");
    print_list(&lst);

    printf("\n---------- "SUBTITLE"Test fill list"RESET" ----------\n");
    ft_list_push_front(&lst, "bad");
    ft_list_push_front(&lst, "small");
    ft_list_push_front(&lst, "champion");
    ft_list_push_front(&lst, "reputation");
    ft_list_push_front(&lst, "frequency");
    print_list(&lst);

    free_list(&lst);
}

void test_lst_size()
{
    t_list *lst = NULL;
    int size;

    printf("---------- "SUBTITLE"Test NULL"RESET" ----------\n");
    size = ft_list_size(lst);
    printf("(NULL)         -> %d\n", size);
    free_list(&lst);

    printf("\n---------- "SUBTITLE"Test size 5"RESET" ----------\n");
    lst = get_list(5);
    size = ft_list_size(lst);
    printf("(list[size 5]) -> %d\n", size);
    free_list(&lst);

    printf("\n---------- "SUBTITLE"Test size 3"RESET" ----------\n");
    lst = get_list(3);
    size = ft_list_size(lst);
    printf("(list[size 3]) -> %d\n", size);
    free_list(&lst);

    printf("\n---------- "SUBTITLE"Test size 1"RESET" ----------\n");
    lst = get_list(1);
    size = ft_list_size(lst);
    printf("(list[size 1]) -> %d\n", size);

    free_list(&lst);
}

void test_lst_sort()
{
    t_list *lst = NULL;

    printf("---------- "SUBTITLE"Test NULL"RESET" ----------\n");
    ft_list_sort(NULL, strcmp);
    printf("(NULL, strcmp) -> NO ERROR\n");
    ft_list_sort(&lst, NULL);
    printf("(&lst, NULL)   -> NO ERROR\n");

    printf("\n---------- "SUBTITLE"Test list size 5"RESET" ----------\n");
    lst = get_list(5);
    printf("(list[size 5]) : bad, small, champion, reputation, frequency\n");
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);

    printf("\n---------- "SUBTITLE"Test list size 1"RESET" ----------\n");
    lst = get_list(1);
    printf("(list[size 1]) : bad\n");
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);

    printf("\n---------- "SUBTITLE"Test list already sorted"RESET" ----------\n");
    lst = NULL;
    ft_list_push_front(&lst, "aaasdf");
    ft_list_push_front(&lst, "caasdf");
    ft_list_push_front(&lst, "haasdf");
    printf("(list[size 3]) : aaasdf, caasdf, haasdf\n");
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);
}


void test_lst_remove()
{
    t_list *lst = NULL;

    printf("\n---------- "SUBTITLE"Test with NULL"RESET" ----------\n");
    printf("Test with NULL for -> **begin_list, *begin_list, data_ref, compare function, free function\n");
    ft_list_remove_if(NULL, "test", strcmp, free); // Null for **begin_list
    ft_list_remove_if(&lst, "test", strcmp, free); // Null for *begin_list
    ft_list_remove_if(&lst, NULL, strcmp, free); // Null for data_ref
    ft_list_remove_if(&lst, "test", NULL, free); // Null for compare function
    ft_list_remove_if(&lst, "test", strcmp, NULL); // Null for free function

    printf("\n---------- "SUBTITLE"Test remove size 1 top"RESET" ----------\n");
    ft_list_push_front(&lst, strdup("Hey"));
    ft_list_remove_if(&lst, "Hey", ft_strcmp, free);
    printf("(list[size 1], remove('Hey')) : Hey -> ");
    print_list(&lst);

    printf("\n---------- "SUBTITLE"Test remove size 2 top"RESET" ----------\n");
    ft_list_push_front(&lst, strdup("Hey"));
    ft_list_push_front(&lst, strdup("Hey"));
    ft_list_remove_if(&lst, "Hey", ft_strcmp, free);
    printf("(list[size 1], remove('Hey')) : Hey, Hey -> ");
    print_list(&lst);

    printf("\n---------- "SUBTITLE"Test middle remove"RESET" ----------\n");
    ft_list_push_front(&lst, strdup("banana"));
    ft_list_push_front(&lst, strdup("bread"));
    ft_list_push_front(&lst, strdup("milk"));
    ft_list_push_front(&lst, strdup("milk"));
    ft_list_push_front(&lst, strdup("ZEBRA"));
    ft_list_push_front(&lst, strdup("tomato"));
    ft_list_push_front(&lst, strdup("other"));

    ft_list_remove_if(&lst, "milk", strcmp, free);
    printf("(list[size 7], remove('milk')) : other, tomato, ZEBRA, milk, milk, bread, banana\n");
    print_list(&lst);

    double_free_list(&lst);
    lst = NULL;

    printf("\n---------- "SUBTITLE"Test end remove"RESET" ----------\n");
    ft_list_push_front(&lst, strdup("banana"));
    ft_list_push_front(&lst, strdup("banana"));
    ft_list_push_front(&lst, strdup("milk"));
    ft_list_push_front(&lst, strdup("milk"));
    ft_list_push_front(&lst, strdup("ZEBRA"));
    ft_list_push_front(&lst, strdup("tomato"));
    ft_list_push_front(&lst, strdup("other"));

    ft_list_remove_if(&lst, "banana", strcmp, free);
    printf("(list[size 7], remove('banana')) : other, tomato, ZEBRA, milk, milk, banana, banana\n");
    print_list(&lst);
    
    double_free_list(&lst);
}

void waitUserKeyPress() {
    printf("\033[999;1HPress enter to see next");
    getchar();
    printf("\033[2J\033[H");
}

int main(void)
{
    printf("\033[2J\033[H");

    printHeader("Test ft_atoi_base");
    test_atoi_base();

    waitUserKeyPress();

    printHeader("Test ft_list_push_front");
    test_push_front();

    waitUserKeyPress();

    printHeader("Test ft_list_size");
    test_lst_size();

    waitUserKeyPress();

    printHeader("Test ft_list_sort");
    test_lst_sort();

    waitUserKeyPress();
    
    printHeader("Test ft_list_remove_if");
    test_lst_remove();

    return (0);
}