#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

#define PORT 8080 

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    cout<<"client_socket "<<client_socket<<endl;
    if (client_socket < 0) {
        cerr << "Socket creation failed!" << endl;
        return 1;
    }

  
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT); 
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); 


    int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status < 0) {
        cerr << "Connection to the server failed!" << endl;
        return 1;
    }


    // char buffer[1024] = {0};
    // int read_size = recv(client_socket, buffer, sizeof(buffer), 0);
    // if (read_size > 0) {
    //     cout << "Server says: " << buffer << endl;
    // } else {
    //     cerr << "Failed to receive message from server!" << endl;
    // }
  
     while(true){
       const char* message = "Hello from the client!";
    cout<<"debug"<<endl;
    send(client_socket, message, strlen(message), 0); 
     }


    close(client_socket);
    return 0;
}
