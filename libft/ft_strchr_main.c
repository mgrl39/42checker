#include "colors.h"

char	*ft_strchr(const char *s, int c);

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void  ft_putstr(char *str)
{
  int  i;

  i = 0;
  while (str[i] != '\0')
    {
      ft_putchar(str[i]);
      i++;
    }
}

void  ft_putnbr(int nb)
{
  if (nb == -2147483648)
  {
    ft_putstr("-2147483648");
    return ;
  }
  if (nb < 0)
  {
    ft_putchar('-');
    nb = -nb;
  }
  if (nb >= 10)
  {
    ft_putnbr(nb / 10);
  }
  ft_putchar(nb % 10 + '0');
}

void  print_memory(void *mem, size_t size)
{
  unsigned char *ptr;
  size_t  i;

  ptr = (unsigned char *)mem;
  i = 0;
  while (i < size)
    {
      if (ptr[i] >= 32 && ptr[i] <= 126) // Printable characters
        ft_putchar(ptr[i]);
      else
        ft_putchar('.');
      i++;
    }
  ft_putstr("\n");
}

int main(void)
{
    char *test_cases[] = {
        "Hello, world!",
        "1234567890",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "!@#$%^&*()_+",
        "",
        "\0Hidden",
        "The quick brown fox jumps over the lazy dog",
        NULL
    };

    int test_chars[] = {
        'H', 'o', 'e', 'x', 'A', '\0', 'd', '5', '!', 'F'
    };

    int tests_passed = 0;
    int tests_failed = 0;

    printf("Testing ft_strchr function against strchr...\n");

    // Iterate through test cases
    int i = 0;
    while (test_cases[i] != NULL) {
        int j = 0;
        while ((size_t)j < sizeof(test_chars) / sizeof(test_chars[0])) {
            int c = test_chars[j];

            // Using ft_strchr
            char *result_ft = ft_strchr(test_cases[i], c);
            // Using strchr from <string.h>
            char *result_std = strchr(test_cases[i], c);

            if (result_ft == result_std) {
                printf(ANSI_COLOR_GREEN "Test Passed: ft_strchr(\"%s\", '%c') returned %p, expected %p\n" ANSI_COLOR_RESET,
                       test_cases[i], c, result_ft, result_std);
                tests_passed++;
            } else {
                printf(ANSI_COLOR_RED "Test Failed: ft_strchr(\"%s\", '%c') returned %p, expected %p\n" ANSI_COLOR_RESET,
                       test_cases[i], c, result_ft, result_std);
                tests_failed++;
            }

            j++;
        }
        i++;
    }

    printf("Summary:\n");
    printf(ANSI_COLOR_YELLOW "Tests passed: %d\n" ANSI_COLOR_RESET, tests_passed);
    printf(ANSI_COLOR_YELLOW "Tests failed: %d\n" ANSI_COLOR_RESET, tests_failed);

    return 0;
}
