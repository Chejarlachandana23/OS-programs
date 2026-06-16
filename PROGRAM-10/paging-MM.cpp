#include<stdio.h>
int main()
{
	int pagetable[20];
	int pagesize,n,i;
	int logicaladdress;
	int pagenumber,offset;
	int framenumber,physicaladdress;
	printf("enter page size:");
	scanf("%d",&pagesize);
	printf("enter number of pages:");
	scanf("%d",&n);
	printf("enter frame numbers for each page:\n");
	for(i=0;i<n;i++)
	{
		printf("page%d->Frame:",i);
		scanf("%d",&pagetable[i]);
	}
	printf("enter logical address:");
	scanf("%d",&logicaladdress);
	pagenumber=logicaladdress/pagesize;
	if(pagenumber>=n)
	{
		printf("invalid page number\n");
		return 0;
	}
	framenumber=pagetable[pagenumber];
	physicaladdress=framenumber*pagesize+offset;
	printf("\n Page Number=%d",pagenumber);
	printf("\n ofset=%d",offset);
	printf("\n FrameNumber=%d",framenumber);
	printf("\n Physical address=%d\n",physicaladdress);
	return 0;
}
