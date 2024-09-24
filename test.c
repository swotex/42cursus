#include <stdio.h>
#include <stdlib.h>

// Déclaration de la fonction ASM
extern char *_ft_strcpy(const char *str, const char *str2);

void main(void)
{
	char *test_str = malloc(4);
    
    // Appel de la fonction assembleur
    test_str = _ft_strcpy(test_str, "qwe");

    // Affichage du résultat
    printf("Length of '%s'\n", test_str);
	free(test_str);
}
