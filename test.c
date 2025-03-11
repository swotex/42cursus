#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define RESET "\033[0m"
#define TITLE "\033[3;32m"
#define SUBTITLE "\033[3;35m"

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
    printf(TITLE"%s"RESET,str);
    for(int i=0; i < ((len / 2) + len % 2); i++)
    {
        printf(" ");
    }
    printf("##\n");

    printf("########################################\n\n");
}

void errorAlloc(void)
{
    printf("error malloc");
    exit(1);
}

// ##### Tests #####
void strlen_test(void)
{
    int len = -1;
    int ft_len = -1;

    printf("---------- "SUBTITLE"Test with len 0"RESET" ----------\n");
    ft_len = ft_strlen("");
    len = strlen("");
    printf("('') -> strlen : %d, ft_strlen : %d\n", len, ft_len);

    printf("\n---------- "SUBTITLE"Test with len 3"RESET" ----------\n");
    ft_len = ft_strlen("Yep");
    len = strlen("Yep");
    printf("('Yep') -> strlen : %d, ft_strlen : %d\n", len, ft_len);

    printf("\n---------- "SUBTITLE"Test with len 16 (Special)"RESET" ----------\n");
    ft_len = ft_strlen("Jump line \n Here");
    len = strlen("Jump line \n Here");
    printf("('Jump line \\n Here') -> strlen : %d, ft_strlen : %d\n", len, ft_len);
}

void strcpy_test(void)
{
    char *dest = malloc(8);
    if (!dest)
        errorAlloc();
    bzero(dest, 8);

    printf("---------- "SUBTITLE"Test with len 0"RESET" ----------\n");
    printf("(dest[malloc 8], '') :\n");

    dest = strcpy(dest, "");
    printf("strcpy : '%s',\n", dest);
    bzero(dest, 8);

    dest = ft_strcpy(dest, "");
    printf("ft_strcpy : '%s'\n", dest);
    bzero(dest, 8);

    printf("\n---------- "SUBTITLE"Test with len 3"RESET" ----------\n");
    printf("(dest[malloc 8], 'hey!') :\n");
    
    dest = strcpy(dest, "hey!");
    printf("strcpy : '%s',\n", dest);
    bzero(dest, 8);

    dest = ft_strcpy(dest, "hey!");
    printf("ft_strcpy : '%s'\n", dest);
    bzero(dest, 8);

    printf("\n---------- "SUBTITLE"Test with len 7 (size+'\\0')"RESET" ----------\n");
    printf("(dest[malloc 8], 'coucou!') :\n");
    
    dest = strcpy(dest, "coucou!");
    printf("strcpy : '%s',\n", dest);
    bzero(dest, 8);

    dest = ft_strcpy(dest, "coucou!");
    printf("ft_strcpy : '%s'\n", dest);
    bzero(dest, 8);

    free(dest);
}

void strcmp_test(void)
{
    char *s1 = "same";
    char *s2 = "same";
    char *s3 = "diff";
    char *s4 = "samegreater";
    int cmp = 0;
    int ft_cmp = 0;

    printf("---------- "SUBTITLE"Test equal string"RESET" ----------\n");
    cmp = strcmp(s1, s2);
    ft_cmp = ft_strcmp(s1, s2);
    printf("('%s', '%s') :\n", s1, s2);
    printf("strcmp : %d\n", cmp);
    printf("ft_strcmp :%d\n", ft_cmp);

    printf("\n---------- "SUBTITLE"Test not equal string"RESET" ----------\n");
    cmp = strcmp(s1, s3);
    ft_cmp = ft_strcmp(s1, s3);
    printf("('%s', '%s') :\n", s1, s3);
    printf("strcmp : %d\n", cmp);
    printf("ft_strcmp : %d\n", ft_cmp);

    printf("\n---------- "SUBTITLE"Test second string greater"RESET" ----------\n");
    cmp = strcmp(s1, s4);
    ft_cmp = ft_strcmp(s1, s4);
    printf("('%s', '%s') :\n", s1, s4);
    printf("strcmp : %d\n", cmp);
    printf("ft_strcmp : %d\n", ft_cmp);

    printf("\n---------- "SUBTITLE"Test first string greater"RESET" ----------\n");
    cmp = strcmp(s4, s1);
    ft_cmp = ft_strcmp(s4, s1);
    printf("('%s', '%s') :\n", s4, s1);
    printf("strcmp : %d\n", cmp);
    printf("ft_strcmp : %d\n", ft_cmp);
}

void write_test(void)
{
    int back = 0;

    printf("---------- "SUBTITLE"Test on fd 1"RESET" ----------\n");
    printf("(1, 'this is a test\\n', 15) :\n");
    back = write(1, "this is a test\n", 15);
    printf("write : %d\n\n", back);
    back = ft_write(1, "this is a test\n", 15);
    printf("ft_write : %d\n", back);

    printf("\n---------- "SUBTITLE"Test bad fd -1"RESET" ----------\n");

    printf("(-1, 'this is a test\\n', 15) :\n");
    back = write(-1, "this is a test\n", 15);
    printf("write : %d, errno : %d\n", back, errno);
    errno = 0;
    
    back = ft_write(-1, "this is a test\n", 15);
    printf("ft_write : %d, errno : %d\n", back, errno);
}

void read_test(void)
{
    int fd = open("./read_test", O_CREAT);
    char buff[4];
    int back = 0;

    printf("---------- "SUBTITLE"Test read file"RESET" ----------\n");

    printf("(%d, buff, 3) :\n", fd);
    printf("read :\n");
    while ((back = read(fd, buff, 3)) > 0)
    {
        buff[back] = 0;
        printf("buffer : '%s', byte readed : %d\n", buff, back);
    }
    close(fd);
    fd = open("./read_test", O_CREAT);


    printf("\nft_read :\n");
    while ((back = ft_read(fd, buff, 3)) > 0)
    {
        buff[back] = 0;
        printf("buffer : '%s', byte readed : %d\n", buff, back);
    }
    
    close(fd);

    printf("\n---------- "SUBTITLE"Test bad fd"RESET" ----------\n");

    printf("(-1, buff, 3) :\n");
    back = read(-1, buff, 3);
    printf("read : %d, errno : %d\n", back, errno);
    errno = 0;
    back = ft_read(-1, buff, 3);
    printf("ft_read : %d, errno : %d\n", back, errno);
}

void strdup_test(void)
{
    char *duplicated;

    printf("---------- "SUBTITLE"Test empty copy"RESET" ----------\n");
    printf("('') :\n");
    duplicated = strdup("");
    if (!duplicated)
        errorAlloc();
    printf("strdup : '%s'\n", duplicated);
    free(duplicated);
    duplicated = NULL;

    duplicated = ft_strdup("");
    if (!duplicated)
        errorAlloc();
    printf("ft_strdup : '%s'\n", duplicated);
    free(duplicated);
    duplicated = NULL;


    printf("\n---------- "SUBTITLE"Test copy"RESET" ----------\n");
    printf("('Hey, this is my msg') :\n");
    duplicated = strdup("Hey, this is my msg");
    if (!duplicated)
        errorAlloc();
    printf("strdup : '%s'\n", duplicated);
    free(duplicated);
    duplicated = NULL;

    duplicated = ft_strdup("Hey, this is my msg");
    if (!duplicated)
        errorAlloc();
    printf("ft_strdup : '%s'\n", duplicated);
    free(duplicated);
    duplicated = NULL;
}

void waitUserKeyPress() {
    printf("\033[999;1HPress enter to see next");
    getchar();
    printf("\033[2J\033[H");
}

int main(void)
{
    printf("\033[2J\033[H");

    printHeader("Test of ft_strlen");
	strlen_test();
    waitUserKeyPress();

    printHeader("Test of ft_strcpy");
    strcpy_test();
    waitUserKeyPress();

    printHeader("Test of ft_strcmp");
    strcmp_test();
    waitUserKeyPress();

    printHeader("Test of ft_write");
    write_test();
    waitUserKeyPress();

    printHeader("Test of ft_read");
    read_test();
    waitUserKeyPress();

    printHeader("Test of ft_strdup");
    strdup_test();
    return (0);
}
