#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Déclaration des fonctions ASM
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

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

void strlen_test(void)
{
    char *test = "Hey, its a msg !";
    int len = strlen(test);
    int ft_len = ft_strlen(test);

    printf("The string is '%s' \nstrlen : %d \nft_strlen : %d\n", test, len, ft_len);
}

void strcpy_test(void)
{
    char *dest = malloc(8);
    bzero(dest, 8);

    dest = strcpy(dest, "coucou!");
    printf("strcpy 'coucou!' -> '%s'\n", dest);
    bzero(dest, 8);
    printf("clean dest -> '%s'\n", dest);
    dest = ft_strcpy(dest, "coucou!");
    printf("ft_strcpy 'coucou!' -> '%s'\n", dest);

    free(dest);
}

void strcmp_test(void)
{
    char *s1 = "coucou1";
    char *s2 = "coucou1";
    char *s3 = "coutou1";
    char *s4 = "coucou";
    int cmp = 0;
    int ft_cmp = 0;

    cmp = strcmp(s1, s2);
    ft_cmp = ft_strcmp(s1, s2);
    printf("Test equal string :\n");
    printf("strcmp '%s' - '%s' : %d\n", s1, s2, cmp);
    printf("ft_strcmp '%s' - '%s' : %d\n\n", s1, s2, ft_cmp);

    cmp = strcmp(s1, s3);
    ft_cmp = ft_strcmp(s1, s3);
    printf("Test not equal string :\n");
    printf("strcmp '%s' - '%s' : %d\n", s1, s3, cmp);
    printf("ft_strcmp '%s' - '%s' : %d\n\n", s1, s3, ft_cmp);

    cmp = strcmp(s1, s4);
    ft_cmp = ft_strcmp(s1, s4);
    printf("Test s1 > s2 :\n");
    printf("strcmp '%s' - '%s' : %d\n", s1, s4, cmp);
    printf("ft_strcmp '%s' - '%s' : %d\n\n", s1, s4, ft_cmp);

    cmp = strcmp(s4, s1);
    ft_cmp = ft_strcmp(s4, s1);
    printf("Test s1 < s2 :\n");
    printf("strcmp '%s' - '%s' : %d\n", s4, s1, cmp);
    printf("ft_strcmp '%s' - '%s' : %d\n", s4, s1, ft_cmp);
}

void write_test(void)
{
    int back = 0;

    printf("Test with write on fd 1\n");
    back = write(1, "this is a test\n", 15);
    printf("back of write is : %d\n", back);

    printf("\nTest with ft_write on fd 1\n");
    back = ft_write(1, "this is a test\n", 15);
    printf("back of ft_write is : %d\n", back);

    printf("\nBad write on fd -1\n");
    back = write(-1, "this is a test\n", 15);
    printf("back of write is : %d\n", back);

    printf("\nBad ft_write on fd -1\n");
    back = ft_write(-1, "this is a test\n", 15);
    printf("back of ft_write is : %d\n", back);
}

void read_test(void)
{
    int fd = open("./read_test", O_CREAT);
    char buff[4];
    int back = 0;

    printf("try with read on read_test file on fd %d\n", fd);
    while ((back = read(fd, buff, 3)) > 0)
    {
        buff[back] = 0;
        printf("buffer of read '%s', nb byte readed : %d\n", buff, back);
    }
    close(fd);
    fd = open("./read_test", O_CREAT);

    printf("\ntry with ft_read on read_test file on fd %d\n", fd);
    while ((back = ft_read(fd, buff, 3)) > 0)
    {
        buff[back] = 0;
        printf("buffer of ft_read '%s', nb byte readed : %d\n", buff, back);
    }
    
    close(fd);

    back = read(-1, buff, 3);
    printf("\nBad fd (-1) on read : %d", back);
    back = ft_read(-1, buff, 3);
    printf("\nBad fd (-1) on ft_read : %d\n", back);
}

void strdup_test(void)
{
    char *duplicated;

    duplicated = strdup("Hey, this is my msg");
    printf("try duplicate with strdup : %s\n", duplicated);
    free(duplicated);
    duplicated = NULL;

    duplicated = ft_strdup("Hey, this is my msg");
    printf("try duplicate with ft_strdup : %s\n", duplicated);
    free(duplicated);
    duplicated = NULL;
}

int main(void)
{
    printHeader("Test of ft_strlen");
	strlen_test();
    printHeader("Test of ft_strcpy");
    strcpy_test();
    printHeader("Test of ft_strcmp");
    strcmp_test();
    printHeader("Test of ft_write");
    write_test();
    printHeader("Test of ft_read");
    read_test();
    printHeader("Test of ft_strdup");
    strdup_test();
    return (0);
}
