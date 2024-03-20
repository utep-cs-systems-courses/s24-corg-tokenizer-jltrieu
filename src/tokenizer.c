#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

/* return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators aren't printable and return false. */
int space_char(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace char
   (not '\t' or ' ')
   Zero terminators aren't printable and return false. */
int non_space_char(char c)
{
  if(!space_char(c) && c != '\0'){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first char
   of the next space-separated token in zero-terminated string
   Return a zero pointer if str contains no tokens. */
char *token_start(char *str)
{
  while(*str){
    if(non_space_char(*str)){
      return str;
    }
    *str++;
  }
  // we exit out of the while loop if/when we hit a zero terminator
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  //if it's a whitespace or string terminator we consider that the terminator
  while(*token){
    if(space_char(*token)){
      return token;
    }
    *token++;
  }
  return token;
}

/* Returns the number of tokens in the string arg. */
int count_tokens(char *s)
{
  int count = 0;
  while(*(s = token_start(s))){
    count++;
    s = token_terminator(s);
  }
  return count;
}

/* Returns a freshly allocated zero-terminated string copy
   containing <len> chars of <inStr> */
char *copy_str(char *inStr, short len)
{
  char *outStr = (char *) malloc(len);
  char *outStrStart = outStr;
  for(int i = 0; i < len; i++){
    *outStr++ = *inStr++;
  }
  if(*outStr){
    *outStr = '\0';
  }
  return outStrStart;
}

/* returns a freshly allocated zero-terminated vector of
   freshly allocated space-separated tokens from a zero-terminated string */
char **tokenize(char *str)
{
  int count = count_tokens(str);
  char **tokens = malloc((count + 1) * 8);
  for(int i = 0; i < count; i++){
    str = token_start(str);
    int tlen = token_terminator(str) - str;
    tokens[i] = copy_str(str, tlen);
    str = token_terminator(str);
  }
  tokens[count] = '\0';
  return tokens;
}

/* prints all the tokens */
void print_tokens(char **tokens)
{
  //print every token in order until we hit the zero-terminator
  int i = 0;
  while(tokens[i]){
    printf("%s\n", tokens[i]);
    i++;
  }
}

/* free all tokens and the vector containing them */
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++; //am i stupid or what
  }
  free(tokens[i]); //free the last token
  free(tokens);
}
