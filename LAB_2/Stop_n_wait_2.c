#include<stdio.h>
#include<time.h>
int s=1,r=1,ack=0;
int frames[50],n;
int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
    return  1;
}

int main()
{
    
}