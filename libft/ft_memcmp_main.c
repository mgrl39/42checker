#include "colors.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n);

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
    char *test_cases1[] = {
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

    char *test_cases2[] = {
        "Hello, world!",
        "0987654321",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "!@#$%^&*()_+",
        "",
        "\0Hidden",
        "The quick brown fox jumps over the lazy dog.",
        NULL
    };

    size_t test_sizes[] = {5, 10, 0, 7, 8, 1, 6, 20};
    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_memcmp function...\n");

    while (test_cases1[i] != NULL && test_cases2[i] != NULL)
    {
        size_t n = test_sizes[i];

        // Use ft_memcmp
        int result = ft_memcmp(test_cases1[i], test_cases2[i], n);
        // use standard memcmp
        int expected = memcmp(test_cases1[i], test_cases2[i], n);

        // Print the memory for visualization
        ft_putstr("Comparing: \n");
        print_memory(test_cases1[i], n);
        ft_putstr("and\n");
        print_memory(test_cases2[i], n);

        // Check if results are equal
        if (result == expected)
        {
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_memcmp matches standard memcmp\n" ANSI_COLOR_RESET);
            tests_passed++;
        }
        else
        {
            ft_putstr(ANSI_COLOR_RED "Error: ft_memcmp does not match standard memcmp\n" ANSI_COLOR_RESET);
            tests_failed++;
        }

        i++;
    }

    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return 0;
}
