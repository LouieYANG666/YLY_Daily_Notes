#include <stdio.h>


void transfer_matrix(int *a, int k)
{
	int i, j;
	
	for(i=0; i<k; i++)
		for(j=0; j<k; j++)
		{
			*(a + i*k + j) = 99;
		}


	
}



int main()
{
	int a[3][3];
	int i, j;

	for (i=0; i<3;i ++)
		for(j=0; j<3; j++)
		{
			a[i][j] = i*j;
		}

	transfer_matrix(*a, 3);
	
	
	for (i=0; i<3;i ++)
		for(j=0; j<3; j++)
		{
			printf("%d, ", a[i][j]);
		}
	printf("\n");


	return 0;
}
