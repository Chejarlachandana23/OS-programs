#include<stdio.h>
struct job{
	char name;
	int time;
};
int main(){
	int n,i,j,temp;
	struct job p[10];
	printf("enter no.of jobs:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter name and time:");
		scanf(" %c %d",&p[i].name,&p[i].time);
	}
	int resource;
	printf("enter available resources:");
	scanf("%d",&resource);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(p[i].time>p[j].time){
				char tname=p[i].name;
				p[i].name=p[j].name;
				p[j].name=tname;
				temp=p[i].time;
				p[i].time=p[j].time;
				p[j].time=temp;
			}
		}
	}
	printf("\nsafe sequence:");
	for(i=0;i<n;i++){
		printf( "%c %d",p[i].name,p[i].time);
	}
	return 0;
}
