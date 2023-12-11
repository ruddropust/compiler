#include<bits/stdc++.h>
using namespace std;
vector<string>token_list;
string str;
int balance=0;

bool is_separator(char ch){
    string str = " ,;:+-*/%=><!&|";
    string tmp;
    for(int i=0;i<str.size();i++){
        if(ch==str[i]){
            return true;
        }
    }return false;
}
bool is_vartype(string s){
    vector<string> keyword={"char","double","float","int","long", "short","signed","unsigned"};
    auto f = find(keyword.begin(),keyword.end(),s);
    if(f==keyword.end()){
        return false;
    }
    else{
        return true;
    }
}
bool check(){
    vector<string> v1;
    set<string> v2;
    for(int i=0; i<token_list.size(); i++){
        if(is_vartype(token_list[i])&&!is_vartype(token_list[i+1])){
            v1.push_back(token_list[i+1]);
            v2.insert(token_list[i+1]);
        }
    }
    if(v1.size()==v2.size()){
        return true;
    }
    else{
        return false;
    }
}

void count_paranthesis(char a){
    if(a=='('||a=='{'||a=='['){
        balance++;
    }
    else{
        balance--;
    }
}

void tokenize(){
    string token="";
    for(char i:str){
        if(is_separator(i)||i=='\n'){
            token_list.push_back(token);
            token="";
        }
        else if(i=='('||i=='{'||i==')'||i=='}'||i=='['||i==']'){
            if(token!=""){
                token_list.push_back(token);
                token="";
            }
            count_paranthesis(i);
        }
        else{
            token+=i;
        }
    }
    token_list.push_back(token);
}
int main(){
    do{
        getline(cin,str);
        if(str!="###") {
            tokenize();
        }
    }
    while(str!="###");


    for(auto i:token_list){
        cout<<i<<endl;
    }

    if(balance!=0){

        cout<<"paranthesis mismatch"<<endl;
    }
    else{
        cout<<"paranthesis ok"<<endl;
    }
    if(check()){
        cout<<"no double declaration"<<endl;
    }
    else{
        cout<<"double declaration"<<endl;
    }
}
