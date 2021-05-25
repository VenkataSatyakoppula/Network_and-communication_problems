#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void){
    int Server_socket;
    struct sockaddr_in server_addr, client_addr;
    char server_msg[256], client_msg[256];
    int length = sizeof(client_addr);
    // Clean buffers:
    memset(server_msg, '\0', sizeof(server_msg));
    memset(client_msg, '\0', sizeof(client_msg));
    // Create UDP socket:
    Server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9002);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //local host
    // Bind to the set port and IP:
    if(bind(Server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){ //bind function
        printf("Couldn't bind to the port\n");
        return -1;
    }
    printf("Listening on port 9002\n\n");
    // Receive client's message:
    if (recvfrom(Server_socket, client_msg, sizeof(client_msg), 0,  //recvfrom function
         (struct sockaddr*)&client_addr, &length) < 0){
        printf("Couldn't receive\n");
        return -1;
    }
    printf("Msg from client: %s\n", client_msg);
    // Respond to client:
    strcpy(server_msg, client_msg);
    if (sendto(Server_socket, server_msg, strlen(server_msg), 0, //sendto function
         (struct sockaddr*)&client_addr, length) < 0){
        printf("Can't send\n");
        return -1;
    }
    return 0;
}
