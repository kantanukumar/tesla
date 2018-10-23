void func(int x)
{
	printf("In func\n");
}
int main(int argc, char** argv)
{
  int x = 1;
	int *p; float bigArray[10];
	printf("Simple main\n");

	func(x);
}
