#include<stdio.h>
int main()
{                                                                                                          
	int indexblock,n,blocks[20],alclocated[50]={0};
	int i;
	printf("enter index block:");
	scanf("%d",&indexblock);
	`if(allocated[indexblock])
		{
			printf("index block already allocated\n");
			return 0;
		}
		allocated[indexblock]=1;
		printf("enter number of blocks needed:");
		scanf("%d",&n);
		printf("enter block numbers:\n");
		for(i=0;i<n;i++)
			{
				scanf("%d",&blocks[i]);
				if(allocated[blocks[i]])
					{
						printf("%d already allocated\n",blocks[i]);
					}else{
						allocated[blocks[i]]=1;
						printf("%dallocated\n",blocks[i]);
					}
			}
			printf("\nIndexed file allocation successful\n");
			printf("index block is:%d\n",indexblock);
}
