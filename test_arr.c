#include <stdio.h>

int main()
{
	int arr[3] = {0xff};
	arr = {1, 2, 3};
	printf("%d  %d  %d", arr[0], arr[1], arr[2]);
	return 0;
}
