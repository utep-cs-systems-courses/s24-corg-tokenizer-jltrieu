# include <stdio.h>

int main()
{
  printf("> ");
  // echo input normally
  char input[100];
  scanf("%99s", input);
  printf("%s\n", input);
}
