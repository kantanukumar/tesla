/*
 * This is a template to create the daily challenge.
 * Need to put the day name, date and problem in below format.
 *
 * Day: 7
 * Date: 13/07/23
 * Problem: Create a circular queue and do queue operations.
 * Approach: Use global queue.
 * Files: d7_queue.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Q_SIZE 6

int Q[Q_SIZE];
int FRONT = -1;
int REAR  = -1;

void enQ(int data)
{
  // Enqueue should check full
  // if(REAR == Q_SIZE-1)
  if(((REAR+1) % Q_SIZE) == FRONT)
    printf("Error: Q FULL\n");
  else
  {
    // first element to enQ
    if(FRONT == -1 && REAR == -1)
    {
      FRONT = 0;
      REAR = 0;
    }
    else
      REAR = (REAR+1) % Q_SIZE;

    Q[REAR] = data;
    printf("EnQed %d to Q rear %d\n", data, REAR);
  }
}

int deQ()
{
  int val = 0;
  // Dequeue should check empty
  if(FRONT == -1)
  {
    printf("Error: Q EMPTY\n");
    return -1;
  }
  else
  {
    val = Q[FRONT];
    printf("DeQed %d from Q front %d\n", val, FRONT);

    // Q became empty, initialize it to defaults
    if(FRONT == REAR)
    {
      FRONT = -1;
      REAR = -1;
    }
    else
      FRONT = (FRONT+1) % Q_SIZE;

    return val;
  }
}

void display()
{
  printf("FRONT=%d, REAR=%d\n", FRONT, REAR);
  
  if(FRONT == -1 && REAR == -1)
    printf("Empty Q\n");
  else
  {
    if(FRONT <= REAR)
      for(int i = FRONT; i <= REAR; i++)
        printf("Q[%d]=%d ", i, Q[i]);
    else
    {
      for(int i = FRONT; i < Q_SIZE; i++)
        printf("Q[%d]=%d ", i, Q[i]);
      for(int i = 0; i < REAR; i++)
        printf("Q[%d]=%d ", i, Q[i]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  // Function body
  /*
   * Usage: ./a.out "E"/"D"/"P" <element>
   */

  if(argc > 1)
  {
    printf("Passed more than one argument, process it\n\n");
  
    if(argc == 3)
    {
      if(0 == strcmp("E", argv[1]))
      {
        enQ(atoi(argv[2]));
        display();
        enQ(2);
        display();
        enQ(3);
        display();
        enQ(4);
        display();
        enQ(5);
        display();
        enQ(6);
        display();
        enQ(7);
        display();
        enQ(8);
        display();
        deQ();
        display();
      }
    }
    else if(argc == 2)
      if(strcmp("D", argv[1]))
        deQ();
    else
      display();
  }
  else
  {
    printf("Usage: ./a.out \"E\"/\"D\"/\"P\" <element>\n");
    display();
  }

  printf("\nEnd of the program\n");

  return 0;
}
