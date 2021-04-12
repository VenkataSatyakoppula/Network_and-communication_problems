#include<stdio.h>
int data[20],carry=0,sum[10],s=0;
int s1[10],s2[10];

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
    // printf("%d%d",s,carry); 
}
void sender(){
    printf("Enter data  8-bits only = \n");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d",&data[i]);
    }
    printf("\nSection-1 = ");
    for (int i = 0; i < 4; i++)
    {
        s1[i] = data[i];
        s2[i] = data[4+i];
        printf("%d",s1[i]);
    }
    printf("\nsection-2 = ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d",s2[i]);
    }
    for (int i = 3; i >= 0; i--)
    {
        sum[i] = add(s1[i],s2[i]);
    }
    if (carry==1)
    {
        for (int i = 3; i >= 0; i--)
        {
            sum[i]=add(sum[i],0);
        }  
    }
    printf("\nCheck sum = ");
    for (int i = 0; i < 4; i++)
    {
        if (sum[i]==0)
        {
            sum[i]=1;
        }else{
            sum[i]=0;
        }
        printf("%d ",sum[i]);
    }
    printf("\nData sent to the receiver  = ");
    for (int i = 0; i < 12; i++)
    {
        if (i<8)
        {
            printf("%d ",data[i]);
        }else
        {
            printf("%d ",sum[i-8]);
        } 
    }  
}
void receiver(){
    printf("Enter the data = \n");
    for (int i = 0; i < 12; i++)
    {
        scanf("%d",&data[i]);
    }
    sender();
    for (int i = 0; i < 4; i++)
    {
        if (sum[i]==1)
        {
            
        }
        
    }
    
}
int main(){
    sender();
    printf("\n");
    receiver();
    
    

    
    
}
