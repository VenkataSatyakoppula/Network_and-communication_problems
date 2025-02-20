#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
//str_split() function to  split the string has been referenced from internet
char** str_split(char* a_str, const char splitter)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = splitter;
    delim[1] = 0;
    while (*tmp)
    {
        if (splitter == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;
    result = malloc(sizeof(char*) * count);
    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);
        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}
//Ip checker function
int IP_checker(int num){
    if (num>255 || num<=0)
    {
        return 1;
    }else
    {
        return 0;
    }  
}
void validity(int i){
    if (i==0)
    {
        printf("\n************************\n*IP Address is Valid!!!*\n************************\n\n");
    }
    else
    {
        printf("\n************************\n*IP Address is Invalid!!!*\n*************************\n\n");
        exit(0);
    }
    
    
}
int main(){
    char IP[16],mask[3];
    char **tokens;
    int temp=0,c=0,cout=0,ip_in_int[10],int_mask;
    printf("Enter the IP Address in decimal form(xxx.xxx.xxx.xxx): ");
    scanf("%s",IP);
    printf("Enter the Subnet mask in decimal number: ");
    scanf("%s",mask);
    printf("\n\nIP Address = %s/%s\n\n",IP,mask);
    int_mask = atoi(mask);
    if (int_mask>32)
    {
        printf("Invalid Subnet mask \n");
        exit(0);
    }
    for (int i = 0; i < strlen(IP); i++)
    {
        if (IP[i]==46)
        {
            c++;
        } 
        if (IP[i]!= 48 && IP[i]!=49 && IP[i]!=50 && IP[i]!=51 && IP[i]!=52 && IP[i]!=54 && IP[i]!=55 && IP[i]!= 56 && IP[i]!= 57 && IP[i]!= 46 && IP[i]!= 53)
        {
            validity(1);
            exit(0);
        }
           
    }
    if (c>3 || strlen(IP)>15)
    {
        validity(1);
        exit(0);
    }
    tokens = str_split(IP,'.');
    for (int i = 0; *(tokens+i); i++)
    {
        ip_in_int[i] = atoi(*(tokens+i));
        temp = temp + IP_checker(ip_in_int[i]) + 1;  
    }
    if (temp==4) 
    {
        validity(0);
    }else
    {
        validity(1);
    }
    //finding first and last address blocks
    printf("\n**********Finding First,last and no.of address in Block**********\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ",ip_in_int[i]);
    }
    printf("\n\nNo.of address in Block 2^(%d-%d)= %lld\n\n",32,int_mask,(long long)pow(2,(32-int_mask)));
    int app_bits = 32-int_mask;
    printf("No.of zero's to be replaced at the end for First Ip in block = %d",app_bits);
    int n =  app_bits/8,i=0;
    while (i<n)
    {
        ip_in_int[3-i]=0;
        i++;
    }
    //C right shift and leftshift operators to replace zeros at last of binary values of ip address
    ip_in_int[3-n] = ip_in_int[3-n]>>(app_bits%8);
    ip_in_int[3-n] = ip_in_int[3-n]<<(app_bits%8);
    printf("\n\n");
    printf("First IP Address of Block = ");
    for (int j = 0; j < 3; j++)
    {
        printf("%d.",ip_in_int[j]);
    }
    printf("%d/%d",ip_in_int[3],int_mask);
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf(".....\n");
    }
    printf("\n\n");
    printf("Last IP Address of block = ");
    ip_in_int[3-n] = ip_in_int[3-n] + pow(2,32-int_mask)-1;
    for (int i = 0; i < 3; i++)
    {
        printf("%d.",ip_in_int[i]);
    }
    printf("%d/%d",ip_in_int[3],int_mask);
    printf("\n\n");
}
