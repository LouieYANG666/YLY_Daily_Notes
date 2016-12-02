#include<stdio.h>
#include<string.h>

char * fun1()
{
	char* s[3] = {"asdf", "xcvzxv", "werwer"};
	return s[0];
}

int main()
{
	char *p = NULL;
	p = fun1();
	printf("%s", p);
	return 0;
}
