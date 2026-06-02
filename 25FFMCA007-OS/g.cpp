#include <stdio.h>
int main() {                
    int n, i, j, smallest, count = 0, time = 0; 
    int at[10], bt[10], ct[10], tat[10], wt[10], p[10];                
    int temp_bt[10];                
    float avgwt = 0, avgtat = 0;                

    printf("enter number of processes:");                
    scanf("%d", &n);                

    for (i = 0; i < n; i++) {                
        printf("enter AT and BT of p %d:", i + 1);                
        scanf("%d%d", &at[i], &bt[i]);                
        p[i] = i + 1;                
        temp_bt[i] = bt[i];  
    }                

    

    while (count < n) {                
        smallest = -1;                
        int min_bt = 9999; 
        
        for (i = 0; i < n; i++) {                
            if (at[i] <= time && temp_bt[i] > 0) {                
                if (temp_bt[i] < min_bt) {                
                    min_bt = temp_bt[i];                
                    smallest = i;                
                }                
                
                if (temp_bt[i] == min_bt && at[i] < at[smallest]) {
                    smallest = i;
                }
            }                
        }                

        if (smallest == -1) {                
            time++;
        } else {                
            time += temp_bt[smallest]; 
            ct[smallest] = time;                
            temp_bt[smallest] = 0;
            count++;                
        }                
    }                

    printf("\np\tAT\tBT\tCT\tTAT\tWT\n");                
    for (i = 0; i < n; i++) {                
        tat[i] = ct[i] - at[i];                
        wt[i] = tat[i] - bt[i];                
        avgwt += wt[i];                
        avgtat += tat[i];                
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);                
    }                

    printf("\nAverage TAT=%.2f", avgtat / n);                
    printf("\nAverage WT=%.2f", avgwt / n);                

    return 0;                
}

