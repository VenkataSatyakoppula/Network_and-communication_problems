#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int ack=0,ch=0,s=1,r=1;
int frames[50],n;
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
    printf("Sending frame = %d.....|....",fr);
    // if (ack=1)
    // {
    //     printf("Received ACK");
    // }else{
    //     printf("ACK not received");
    // }   
}
void receiver(int fr){
    printf("Received frame = %d",fr);
}
int main()
{
    // srand(time(0));
    // int num=random(1,3);
    // timeout(num);
    printf("Enter the no.of frames= \n");
    scanf("%d",&n);
    printf("frames which needs to be sent\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d ",i);
        frames[i]=i;
    }
    printf("\n1)ACK is lost\n2)Frame is lost\n");
    scanf("%d",&ch);
    int i=1;
    switch (ch)
    {
    case 1:
        printf("\n****ACK is lost****\n");
        while (i<n)
        {
            sender(frames[i]);
            receiver(frames[i]);
            if (random_num(1,10)<5)
            {
                ack = 1;
                i++;
            }else
            {
                ack=0;
            }
            timeout(1);
            if (ack==1)
            {
                printf("\nACK RECEIVED!!!\n");
            }else
            {
                printf("\nACK LOST\n");
            }
        }
        
        break;
    case 2:
        printf("\n****Frame is lost****\n");
                while (i<n)
        {
            sender(frames[i]);
            receiver(frames[i]);
            if (random_num(1,10)<5)
            {
                ack = 1;
                i++;
            }else
            {
                ack=0;
            }
            timeout(1);
            if (ack==1)
            {
                printf("\nACK RECEIVED!!!\n");
            }else
            {
                printf("\nACK LOST\n");
            }
        }
        break;    
    default:
        printf("\nWrong choice try again\n");
        break;
    }
    
}