#include<stdio.h>
#include<math.h>
int data[50],parity[50],temp[20],ham[20];
int data_limit,parity_bits=0,count=0,j=0,k=0,l=0;
void hamming(void);
void display(int a[]);

void display(int a[]){ //display the bits in data
    int j=0;
    for (int i = 1; i < data_limit+parity_bits+1; i++)
    {
        if (pow(2,j)==i)
        {
            data[i]=ham[j];
            j++;
        }
        printf("%d ",data[i]);
    }
}
int xor(int a[],int l){ //checks no.of 1's
    int c=0;
    for (int i = 0; i < l; i++)
    {
        if (a[i]==1)
        {
            c++;
        }
    }
    if(c%2==0){
        return 0;
    }else
    {
        return 1;
    }
}
void sender(){ //sender function
    printf("*******SENDER SIDE*******\n");   
    printf("Enter the length of data = ");
    scanf("%d",&data_limit);
    while (!(pow(2,parity_bits)>=data_limit+parity_bits+1))
    {
        parity_bits++;
    }
    printf("No.of Parity bits = %d \n",parity_bits);
    printf("Enter the data = \n");
    for (int i = 1; i < data_limit+parity_bits+1; i++)
    {
        if (pow(2,count)==i)
        {
            data[i]=0;
            count++;
        }else{
            scanf("%d",&data[i]);
        }
        
    }
    hamming();
    printf("\n");
    printf("Generated Bits =  ");
    display(ham);
}
void hamming(){ //calaculationg hamming code(parity bits)
    for (int i = 0; i < parity_bits; i++)
    {
        j=pow(2,i);
        l=0;
        while (j<parity_bits+data_limit+1)
        {
            
            k=j;
            while(k<j+pow(2,i) && k<data_limit+parity_bits+1)
            {
                temp[l]=data[k];
                l++;
                k++;
                
            }
            j = j+ pow(2,i+1);
            
        }
        ham[i] = xor(temp,l);
    }
    printf("Hamming bits  = ");
    for (int i = 0; i < parity_bits; i++)
    {
        printf("%d ",ham[i]);
    }
    
}

void receiver(){ //receiver function
    printf("*******RECEIVER SIDE*******\n");
    printf("Enter the bits to be sent = \n");
    for (int i = 1; i < data_limit+parity_bits+1; i++)
    {
        scanf("%d",&data[i]);  
    }
    hamming();
    int error=0;
    for (int i = 0; i < parity_bits; i++)
    {
        if (ham[i]==1)
        {
            error = error + pow(2,i);
        }
    }
    if (error!=0)
    {
        printf("\nError at position = %d\n",error);
        if (data[error]==1) //correcting the bits
        {
            data[error]=0;
        }else
        {
            data[error]=1;
        }
        printf("Data after Error correction = ");
    }else
    {
        printf("\nAll Bits received without any error\n");
    }
    for (int i = 1; i < data_limit+parity_bits+1; i++)
    {
        printf("%d ",data[i]);
    }
    
}

int main(){
    printf("\n*****Hamming code*****\n");
    sender();
    printf("\n");
    receiver();
    printf("\n");
}