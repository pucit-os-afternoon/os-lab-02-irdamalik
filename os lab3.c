#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
int i=0;
int arr1[3][3];
int arr2[3][3];
int r[3][3];
void * multiplyer(void * arg)
{
	printf("executing thread # %d\n", i++ );

int sum=0;
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
{
	for(int k=0;k<3;k++)
		sum=sum+arr1[i][k]*arr2[k][j];
	r[i][j]=sum;
	sum=0;
}
}
int main()
{
	
	
	FILE *file1=fopen("sample_textfile1.txt", "r");
	FILE * file2=fopen("sample_textfile2.txt", "r");
if(file1==NULL)
	printf("Error File opening!\n");
else if(file2==NULL)
	printf("Error File opening!\n");
else
{
    for (int i = 0; i <  3; i++) 
     for (int j = 0; j < 3; j++)
	fscanf(file1, "%d", &arr1[i][j]);
  for (int i = 0; i <  3; i++) 
     for (int j = 0; j < 3; j++)
	fscanf(file2, "%d", &arr2[i][j]);
	
fclose(file1);
fclose(file2);

pthread_t t[3];
for(int i=0;i<3;i++)
pthread_create(&t[i], NULL, multiplyer, NULL);
for(int i=0;i<3;i++)
 pthread_join(t[i], NULL);
FILE * re=fopen("matrix.txt", "w");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				fprintf(re,"%d ", r[i][j]);
			fprintf(re,"\n");
		}
		fclose(re);
for (int i = 0; i <  3; i++) 
{
     for (int j = 0; j < 3; j++)
	printf("%d\t", r[i][j]);
printf("\n");
}

}
printf("\nmain is ended \n");
   return 0;
}

