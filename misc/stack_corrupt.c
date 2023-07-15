#include<stdio.h>

int main(int argc, char *argv[])
{
    int flag = 0;
    char passwd[10] = {0};
		int h1;
		int h2;
		int h3;
		int h4;

    memset(passwd, '1', 20);//sizeof(passwd));

		printf("Address of flag=%p, passwd=%p\n", &flag, passwd);

		printf("argv[1] = %s\n", argv[1]);

		printf("h1=%p, h2=%p, h3=%p, h4=%p\n", &h1, &h2, &h3, &h4);

		printf("passwd=%s\n", passwd);
#if 1
    strcpy(passwd, argv[1]);
		printf("passwd after copy=%s\n", passwd);

    if(0 == strcmp("LinuxGeek", passwd))
    {
        flag = 1;
    }
#endif

    if(flag)
    {
        printf("\n Password cracked \n");
    }
    else
    {
        printf("\n Incorrect passwd \n");
    }
    return 0;
}
