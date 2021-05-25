#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void){
    int Client_socket;
    struct sockaddr_in server_addr;
    char server_msg[256], client_msg[256];
    int length = sizeof(server_addr);
    // Clean buffers:
    memset(server_msg, '\0', sizeof(server_msg));
    memset(client_msg, '\0', sizeof(client_msg)); 
    // Create UDP socket:
    Client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9002);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // Get input from the user:
    printf("Enter message: ");
    scanf("%s",client_msg);
    // Send the message to server:
    if(sendto(Client_socket, client_msg, strlen(client_msg), 0, //sendto function
         (struct sockaddr*)&server_addr, length) < 0){
        printf("Something Went wrong!!\n");
        return -1;
    }
    // Receive the server's response:
    if(recvfrom(Client_socket, server_msg, sizeof(server_msg), 0, //recvfrom function
         (struct sockaddr*)&server_addr, &length) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
    printf("Server's response: %s\n", server_msg);
    return 0;
}

