# include <stdio.h>

int main()
{
  printf("> ");
  // echo input normally
  char input[100];
  fgets(input, 100, stdin);
  printf("%s\n", input);
}
