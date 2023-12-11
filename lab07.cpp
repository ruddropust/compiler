#include<bits/stdc++.h>
using namespace std;
#define npos string::npos

bool is_operator(char ch){
    string str = "+-*/";
    for(int i=0;i<str.size();i++){
        if(ch==str[i]){
            return true;
        }
    }return false;
}

bool any_operator(string s){

    for(char i:s){
        if(i=='+' || i=='-' || i=='*'|| i== '/')
            return true;
    }
    return false;
}
//w=a-b*c/de+e-f
int main(){
    string str;
    getline(cin,str);

    int pos=str.find("=");

    string left=str.substr(0,pos+1);
    str.erase(0,pos+1);
    int i=1;
    while(any_operator(str)){
        if(str.find("/")!=npos)
            pos=str.find("/");
        else if(str.find("*")!=npos)
            pos=str.find("*");
        else if(str.find("+")!=npos)
            pos=str.find("+");
        else if(str.find("-")!=npos)
            pos=str.find("-");
        int back,front;
        //cout<<pos<<endl;
        //back = pos+1;
        //front=pos-1;
        for(back=pos-1;!is_operator(str[back]) && back>=0;back--){}
        for(front=pos+1;!is_operator(str[front]) && front<str.size();front++){}

        string temp=str.substr(back+1,front-back-1);
        string s="t"+ to_string(i);
        str.replace(back+1,front,s);
        //cout<<front<<back<<endl;
        //cout<<str<<endl;
        cout<<s<<"="<<temp<<endl;
        i++;
    }
    cout<<left<<"t"<<to_string(i-1);
}

