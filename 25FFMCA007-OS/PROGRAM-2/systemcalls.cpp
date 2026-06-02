#include<stdio.h>
int my_fork(){
	printf("fork()called-creating child process\n");
	return 0;
}
void my_wait(){
	printf("wait()called-parent waiting for child process\n");
}
void my_exit(){
	printf("exit()called-process exited successfully\n");
}
int my_getpid(){
	return 101;
}
int my_open(const char*filename){
	printf("open()called-file%sopened succesfully\n",filename);
	return 1;
}
int main()
{
	int pid,fd;
	pid=my_fork();
	if(pid==0){
		printf("child process TD:%d\n",my_getpid());
		my_exit();
	}
	else{
		my_wait();
	}
	fd=my_open("sample.txt");
	printf("current process TD:%d\n",my_getpid());
	return 0;
}
