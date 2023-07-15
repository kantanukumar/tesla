/*
 * Day: 5
 * Date: 11/07/23
 * Problem: Check balanced paranthesis using stack(array).
 * Approach: Use global array.
 * Files: d5_2_paranthesis_stack.c 
 */

/*
 * stack uses push, pop, peek functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insert only on TOP
void push(int value);

// Remove only from TOP
int pop(void);

// Just look at the TOP value
int peek();

#define STACK_SIZE 100

// Global stack
int stack[STACK_SIZE]; 

// Initialize the stack
int TOP = -1; 

void push(int value)
{
  if(TOP == STACK_SIZE - 1)
    printf("Error: Stack overflow\n");
  else
  {
    ++TOP;
    stack[TOP] = value;
  }
}

int pop()
{
  int value = 0;
  if(TOP == -1)
    printf("Error: Stack underflow\n");
  else
  {
    value = stack[TOP];
    --TOP;
  }
  return value;
}

int peek()
{
  int value = 0;
  if(TOP == -1)
    printf("Error: Stack underflow\n");
  else
  {
    value = stack[TOP];
  }
  return value;
}

void display()
{
  if(TOP == -1)
    printf("Stack Empty\n");
  else
  {
    for(int i = TOP; i >= 0; i--)
    {
      // Just for fun display
      printf("|%c| <---%d\n", stack[i], i);
      printf("---\n");
    }
  }
}


int main(int argc, char *argv[])
{
  // Function body
  if(argc != 2)
  {
    printf("This program needs the paranthesis string to be passed\n");
    printf("Usage: ./a.out \"expression string\"\n");
    return 0;
  }
    
  int i = 0;
  char arr[STACK_SIZE] = {'\0'};
  memcpy(arr, argv[1], strlen(argv[1]));

  printf("Input expression: ");
  for(i = 0; i < strlen(argv[1]); i++)
    printf("%c ", arr[i]);

  printf("\n");

  // Simple logic - If opening brace, push
  // If encountered a closing brace, peek the stack,
  // If we have matching, pop it.

  for(i = 0; i < strlen(arr); i++)
  {
    if((arr[i] == '{') || (arr[i] == '[') || (arr[i] == '('))
      push(arr[i]);
    else if((arr[i] == '}') && ('{' == peek()))
      pop();
    else if((arr[i] == ']') && ('[' == peek()))
      pop();
    else if((arr[i] == ')') && ('(' == peek()))
      pop();
    else
      continue;
  }

  display();
  
  if(TOP == -1)
    printf("\nStack Empty - Balanced paranthesis\n");
  else
    printf("\nStack Non-Empty - Non-Balanced paranthesis\n");

  printf("\nEnd of the program\n");

  return 0;
}
