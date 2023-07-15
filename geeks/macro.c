#define max 0
#define INCR(x) ++x
#define merge(a, b) a##b
#define get(a) #a

#define A -B
#define B +C
#define C 5

int main()
{
  int *ptr = "GeeksFor";
  printf("Increment ptr = %s\n", INCR(ptr));
  printf("%d\n", merge(12,34));
  printf("get=%s\n", get(kantanu));

  printf("The value of A is %d\n", A);

   printf("Current File :%s\n", __FILE__ ); 
   printf("Current Date :%s\n", __DATE__ ); 
   printf("Current Time :%s\n", __TIME__ ); 
   printf("Line Number :%d\n", __LINE__ ); 

#if max
  printf("max=%d\n", max);
#endif

}
