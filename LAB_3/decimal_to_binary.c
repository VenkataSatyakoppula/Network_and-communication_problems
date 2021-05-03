#include<stdio.h>
#include<string.h>
#define MAX_LIMIT 100
int main(){
//    char str[MAX_LIMIT],a[15][30],b[15][30];
//    fgets(str, MAX_LIMIT, stdin);
// //    printf("%s", str);
//    char lim[] = " ";
//    char *ptr = strtok(str, lim);
//    int i=0;
//    	while(ptr != NULL)
// 	{
// 		printf("%s\n", ptr);
//         strcpy(*a,ptr);
// 		ptr = strtok(NULL, lim);
//         i++;
// 	}
//     printf("%d",i);
//     for (int j = 0; j < i; i++)
//     {
//         printf("%s",a[j]);
//     }
    unsigned int x = 39;
    x = x>>4;
    x = ~x;
    x = x<<4;
    x = ~x;
    printf("%d",x);


}