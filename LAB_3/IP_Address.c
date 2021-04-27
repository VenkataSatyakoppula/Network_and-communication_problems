#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
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
int IP_checker(int num){
    if (num>255)
    {
        return 1;
    }else
    {
        return 0;
    }  
}
int main(){
    char IP[16];
    char **tokens;
    int temp=0,c=0,cout=0;
    printf("Enter the IP Address in decimal form(xxx.xxx.xxx.xxx):");
    scanf("%s",IP);
    
    for (int i = 0; i < strlen(IP); i++)
    {
        if (IP[i]==46)
        {
            c++;
        }
    }
    if (c>3 || strlen(IP)>15)
    {
        printf("IP Address is Invalid!!!\n");
        exit(0);
    }
    tokens = str_split(IP,'.');
    for (int i = 0; *(tokens+i); i++)
    {
        // printf("%s",*(tokens+i));
        temp = temp + IP_checker(atoi(*(tokens+i)));  
    }
    if (temp==0) 
    {
        printf("IP Address is Valid!!!\n");
    }else
    {
        printf("IP Address is Invalid!!!\n");
    }
}