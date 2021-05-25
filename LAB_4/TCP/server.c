#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    char server_msg[256] = "Hello";
    //creating TCP socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM,0);//'0' means default TCP protocol
    
    //server  address of the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;\
    //bind socket to specific IP and port
    printf("Data to be sent to Client = %s \n",server_msg);
    printf("Listening on port 9002 \n");
    bind(server_socket, (struct sockaddr*) &server_address , sizeof(server_address));
     
    listen(server_socket,5);
    int client_socket;
    client_socket = accept(server_socket,NULL,NULL);
    //sending the message
    send(client_socket,server_msg,sizeof(server_msg),0);
    return 0;
}
