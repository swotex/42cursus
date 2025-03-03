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
    printf("\033[3;32m%s\033[0m",str);
    for(int i=0; i < ((len / 2) + len % 2); i++)
    {
        printf(" ");
    }
    printf("##\n");

    printf("########################################\n\n");
}

void	ft_free(void *ptr)
{
    // (void)ptr;
	// if (ptr)
		// free(ptr);
    printf("oui : %s \n", (char *)ptr);
    *(char *)ptr = 'X';
    printf("oui : %s \n", (char *)ptr);
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
    printf("----- Test with NULL -----\n");
    back = ft_atoi_base(NULL, "0123456789ABCDEF");
    printf("Result : %d\n", back);
    back = ft_atoi_base(" ---+--+7CE", NULL);
    printf("Result : %d\n", back);

    printf("\n----- Test multiple operands (Base 16) -----\n");
    back = ft_atoi_base(" ---+--+7CE", "0123456789ABCDEF");
    printf("Result (' ---+--+7CE') : %d\n", back);

    printf("\n----- Test Base 2 -----\n");
    back = ft_atoi_base("00100101010001", "01");
    printf("Result ('00100101010001') : %d\n", back);
}

void test_push_front()
{
    t_list *lst = NULL;

    printf("----- Test with NULL list -----\n");
    ft_list_push_front(NULL, "test");
    print_list(&lst);

    printf("\n----- Test fill list -----\n");
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

    printf("----- Test NULL -----\n");
    size = ft_list_size(lst);
    printf("Size (0) : %d\n", size);
    free_list(&lst);

    printf("\n----- Test size 5 -----\n");
    lst = get_list(5);
    size = ft_list_size(lst);
    printf("Size (5) : %d\n", size);
    free_list(&lst);

    printf("\n----- Test size 3 -----\n");
    lst = get_list(3);
    size = ft_list_size(lst);
    printf("Size (3) : %d\n", size);
    free_list(&lst);

    printf("\n----- Test size 1 -----\n");
    lst = get_list(1);
    size = ft_list_size(lst);
    printf("Size (1) : %d\n", size);

    free_list(&lst);
}

void test_lst_sort()
{
    t_list *lst = NULL;

    printf("----- Test NULL -----\n");
    ft_list_sort(NULL, strcmp);
    ft_list_sort(&lst, strcmp);

    printf("\n----- Test list size 5 -----\n");
    lst = get_list(5);
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);

    printf("\n----- Test list size 1 -----\n");
    lst = get_list(1);
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);

    printf("\n----- Test list already sorted -----\n");
    lst = NULL;
    ft_list_push_front(&lst, "aaasdf");
    ft_list_push_front(&lst, "caasdf");
    ft_list_push_front(&lst, "haasdf");
    ft_list_sort(&lst, strcmp);
    print_list(&lst);
    free_list(&lst);
}




void	ft_list_remove_if_test(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*remove;
	t_list	*current;

	current = *begin_list;
	while (current && current->next)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			remove = current->next;
			current->next = current->next->next;
			// free(remove);
            (*free_fct)(remove);
		}
		current = current->next;
	}
	current = *begin_list;
	if (current && (*cmp)(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
	}
}




void test_lst_remove()
{
    t_list *lst = NULL;

    // printf("----- Test with NULL -----\n");
    // ft_list_remove_if(NULL, "test", strcmp, ft_free);
    // ft_list_remove_if(&lst, "test", strcmp, ft_free);

    // ft_list_push_front(&lst, "test");

    // ft_list_remove_if(NULL, "test2", NULL, ft_free);
    // ft_list_remove_if(&lst, "test", strcmp, NULL);

    // printf("\n----- Test remove 1 top -----\n");
    // ft_list_remove_if(&lst, "test", strcmp, ft_free);
    // ft_list_remove_if(&lst, "test", strcmp, free);

    // ft_list_push_front(&lst, "test");
    // ft_list_push_front(&lst, "test");

    // printf("\n----- Test remove 2 top -----\n");
    // ft_list_remove_if(&lst, "test", strcmp, ft_free);


    ft_list_push_front(&lst, "sdf4");
    ft_list_push_front(&lst, "sfsdf3");
    ft_list_push_front(&lst, "test2");
    ft_list_push_front(&lst, "test2");
    ft_list_push_front(&lst, "tesfsdfst1");

    printf("\n----- Test middle remove -----\n");
    // ft_list_remove_if_test(&lst, "test2", strcmp, ft_free);
    // ft_list_remove_if(&lst, "test2", strcmp, ft_free);
    ft_list_remove_if(&lst, "test2", strcmp, free);
    print_list(&lst);

    free_list(&lst);
}

int main(void)
{
    printHeader("Test ft_atoi_base");
    test_atoi_base();

    printHeader("Test ft_list_push_front");
    test_push_front();

    printHeader("Test ft_list_size");
    test_lst_size();

    printHeader("Test ft_list_sort");
    test_lst_sort();
    
    printHeader("Test ft_list_remove_if");
    test_lst_remove();

    return (0);
}