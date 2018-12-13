// C program for Knight Tour problem using Warnsdorff's Heuristics
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 8
/* Move pattern on basis of the change of x coordinates and y coordinates respectively */
static int cx[N]={1,1,2,2,-1,-1,-2,-2};
static int cy[N]={2,-2,1,-1,2,-2,1,-1};//to maintain the knight's position, i.e. ;

/* function restricts the knight to remain within the 8x8 chessboard */
int limits(int *a, int x, int y)
{
    if((x>=0 && y>=0) && (x<N && y<N))
        return 1;
    return 0;
}
/* checks whether a square is empty or not */
int isempty(int *a, int x, int y)
{
    if((limits(a,x,y)) && (a[y*N+x]<0))
        return 1;
    return 0;
}
/* returns the number of empty squares */
int getcount(int *a, int x, int y)
{
    int i,count=0;
    for(i=0;i<N;++i)
    {
        if(isempty(a,(x+cx[i]),(y+cy[i])))
            count++;
    }
    return count;
}
/* calculates the minimum degree(count) of unvisited square among its neighbours and assigns the counter to that square */
int progress(int *a, int *x, int *y)
{
    int start,count,i,flag=-1,c,min=(N+1),nx,ny;
    start = rand()%N;
    for(count=0;count<N;++count)
    {
        i=(start+count)%N;
        nx=*x+cx[i];
        ny=*y+cy[i];
        if((isempty(a,nx,ny))&&(c=getcount(a,nx,ny))<min)
        {
            flag=i;
            min=c;
        }
    }
    if(min==N+1)
        return 0;
    nx=*x+cx[flag];
    ny=*y+cy[flag];
    a[ny*N+nx]=a[(*y)*N+(*x)]+1;
    *x=nx;*y=ny;
    return 1;
}
/* displays the chessboard with all the legal knight's moves */
void print(int *a)
{
    int i,j;
    for(i=0;i<N;++i)
    {
        for(j=0;j<N;++j)
            printf("%d\t",a[j*N+i]);
        printf("\n");
    }
}
/* checks its neighbouring sqaures */
/* If the knight ends on a square that is one knight's move from the beginning square, then tour is closed */
int neighbour(int x, int y, int xx, int yy)
{
    int i;
    for(i=0;i<N;++i)
    {
        if(((x+cx[i])==xx)&&((y+cy[i])==yy))
            return 1;
    }
    return 0;
}
/* generates the legal moves using warnsdorff's heuristics */
int generate()
{
    int a[N*N];
    int i,x,y,sx,sy;
    for(i=0;i<N*N;++i)
        a[i]=-1;//filling up the chessboard matrix with -1's
    //sx=x=rand()%N;
    //sy=y=rand()%N;//if you want to start from the first square of the chessboard, then set x<==0 and y<==0
    sx=x=0;sy=y=0;
    a[y*N+x]=1;//initial position
    for(i=0;i<N*N-1;++i)
    {
        if(progress(a,&x,&y)==0)
        {
            return 0;
        }
    }
    if(!neighbour(x,y,sx,sy))
        return 0;
    print(a);
    return 1;
}
/* Driver program to test above functions */
int main()
{
    srand(time(NULL));
    clock_t tooo;
    tooo = clock();
    while(!generate());
    tooo = clock() - tooo;
    double time_taken = ((double)tooo)/CLOCKS_PER_SEC; // in seconds
    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
