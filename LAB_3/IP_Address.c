#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//str_split() function to  split the string source:Stackoverflow
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
        printf("IP Address is Valid!!!\n");
    }
    else
    {
        printf("IP Address is Invalid!!!\n");
    }
    
    
}
int main(){
    char IP[16],mask[3];
    char **tokens;
    int temp=0,c=0,cout=0;
    printf("Enter the IP Address in decimal form(xxx.xxx.xxx.xxx): ");
    scanf("%s",IP);
    printf("Enter the Subnet mast in decimal number: ");
    scanf("%s",mask);
    if (atoi(mask)>32)
    {
        validity(1);
        exit(0);
    }
    for (int i = 0; i < strlen(IP); i++)
    {
        if (IP[i]==46)
        {
            c++;
        } 
        if (IP[i]!= (48 || 49 || 50 || 51 || 52 || 54 || 55 || 56 || 67 || 46))
        {
            printf("%c \n",IP[i]);
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
        temp = temp + IP_checker(atoi(*(tokens+i))) + 1;  
    }
    if (temp==4) 
    {
        validity(0);
    }else
    {
        validity(1);
    }
}
