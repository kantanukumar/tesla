#if 0
#include <stdio.h>

void func(int x)
{

}

int main()
{
  int x;

  func(x);
  return 0;
}
#endif


#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* Obtain a backtrace and print it to stdout. */
void
print_trace (void)
{
  void *array[100];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 100);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf ("%s\n", strings[i]);

  free (strings);
}

/* A dummy function to make the backtrace more interesting. */
void
dummy_function (void)
{
  kill(getpid(), SIGSEGV);
  print_trace ();
}

int
main (void)
{
  dummy_function ();
  return 0;
}
