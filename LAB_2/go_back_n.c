#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int ack=0,ch=0,win=0,key=0;
int frames[50],n;
int buffer[10];
int timeout ( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
    return  1;
}
int random_num(int lower, int upper)
{
    int num = rand() % upper;
    return num;
}
void sender(int fr){
    int k=0;
    if (fr==1 && key==0)
    {
    for (int i = fr; i < fr+win; i++)
    {
        printf("Sending frame = %d.....|.....Received frame = %d\n",frames[i],frames[i]);
        buffer[k]=frames[i%n];
        k++;
    }
    key=1;
    }else
    {
        if (ack==1)
        {
            printf("\nACK RECEIVED FOR FRAME %d!!!\n",fr-1);
            if (fr==n)
            {
                exit(0);
            }
            
            if ((fr+win-1)>=n)
            {
                printf("Sending frame = %d.....|.....Received frame = %d\n",frames[(fr+win-1)%n+1],frames[(fr+win-1)%n+1]);
            }else
            {
                printf("Sending frame = %d.....|.....Received frame = %d\n",frames[(fr+win-1)],frames[(fr+win-1)]);
            }
            
        }else
        {
            printf("\nACK LOST....LAST ACK WAS %d\n",fr-1);
            printf("\nResending window....\n");
            for (int i = fr; i < fr+win; i++)
            {
                if (i>=n)
                {
                    printf("Sending frame = %d.....|.....Received frame = %d\n",frames[(i)%n+1],frames[i%n+1]);
                }else
                {
                    printf("Sending frame = %d.....|.....Received frame = %d\n",frames[i],frames[i]);
                }
                
            }
        }
        
    }

}
int main()
{
    srand(time(0));
    printf("\n****Go_Back_N ARQ****\n");
    printf("Enter the no.of frames= \n");
    scanf("%d",&n);
    printf("Sequence numbers = \n");
    for (int i = 1; i < n; i++)
    {
        printf("%d ",i);
        frames[i]=i;
    }
    printf("\nEnter the size of window = ");
    scanf("%d",&win);
    int i=1;
    printf("\n****ACK is lost****\n");
    while (i<n+1)
    {
        sender(i);
        if (random_num(1,10)<5)
        {
            ack = 1;
            i++;
        }else
        {
           ack=0;
        }
        timeout(1);
    }
} 