#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h" // Asumiendo que este archivo contiene la declaración de ft_substr
#include "colors.h" // Definición de colores ANSI para mejor visualización

#ifndef mg_substr
#define mg_substr
char	*mg_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
#endif

char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
    size_t	i = 0;
    while (str[i])
        i++;
    return (i);
}

// Función para imprimir una cadena
void print_string(const char *label, const char *str)
{
    printf("%s: \"%s\"\n", label, str);
}

// Función para imprimir el resultado de ft_substr
void test_substr(const char *s, unsigned int start, size_t len, int *tests_passed, int *tests_failed)
{
	char *result = ft_substr(s, start, len);
	char *expected = mg_substr(s, start, len);
	
    if (strcmp(result, expected) == 0)
    {
        print_string("Original", s);
        printf("Start: %u, Length: %zu\n", start, len);
        print_string("Substring", result);
        free(result); // Liberar memoria asignada por ft_substr
        printf(ANSI_COLOR_GREEN "Test Passed: ft_substr(\"%s\", %u, %zu)\n" ANSI_COLOR_RESET, s, start, len);
        (*tests_passed)++;
    }
    else
    {
        printf(ANSI_COLOR_RED "Test Failed: ft_substr(\"%s\", %u, %zu) returned NULL\n" ANSI_COLOR_RESET, s, start, len);
        (*tests_failed)++;
    }
    printf("\n");
}

int main(void)
{
    const char *s = "Hello, World!";
    unsigned int start;
    size_t len;
    int tests_passed = 0;
    int tests_failed = 0;

    printf("Testing ft_substr function...\n\n");

    // Casos normales
    start = 0;
    len = 5;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 7;
    len = 6;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    // Casos especiales
    start = 15; // Más allá de la longitud de s
    len = 5;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 7;
    len = 20; // Longitud mayor que la parte restante de s desde start
    test_substr(s, start, len, &tests_passed, &tests_failed);

    // Casos de borde y situaciones especiales
    start = 0;
    len = 0;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 6;
    len = 0;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 15; // Más allá de la longitud de s
    len = 0;
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 0;
    len = 100; // Longitud mayor que la longitud total de s
    test_substr(s, start, len, &tests_passed, &tests_failed);

    start = 7;
    len = 5; // Parte intermedia de s
    test_substr(s, start, len, &tests_passed, &tests_failed);

    // Resumen final
    printf(ANSI_COLOR_YELLOW "\nSummary:\n");
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n" ANSI_COLOR_RESET, tests_failed);

    return 0;
}
