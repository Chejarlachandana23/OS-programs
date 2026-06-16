#include<stdio.h>
int main()
{
	int pages[50],frames[10];
	int n,f,i,j,k,fault=0;
	int found,farthest,index,pos;
		printf("enter number of pages:");
		scanf("%d",&n);
		printf("enter page reference string:");
		for(i=0;i<n;i++){
			scanf("%d",&pages[i]);
		}
		printf("enter number of frames:");
		scanf("%d",&f);
		for(i=0;i<f;i++){
			frames[i]=-1;
		}
		for(i=0;i<n;i++){
			found=0;
			for(j=0;j<f;j++){
				if(frames[j]==pages[i]){
					found=1;
					break;
				}
			}
			if(!found){
				fault++;
				for(j=0;j<f;j++){
					if(frames[j]==-1){
						frames[j]=pages[i];
						found=1;
						break;
					}
				}
				if(!found){
					farthest=-1;
					index=-1;
					for(j=0;j<f;j++){
						pos=999;
					for(k=i+1;k<n;k++){
						if(frames[j]==pages[k]){
							pos=k;
							break;
						}
					}
					if(pos>farthest){
						farthest=pos;
						index=j;
					}
					}
					frames[index]=pages[i];
				}
			}
		}
printf("total pages faults(optimal)=%d\n",fault);
return 0;
}
