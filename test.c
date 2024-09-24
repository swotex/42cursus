#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Déclaration de la fonction ASM
extern char *_ft_strdup(const char *s);

void main(void)
{
	// char *test_str = malloc(4);
    char *test = NULL;
    test = _ft_strdup("t");
    printf("the back is '%s'", test);
    free(test);
}
