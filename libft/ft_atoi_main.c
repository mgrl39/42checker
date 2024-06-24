#include "colors.h"

int  ft_atoi(const char *nptr);

// Implementation of ft_putchar
void  ft_putchar(char c)
{
  write(1, &c, 1);
}

// Implementation of ft_putstr
void  ft_putstr(char *str)
{
  int  i;

  i = 0;
  while (str[i] != '\0')
    {
      write(1, &str[i], 1);
      i++;
    }
}

// Implementation of ft_putnbr
void  ft_putnbr(int nb)
{
  if (nb == -2147483648)
  {
    write(1, "-2147483648", 11);
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

// main
int  main(void)
{
  char *test_cases[] = {
          "12345",
        "-54321",
        "0",
        "   456",
        "+789",
        "    -987",
        "123abc",
        "abc123",
        "++2",
        "-4",
        "--54a",
        "              -2.3",
        "     ",
        "   123abc",
        "   abc123",
        "-2147483648",
        "2147483647",
        NULL
  }
  int tests_passed = 0;
  int tests_failed = 0;
  int i = 0;

  ft_putstr("Testing ft_atoi function...\n");

  while (test_cases[i] != NULL)
    {
      int result = ft_atoi(test_cases[i]);
      int expected = atoi(test_cases[i]); // Using standard library atoi as reference

      if (result == expected)
      {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_atoi(\"");
        ft_putstr(test_cases[i]);
        ft_putstr("\") returned ");
        ft_putnbr(result);
        ft_putstr(ANSI_COLOR_RESET "\n");
        tests_passed++;
      }
      else
      {
        ft_putstr(ANSI_COLOR_RED "Error: ft_atoi(\"");
        ft_putstr(test_cases[i]);
        ft_putstr("\") returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
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

  return (0);
}
