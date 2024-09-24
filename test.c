#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Déclaration des fonctions ASM
extern char *ft_strdup(const char *s);

int main(void)
{
	// char *test_str = malloc(4);
    char *test = NULL;
    test = ft_strdup("tt");
    if (!test)
        printf("error");
    printf("the back is '%s'", test);
    free(test);
    return (0);
}
