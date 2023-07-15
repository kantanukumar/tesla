/*
 * Day: 9
 * Date: 15/07/23
 * Problem: Create a linked list and reverse it.
 * Approach: Use global head to create a list.
 * Files: d9_2_string_reverse.c
 */

/*
 * I have to reverse a given string in following ways.
 *
 * IN:   "Hello World How Are You"
 * 
 * OUT1: "uoY erA woH dlroW olleH"
 * OUT2: "olleH dlroW woH erA uoY"
 * OUT3: "You Are How World Hello"
 *
 */

#include <stdio.h>
#include <string.h>

// Just reverse whole string
void my_str_rev(char *s)
{
  int len = strlen(s);

  for(int i = 0; i < len/2; i++)
  {
    char temp = '\0';
    temp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = temp;
  }
  // printf("Rev: %s\n", s);
}

// Reverse the word
// Note: Above function also does the same, but without len param
void my_word_rev(char *start, int word_len)
{
  for(int i = 0; i < word_len/2; i++)
  {
    char temp = start[i];
    start[i] = start[word_len-i-1];
    start[word_len-i-1] = temp;
  }
  // printf("Rev word: %s\n", start);
}

// Reverse each words 
void my_rev_words(char *s)
{
  char *start = s;
  int word_len = 0;
  int i = 0;

  while(s[i])
  {
    word_len++;

    if((s[i] == ' ') && (s[i+1] != ' '))
    {
      my_word_rev(start, word_len-1);
      // Reset the start
      start = &s[i]+1;
      word_len = 0;
    }
    i++;
  }
  // We reached end of string, so just reverse the last word
  my_word_rev(start, word_len);
      
  // printf("Rev words: %s\n", s);
}

int main(int argc, char *argv[])
{
  // Function body

  char arr[] = "Hello World   How Are You";
  printf("IN: %s\n", arr);

  // OUT1
  // my_str_rev(arr);
  my_word_rev(arr, strlen(arr)); // Can also done by above function as stand alone
  printf("OUT1: %s\n", arr);

  // Reverse the string to bring it to original state
  my_str_rev(arr);

  // OUT2
  my_rev_words(arr);
  printf("OUT2: %s\n", arr);

  // OUT3
  my_str_rev(arr);
  printf("OUT3: %s\n", arr);

  printf("\nEnd of the program\n");

  return 0;
}
