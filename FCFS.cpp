#include<stdio.h>
int main()
{
	int n,i;
	int at[20],bt[20],ct[20],tat[20],wt[20];
	float avg_wt=0,avg_tat=0;
	printf("enter no.of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	  printf("process %d arrival time:",i+1);
	  scanf("%d",&at[i]);
	  printf("process %d Burst time:",i+1);
	  scanf("%d",&bt[i]);
    }
ct[0]=at[0]+bt[0];
for(i=0;i<n;i++)
{
	if(ct[i-1]<at[i])
	  ct[i]=at[i]+bt[i];
	else
	  ct[i]=ct[i-1]+bt[i];
}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		avg_tat+=tat[i];
		avg_wt+=wt[i];
    }
    avg_tat=avg_tat/n;
    avg_wt=avg_wt/n;
		printf("\np\tAT\tBT\tCT\tTAT\tWT\n");
		for(i=0;i<n;i++)
		{
			printf("p%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		}
		printf("\n Average TAT=%.2f",avg_tat/n);
		printf("\n Average WT=%.2f",avg_wt/n);
		return 0;
	}

