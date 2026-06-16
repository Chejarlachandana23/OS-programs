#include<stdio.h>
int main(){
	int f[50],i,j,start,len;
	for(i=0;i<50;i++)
		f[i]=0;
	printf("enter starting block:");
	scanf("%d",&start);
	printf("enter length of file:");
	scanf("%d",&len);
	for(i=start;i<start+len;i++){
		if(f[i]==1){
			printf("Allocation not possible\n");
			return 0;
		}
	}
	for(i=start;i<start+len;i++)
		f[i]=1;
	printf("\nfile allocated successfully\n");
	printf("allocated blocks are:\n");
	for(i=start;i<start+len;i++)
		printf("%d",i);
	return 0;
	}

