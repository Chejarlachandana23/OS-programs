#include<stdio.h>

int main()
{
    int n,i,j;
    int p[10],at[10],bt[10],pr[10],ct[10],tat[10],wt[10],temp;
    float avgwt=0,avgtat=0;
    
    printf("enter number of processes:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("enter at, bt, and priority of p%d:",p[i]);
        // FIX 1: Added & before bt[i]
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
    }
    
    // Sort based on Priority, then arrival time for non-preemptive
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                temp=pr[i];pr[i]=pr[j];pr[j]=temp;
                temp=at[i];at[i]=at[j];at[j]=temp;
                temp=bt[i];bt[i]=bt[j];bt[j]=temp;
                temp=p[i];p[i]=p[j];p[j]=temp;
            }
        }
    }
    
    // Calculate Completion Time (Correcting for idle time)
    int current_time = 0;
    for(i=0;i<n;i++)
    {
        if(current_time < at[i])
            current_time = at[i];
            
        current_time += bt[i];
        ct[i] = current_time;
    }
    
    // Calculate TAT and WT
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    
    printf("\np\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    
    printf("\n Average TAT=%.2f",avgtat/n);
    printf("\n Average WT=%.2f",avgwt/n);
    return 0;
}

