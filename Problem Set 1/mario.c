#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
      n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Add space between # and \n in the end of each loop
    for (int i = 0; i < n; i++)
    {

      for (int w = n - 1; w > i; w--) // Creates the space before #
      {
        printf(" ");
      }

      for (int j = n -i - 1; j < n; j++) //Creates the piramid
      {
        printf("#");
      }

      printf("  "); //Space between piramid

      for (int j = n - i - 1; j < n; j++) //Creates other part of piramid
      {
        printf("#");
      }

      printf("\n"); //New line
    }
}