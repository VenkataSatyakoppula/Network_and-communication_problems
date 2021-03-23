#include<stdio.h>
#include<string.h>
int main(){
    char data[20],s1[10],s2[10];
    printf("Enter the 8-bit data = ");
    scanf("%s",data);
    printf("Data will be divided into 2 sections(8-bit,8-bit)\n");
    for (int i = 0; i < strlen(data); i++)
    {
        strcpy(&s1[i],&data[i]);
        strcpy(&s2[i],&data[(strlen(data)/2)+i]);
    }
    printf("\nSection-1: ");
    for (int i = 0; i < strlen(data)/2; i++)
    {
        printf("%c",s1[i]);
    }
    printf("\nSection-2: ");
    for (int i = 0; i < strlen(data)/2; i++)
    {
        printf("%c",s2[i]);
    }
    
    
    
}