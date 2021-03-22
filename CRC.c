#include<stdio.h>
int n,m,data[50],divisor[10],out[10]; //out[10] array stores the result in each iteration
int xor(int a,int b){
    if(a==b){
        return 0;
    }else{
        return 1;
    }
}
//appends the zero's to data
void append_zeros(int l,int n){
    for (int i = n; i < n+l-1; i++)
    {
        data[i] = 0;
    }
}
//calculates CRC 
void CRC(){
    printf("intermediate values in division\n");
    for (int i = 0; i < m-1; i++) //calculates initial values 
    {
        if (data[0]==1)
        {
            out[i] = xor(data[i+1],divisor[i+1]);
        }else{
            out[i] = xor(data[i+1],0);
        }  
    }
    out[m-1] = data[m];
    for (int i = 0; i < m; i++)
    {
        printf("%d",out[i]); //printing out initial values
    }
    printf("\n");
    for (int j = m+1; j < n+m; j++) //calcultes remaining values
    {
        if (out[0]==1)
        {
            for (int i = 0; i < m-1; i++)
           {
            out[i] = xor(out[i+1],divisor[i+1]);
           }
        }else
        {
           for (int i = 0; i < m-1; i++)
           {
            out[i] = xor(out[i+1],0);
           }
        }
        out[m-1] = data[j];
        for (int i = 0; i < m; i++)
        {
        printf("%d",out[i]);
        }
        printf("\n");     
    }
    printf("CRC = ");
    for (int i = 0; i < m-1; i++)
    {
        printf("%d",out[i]);
    }
    printf("\n");
}
int main(){
    printf("Enter the length of Data: ");
    scanf("%d",&n);
    printf("Enter the data = \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data[i]);
    }
    printf("Enter the length of Divisor: ");
    scanf("%d",&m);
    printf("Enter the divisor= \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&divisor[i]);
    }
    printf("\n******Sender-Side******\n");
    printf("Number of zero's to be appended: %d \n",m-1);
    append_zeros(m,n); //this function will append zero's
    printf("Data After appending: ");
    for (int i = 0; i < n+m-1; i++)
    {
        printf("%d",data[i]);
    }
    printf("\n");
    CRC(); //calling CRC function
    for (int i = n; i < n+m-1; i++) //for loop to append CRC at the end of message
    {
        data[i] = out[i-n];
    }
    printf("Generated message = "); 
    for (int i = 0; i < n+m-1; i++)
    {
        if (i==n)
        {
            printf(" | ");
        }
        printf("%d",data[i]);
    }
    printf("\n*******Receiver_side*******\n");
    printf("Enter the data received: ");
    for (int i = 0; i < n+m-1; i++)
    {
        scanf("%d",&data[i]);
    }
    CRC(); //calculating CRC at receiver side
}

