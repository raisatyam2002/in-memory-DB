
#include <iostream>
#include <unordered_map>
using namespace std;
class dbClass {
private:
    unordered_map<string, string> db;

public:
    void add(string key, string value) {
        db[key] = value;
    }
    void remove(string key){
        if(db.find(key)!=db.end()){
            db.erase(key);
        }
        else{
            cout<<"key does not exist"<<endl;
        }
    }
    void get(string key){
        if(db.find(key)!=db.end()){
            cout<<db[key]<<endl;
        }
        else{
            cout<<"key does not exist"<<endl;
        }
        
    }
    void update(string key,string value){
         db[key]=value;
    }
    void log() const {
        for (const auto& it : db) {
           cout << it.first << " " << it.second << endl;
        }
    }
};
