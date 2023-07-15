/*
 * Day: 9
 * Date: 15/07/23
 * Problem: Create a queue using two stacks.
 * Approach: Use global array.
 * Files: d9_Q_using_stack.c
 */

/*
 * We need to use two stacks, stack1 and stack2.
 * Stack1 will be used to enqueue and stack2 for dequeue.
 * Enqueue is pushing to stack1 and dequeue is popping from stack2.
 *    If stack2 is not empty, 
 *        pop from stack2 to get the first element.
 *    If stack2 is empty, 
 *        then pop all elements from stack1, 
 *        push to stack2,
 *        pop from stack2.
 *
 * operations on respective stacks are labelled with push1(), push2() etc.
 */

#include <stdio.h>
#include <stdlib.h>

// Insert only on TOP
void push1(int value);
void push2(int value);

// Remove only from TOP
int pop1(void);
int pop2(void);

#define STACK_SIZE 10

// Global stacks
int stack1[STACK_SIZE]; 
int stack2[STACK_SIZE]; 

// Initialize the stacks
int TOP1 = -1; 
int TOP2 = -1; 

void push1(int value)
{
  if(TOP1 == STACK_SIZE - 1)
    printf("Error: Queue overflow\n");
  else
  {
    ++TOP1;
    stack1[TOP1] = value;
  }
}

void push2(int value)
{
  // This condition should never happen
  // We should assert, on this.
  if(TOP2 == STACK_SIZE - 1)
    printf("Error: Queue overflow\n");
  else
  {
    ++TOP2;
    stack2[TOP2] = value;
  }
}

int pop1()
{
  int value = 0;
 
  // This condition should never happen
  // We should assert, on this.
  if(TOP1 == -1)
    printf("Error: Queue underflow\n");
  else
  {
    value = stack1[TOP1];
    --TOP1;
  }
  return value;
}

int pop2()
{
  int value = 0;
 
  // This condition should never happen
  // We should assert, on this.
  if(TOP2 == -1)
    printf("Error: Queue underflow\n");
  else
  {
    value = stack2[TOP2];
    --TOP2;
  }

  return value;
}

// let's define the actual Queue functions.
// Enqueue()

void enQ(int data)
{
  // Just push to stack1, push1 takes care about overflow.
  push1(data);
  printf("EnQed %d\n", data);
}

int deQ()
{
  int val = 0;

  if(TOP1 == -1)
  {
    if(TOP2 == -1)
      printf("Queue is empty");
    else
      val = pop2(); // Pop from stack2
  }
  else
  {
    // Keep move stack1 into stack2
    // keep popping until stack1 becomes empty,
    // pop from stack2.
    while(TOP1 != -1)
    {
      int temp = pop1();
      push2(temp);
    }
    val = pop2();
  }

  printf("DeQed %d\n", val);
  return val;
}

void display()
{
  if(TOP1 == -1 && TOP2 == -1)
    printf("Error: Queue Empty\n");
  else
  {
    // Printing is interesting.
    // We need to print stack1 and stack2
    // stack2: from TOP2 - 0
    // stack1: from 0 - TOP1

    printf("<==");
    for(int i = TOP2; i >= 0; i--)
    {
      // Just for fun display
      printf("%d<==", stack2[i]);
    }
    for(int i = 0; i <= TOP1; i++)
    {
      // Just for fun display
      printf("%d<==", stack1[i]);
    }
    printf("\n");
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
      enQ(data);
      ++idx; --argc;
    }   
  }
  display();

  printf("Popped %d from stack, now the stack looks: \n", deQ());
  display();

  printf("Popped %d from stack, now the stack looks: \n", deQ());
  display();
  
  printf("Popped %d from stack, now the stack looks: \n", deQ());
  display();
  
  printf("\nEnd of the program\n");

  return 0;
}
