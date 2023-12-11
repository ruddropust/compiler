#include<bits/stdc++.h>

#include <utility>
using namespace std;

class entries{
public:
    string name,id_type,data_type,scope,value;
    entries(){
        name="";
        id_type="";
        data_type="";
        value="";
        scope="";
    }
};
vector<entries> symbol_table;

void insert(string name,string id_type, string data_type,string scope, string value){
    entries entry;
    entry.name=name;
    entry.id_type=id_type;
    entry.data_type=data_type;
    entry.value=value;
    entry.scope=scope;
    symbol_table.push_back(entry);
}

entries* lookup(string s){
    for(auto& i:symbol_table){
        if(i.name==s){
            return &i;
        }
    }
    return nullptr;
}

void Delete(string s){
    for(auto it=symbol_table.begin(); it<symbol_table.end(); it++){
        if(it->name==s){
            symbol_table.erase(it);
            break;
        }
    }
}
void update(string s,string name,string id_type, string data_type,string scope, string value){
    for(auto entry=symbol_table.begin();entry<symbol_table.end();entry++){
        if(entry->name==s){
            entry->name=name;
            entry->id_type=id_type;
            entry->data_type=data_type;
            entry->value=value;
            entry->scope=scope;
        }
    }
}

void display(){
    cout<<"name -- data_type -- id_type -- scope -- value"<<endl;
    for(auto i:symbol_table){
        cout<<i.name<<" -- "<<i.data_type<<" -- "<<i.id_type<<" -- "<<i.scope<<" -- "<<i.value<<endl;
    }
}

int main(){

}