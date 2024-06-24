#include "colors.h"

void  *ft_memset(void *s, int c, size_t n);

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
  if (nb == "-2147483648", 11);
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

int  main(void)
{
  char test_cases[][50] = {
  "Hello, world!",
  "1234567890",
  "abcdefghijklmnopqrstuvwxyz",
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "!@#$%^&*()_+",
  "",
  "\0Hidden",
  "The quick brown fox jumps over the lazy dog",
  };

  size_t test_sizes[] = {5, 10,0,7,8,1,6,20};
  int test_cases_count = sizeof(test_cases) / sizeof(test_cases[0]);
  int tests_passed = 0;
  int tests_failed = 0;
  int i = 0;

  ft_putstr("Testing ft_memset function...\n");

  while (i < test_cases_count)
    {
      char test1[50] = {0};
      char test2[50] = {0};
      strcpy(test1, test_cases[i]);
      strcpy(test2, test_cases[i]);
      size_t n = test_sizes[i];
      int c = '*';

      // Use ft_memset
      ft_memset(test1, c, n);
      // use standard memset
      memset(test2, c, n);

      // Compare results
      ft_putstr("Custom ft_memset result: ");
      print_memory(test1, sizeof(test1));
      ft_putstr("Standard memset result: ");
      print_memory(test2, sizeof(test2));

      // Check if results are equal
      if (memcmp(test1, test2, sizeof(test1)) == 0)
      {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_memset matches standard memset\n" ANSI_COLOR_RESET);
        tests_passed++;
      }
      else
      {
        ft_putstr(ANSI_COLOR_RED "Error: ft_memset does not match standard memset\n" ANSI_COLOR_RESET);
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
