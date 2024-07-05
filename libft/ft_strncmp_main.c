#include "colors.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void  ft_putchar(char c)
{
  write(1, &c, 1);
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
    char *test_cases_s1[] = {
        "Hello, world!",
        "12345",
        "abcdef",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
        "abc",
    };

    char *test_cases_s2[] = {
        "Hello, world!",
        "12345",
        "abcdef",
        "abc",
        "abcd",
        "ab",
        "abcdef",
        "abcdef",
        "abcde",
        "ab",
        "abc",
        "abcd",
        "abcdefgh",
        "abcdef",
        "abcd",
        "abcdefgh",
        "abcdef",
    };

    int test_cases_n[] = {
        50,
        5,
        6,
        2,
        3,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
    };

    int tests_passed = 0;
    int tests_failed = 0;
    int num_tests = sizeof(test_cases_s1) / sizeof(test_cases_s1[0]);
    int i = 0;

    printf("Testing ft_strncmp function against strncmp...\n");

    while (i < num_tests)
    {
        const char *s1 = test_cases_s1[i];
        const char *s2 = test_cases_s2[i];
        size_t n = test_cases_n[i];

        // Using ft_strncmp
        int result_ft = ft_strncmp(s1, s2, n);
        // Using strncmp from <string.h>
        int result_std = strncmp(s1, s2, n);

        if (result_ft == result_std)
        {
            printf(ANSI_COLOR_GREEN "Test %d Passed: ft_strncmp(\"%s\", \"%s\", %zu) returned %d\n" ANSI_COLOR_RESET,
                   i + 1, s1, s2, n, result_ft);
            tests_passed++;
        }
        else
        {
            printf(ANSI_COLOR_RED "Test %d Failed: ft_strncmp(\"%s\", \"%s\", %zu) returned %d, expected %d\n" ANSI_COLOR_RESET,
                   i + 1, s1, s2, n, result_ft, result_std);
            tests_failed++;
        }

        i++;
    }

    printf("Summary:\n");
    printf(ANSI_COLOR_YELLOW "Tests passed: %d\n" ANSI_COLOR_RESET, tests_passed);
    printf(ANSI_COLOR_YELLOW "Tests failed: %d\n" ANSI_COLOR_RESET, tests_failed);

    return 0;
}
