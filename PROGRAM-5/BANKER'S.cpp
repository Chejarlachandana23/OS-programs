#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	printf("Enter Number Of Processes:");
	scanf("%d",&n);
	printf("enter the no.of resources types:");
	scanf("%d",&m);
	int alloc[n][m],max[n][m],need[n][m];
	int avail[m];
	printf("\n enter allocation matrix:\n");
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	   scanf("%d",&alloc[i][j]);
	printf("\n enter max matrix:\n");
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	    scanf("%d",&max[i][j]);
	printf("\n enter availabe resources:\n");
	for(j=0;j<m;j++)
	   scanf("%d",&avail[j]);
	for(i=0;i<n;i++)
     	for(j=0;j<m;j++)
	    need[i][j]=max[i][j]-alloc[i][j];
	    int finish[n];
	    int safeseq[n];
	    int work[m];
	for(i=0;i<n;i++)
	   finish[i]=0;
	for(i=0;i<m;i++)
	   work[i]=avail[i];
	int count=0;
	while(count<n){
		int found=0;
		for(i=0;i<n;i++){
			if(finish[i]==0){
				int possible=1;
		for(j=0;j<m;j++){
			if(need[i][j]>work[j]){
				possible=0;
			break;
		}
	}
	if(possible){
		for(k=0;k<m;k++)
		   work[k]+=alloc[i][k];
		   safeseq[count++]=i;
		   finish[i]=1;
		   found=1;
	     } 
       } 
     }
    if(found==0){
	printf("\n system is not in safe state('deadlock possible')\n");
	return 0;
    }
  }
    printf("\n system is in safe state.\nsafe sequence:\n");
    for(i=0;i<n;i++)
    printf("p%d->",safeseq[i]);
    printf("\n");
    return 0;
}
