#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int s=1,r=1,ack=0;
int frames[50],n;
int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
    return  1;
}
int random(int lower, int upper)
{
    int num = rand() % upper;
    return num;
}
int main()
{
    srand(time(0));
    int num=random(1,10);
    timeout(num);
    printf("satya %d",num);
    
}