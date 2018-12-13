#include<stdio.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>
#define lim 8
int arr[lim][lim];
int ans[lim][lim];
int x[64],y[64],point;
clock_t tooo;
int printsol()
{
	int i,j,count=1;
	for(i=0;i<64;i++)
	ans[x[i]][y[i]]=count++;
	for(i=0;i<lim;i++)
	{
		for(j=0;j<lim;j++)
		    printf("%d\t",ans[i][j]);
		printf("\n");
	}
	tooo = clock() - tooo;
    double time_taken = ((double)tooo)/CLOCKS_PER_SEC; // in seconds
    printf("fun() took %f seconds to execute \n", time_taken);
	exit(1);
}
void findpath(int a,int b)
{
	if(!(a>-1&&a<lim&&b>-1&&b<lim&&arr[a][b]==0))
	return;
	point++;
	arr[a][b]=1;
	x[point]=a;y[point]=b;
	if(point==63)
	printsol();
	findpath(a-2,b+1);
	findpath(a-1,b+2);
	findpath(a+1,b+2);
	findpath(a+2,b+1);
	findpath(a+2,b-1);
	findpath(a+1,b-2);
	findpath(a-1,b-2);
	findpath(a-2,b-1);
	point--;
	arr[a][b]=0;
}
int main()
{
    point=-1;int start;int xxx;
	memset(arr,0,sizeof(arr));
	srand(time(NULL));
    start=0;
    tooo = clock();
    findpath(start+7,start+7);
	return 0;
}
