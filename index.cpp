#include<iostream>
#include<cmath>
#include<climits>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include "db.h"

using namespace std;

void runCli(){
  dbClass db;
  string command;
  cout<<"Welcome to the in-memoryDB";
  while(true){
    cout<<">";
    getline(cin,command);

    if(command=="EXIT")break ;
    string operation,key;
    int prev=0;
    for(int i=0;i<command.size();i++){
       if(command[i]==' '&&command[i-1]!=' '){
                operation=command.substr(prev,i);
       }
        if(command[i]==' '&&command[i+1]!=' '){
        prev=i+1;
       }
    }
     key=command.substr(prev);


    if (operation == "ADD") {
           string value;
           cout<<"ENTER VALUE"<<endl;
           cin>>value;
            db.add(key, value);
             cin.ignore(); 
        } else if (operation == "UPDATE") {
            string value;
           cout<<"ENTER VALUE"<<endl;
           cin>>value;
            db.update(key, value);
                 cin.ignore(); 
        } else if (operation == "DELETE") {
            db.remove(key);
        } else if (operation == "GET") {
            db.get(key);
        } else {
            cout << "COMMAND NOT FOUND\n";
        }
  }
  db.log();
  cout<<"EXITING CLI";

}

int main(){
   runCli();
    return 0;
}