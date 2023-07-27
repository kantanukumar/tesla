Create Library process:

Static Library:
===============
1. Create .o files:

gcc -c file1.c
gcc -c file2.c

2. Create static library

ar rs libstatic_cal.a file1.o file2.o
Note: The name after "lib" is the library name, so be careful with characters after lib.
ar: creating libstatic_cal.a

3. Link with library and create executable

gcc main.o -o calc -L . -lstatic_cal

4. Run executable:
./calc
