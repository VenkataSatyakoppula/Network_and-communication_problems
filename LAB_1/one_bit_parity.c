#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int AsciitoBinary(int n) //function to convert ascii to binary
{
	int res = 0, i = 1, rem;
        
	while (n > 0)
	{
		rem = n % 2;
		res = res + (i * rem);
		n = n / 2;
		i = i * 10;
	}
	return(res);
}
const char* int_string(int binary){  // function to convert int to string
    int length = snprintf( NULL, 0, "%d", binary );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", binary);
    return str;
}
const char* parity_check(char* data){  //parity check function
	int count=0;
	for (int i = 0; i < strlen(data); i++) //iterates through string of binary
	{
		if (data[i]=='1') //counts no.of 1's, data is a pointer &data is the character 
		{
			count++;
		}
		
	}
	if (count%2==0)
	{
		return strcat(data,"0");
	}else{
		return strcat(data,"1");
	}

}

char* sender() {
	char msg[10];
	int buff=0,asc=0;
	const char* buff_2;
	char* binary,*output,*result;
	result = strdup("_");
	printf("Enter the data(in string with out gaps upto char[10]): ");
	scanf("%s",msg);
	for (int i = 0; i < strlen(msg); i++)
	{
		asc = msg[i];
		buff = AsciitoBinary(asc);
		buff_2 = int_string(buff);
		binary = strdup(buff_2);
		output = strdup(parity_check(binary));
		printf("%s parity for letter %c \n",output,msg[i]);
		strcat(output,"_");
		strcat(result,output);
	}
	printf("Bits needs to be sent to server is \n%s",result);
	return result;
}

char * receiver(char* msg){
	int i=1;
	while (msg[i]!="_")
	{
		printf("%c",msg[i]);
	}
}
int main()
{
	char* msg=sender();
	receiver(msg);
	
}
