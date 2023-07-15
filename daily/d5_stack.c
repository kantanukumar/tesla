/*
 * Day: 5
 * Date: 11/07/23
 * Problem: Create a stack using array.
 * Approach: Use global array.
 * Files: d5_stack.c
 */

/*
 * stack uses push, pop, peak functions.
 */

#include <stdio.h>
#include <stdlib.h>

// Insert only on TOP
void push(int value);

// Remove only from TOP
int pop(void);

// Just look at the TOP value
int peak();

#define STACK_SIZE 10

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

int peak()
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
    printf("Error: Stack Empty\n");
  else
  {
    for(int i = TOP; i >= 0; i--)
    {
      // Just for fun display
      printf("|%d| <---%d\n", stack[i], i);
      printf("----\n");
    }
  }
}


int main(int argc, char *argv[])
{
  // Function body
  if(argc > 1)
  {
    printf("Passed more than one argument, process it\n\n");
   
    // Only Push() needs elements
    
    int idx = 1;
    int data = 0;

    while(argc != 1)
    {   
      data = atoi(argv[idx]);
      push(data);
      ++idx; --argc;
    }   
  }
  display();

  printf("Popped %d from stack, now the stack looks: \n", pop());
  display();

  printf("Popped %d from stack, now the stack looks: \n", pop());
  display();
  
  printf("Popped %d from stack, now the stack looks: \n", pop());
  display();
  
  printf("Peak |%d| <--%d at stack\n", peak(), TOP);
  display();

  printf("\nEnd of the program\n");

  return 0;
}
