
#include<stdio.h>
int main()
{
	int n,i,j,smallest,count=0,time;
	int at[10],bt[10],ct[10],tat[10],wt[10],p[10];
	int temp_bt[10];
	float avgwt=0,avgtat=0;
	printf("enter number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter AT and BT of  p %d:",i+1);
		scanf("%d %d",&at[i],&bt[i]);
		p[i]=i+1;
		temp_bt[i]=bt[i];
    }
		time=0;
		while(count<n){
			smallest=-1;
			for(i=0;i<n;i++){
			if(at[i]<=time&&temp_bt[i]>0){
				if(smallest==-1||temp_bt[i]<temp_bt[smallest])
				smallest=i;
			}		
		}
		if(smallest==-1){
			time++;
		}
		else{
			time+=temp_bt[smallest];
			ct[smallest]=time;
			temp_bt[smallest]=0;
			count++;
		}
		}
		printf("\np\tAT\tBT\tCT\tTAT\tWT\n");
		for(i=0;i<n;i++){
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			avgwt+=wt[i];
			avgtat+=tat[i];
			printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
		}
		printf("\n Average TAT=%.2f",avgtat/n);
		printf("\n Average WT=%.2f",avgwt/n);
		return 0;
	}
