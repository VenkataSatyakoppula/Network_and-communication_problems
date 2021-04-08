#include <stdio.h>
#include <time.h>
int s=1,r=1,ack=0;
int frames[50],n;
int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
    return  1;
}
void sender(int frame){
    if (s==0)
    {
        s=1;
    }else
    {
        s=0;
    }
    printf("S= %d \n",s);
    printf("Sending frame %d \n",frame);
}
void receiver(int frame){
    if (r==0)
    {
        r=1;
    }else
    {
        r=0;
    }
    printf("R= %d \n",r);
    printf("Received frame %d \n",frame);
    if (ack==0)
    {
        ack=1;
    }else{
        ack=0;
    }
        
}
int main ()
{
    printf("*********STOP_AND_WAIT********** \n");
    printf("Enter the no.of frames:- ");
    scanf("%d",&n);
    printf("Enter frames = \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&frames[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sender(frames[i]);
        receiver(frames[i]);
        printf("waiting for Acknowledgement(2 sec)\n");
        timeout(2);
        printf("ACK= %d \n",ack);
    }
    
}