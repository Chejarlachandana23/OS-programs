#include<stdio.h>
void run_job(int job_id)
{
	printf("processing job %d...\n",job_id);
}
int main()
{
	int job_count=3;
	int i;
	for(i=1;i<=job_count;i++)
	{
		run_job(i);
	}
	return 0;
}
