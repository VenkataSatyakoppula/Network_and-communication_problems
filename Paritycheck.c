#include<stdio.h>
#include<string.h>
int even_parity(int bits[],int n){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (bits[i]==1)
        {
            count++;
        }
        
    }
    if (count%2==0)
    {
        return 0;
    }else{
        return 1;
    }   
}

int odd_parity(int bits[],int n){
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (bits[i]==1)
        {
            count++;
        }
        
    }
    if (count%2==0)
    {
        return 1;
    }else{
        return 0;
    } 
}

int main(){
    int n,bits[20],choice=0;
    printf("**********Sender-Side**********\n");
    printf("Enter the no.of bits = ");
    scanf("%d",&n);
    printf("Enter the bits (one by one) = \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&bits[i]);
    }
    printf("1)Even Parity check\n2)Odd Parity check\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        bits[n] = even_parity(bits,n);
        printf("Even parity bit is %d \n",bits[n]);
    }else if(choice==2){
        bits[n] = odd_parity(bits,n);
        printf("odd parity bit is %d\n",bits[n]);
    }
    for (int i = 0; i <=n; i++)
    {
       printf("%d ",bits[i]); 
    }
    printf("\n**********Receiver-Side**********\n");
    char rece[20];
    int c=0;
    printf("Enter the data sent by sender = ");
    scanf("%s",rece);
    for (int i = 0; i < strlen(rece); i++)
    {
        if (rece[i]=='1')
        {
            c++;
        }
        
    }
    if (choice==1)
    {
        printf("***Even parity mode***\n");
        if (c%2==0)
        {
        printf("THE ACCEPTED BITS ARE \n");
        for (int i = 0; i < strlen(rece)-1; i++)
        {
            printf("%c",rece[i]);
        }
        printf("\n");
    }else {
        printf("Bits are rejected\n");
    }
    }
    if (choice==2)
    {
        printf("***Odd Parity mode***");
        if (c%2!=0)
        {
        printf("THE ACCEPTED BITS ARE:\n");
        for (int i = 0; i < strlen(rece)-1; i++)
        {
            printf("%c",rece[i]);
        }
        printf("\n");
    }else{
        printf("Bits are rejected\n");
    }
    }
}