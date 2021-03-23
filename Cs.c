#include<stdio.h>

int data1[10],data2[10],carry=0,sum[10],temp[10];
void checksum(void);
int add(int a,int b){
    int c=0;
    if (a==1)
    {
        c++;
    } 
    if(b==1){
        c++;
    }
    if(carry==1){
        c++;
    }
    if (c==1)
    {
        carry=0;
        return 1;
    }else if (c==2)
    {
        carry=1;
        return 0;
    }else if(c==3){
        carry=1;
        return 1;
    }else{
        carry=0;
        return 0;
    }
}
void sender(){
    printf("Enter 1st section of 8-bit data= ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d",&data1[i]);
    }
    printf("Enter 2st section of 8-bit data = ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d",&data2[i]);
    }
    checksum();
    for (int i = 0; i < 8; i++)
    {
        temp[i] = sum[i];
    }
    
}
void checksum(){
    for (int i = 8; i >= 0; i--)
    {
        sum[i] = add(data1[i],data1[i]);
    }
    printf("\nCheck sum = ");
    for (int i = 0; i < 8; i++)
    {
        if (sum[i]==0)
        {
            sum[i]=1;
        }else{
            sum[i]=0;
        }
        printf("%d",sum[i]);
    }
}
void receiver(){
    int key=0;
    printf("Enter 1st section of 8-bit data = ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d",&data1[i]);
    }
    printf("Enter 2st section of 8-bit data = ");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d",&data2[i]);
    }
    checksum();
    for (int i = 0; i < 8; i++)
    {
        if (temp[i]!=sum[i])
        {
            printf("\nCheck sum is not equal hence, data is rejected\n");
            key=1;
            break;
        }
    }
    if (key==0)
    {
        printf("\nChecksum is equal, hence data is accepted\n");
    }
    
}

int main(){
    printf("******SENDER******\n");
    sender();
    printf("\n******RECEIVER******\n");
    receiver();
}