#include<iostream>
#include<cstring> 
#include<arpa/inet.h> 
#include <sys/socket.h>   
#include <unistd.h> 
#include "db.h"
using namespace std;

#define PORT 8080  
int main(){
   dbClass db;
  int server_socket=socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
        cerr << "Socket creation failed!" << endl;
        return 1;
    }
    cout<<"server_socket "<<server_socket<<endl;
  sockaddr_in server_address;
  memset(&server_address,0,sizeof(server_address));
  server_address.sin_family=AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;  
  server_address.sin_port=htons(PORT);
  if(::bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0){
     cerr<<" Binding Failed !"<<endl;
     close(server_socket);
     return 1;

  }
   if (listen(server_socket, 5) < 0) {
        cerr << "Listening failed!" << endl;
        close(server_socket);
        return 1;
    }

  int client_socket=accept(server_socket,nullptr,nullptr);
  cout<<"client_socket "<<client_socket<<endl;
  if (client_socket < 0) {
        cerr << "Failed to accept connection!" << endl;
        close(server_socket);
        return 1;
    }
    cout << "Client connected!" <<endl;
  while(true){
     char buffer[1024] = {0};
    int read_size = recv(client_socket, buffer, sizeof(buffer), 0);
    cout<<"read_size "<<read_size<<endl;
    if (read_size > 0) {
        cout << "Client says: " << buffer << endl;
    } else {
        cerr << "Failed to receive message from client!" << endl;
        return 1;
    }
  }
      
    
    const char* message = "Hello from the server!";
    send(client_socket, message, strlen(message), 0); 
    close(client_socket);
    close(server_socket);
    return 0;

}