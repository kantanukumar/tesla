int main()
{
  static unsigned char lock = 0;

  if(lock < 5)
  {
    printf("lock=%d\n", lock);
    lock++;
  }
  else
  {
    return 0; //exit recursion
  }

  main();

  return 0;
}
