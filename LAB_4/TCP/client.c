#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    //creating TCP socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM,0);//'0' means default TCP protocol
    
    //address of the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connect_stat = connect(network_socket, (struct sockaddr *) &server_address,sizeof(server_address));

    // check for error
    if (connect_stat == -1)
    {
        printf("There was an error making a connection \n\n");
    }else{
        printf("Connected on PORT 9002\n");
    }
    //receive data from server
    char server_Response[256];
    recv(network_socket, &server_Response,sizeof(server_Response), 0);
    
    //print server response
    printf("Server Sent the data: %s\n",server_Response);
    return 0;
}