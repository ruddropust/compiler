#include<bits/stdc++.h>

using namespace std;
vector<string> tokens;
int comment=0;
vector<string>key,special,constant,variable,oprtr;
bool is_separator(char ch){
    string str = " ,;:(){}[]";
    string tmp;
    for(int i=0;i<str.size();i++){
        if(ch==str[i]){
            if(ch!=' '){
                tmp.push_back(ch);
                special.push_back(tmp);
            }
            return true;
        }
    }return false;
}

bool is_constant(string s){
    bool valid = true;
    for(int i=0;i<s.length();i++){
        if((s[i]>='0'&&s[i]<='9')||(s[i]=='.'))
            continue;
        else{
            valid =false;break;
        }
    }
    return valid;
}

bool is_operator(char ch){
    string str = "+-*/%=><!&|";
    for(int i=0;i<str.size();i++){
        if(ch==str[i]){
            return true;
        }
    }return false;
}
bool is_keyword(string s) {
    vector<string> keyword = {"auto", "break", "case", "char", "const", "continue", "default",
                              "do", "double", "else", "enum", "extern", "float", "for", "goto",
                              "if", "int", "long", "register", "return", "short", "signed",
                              "sizeof", "static", "struct", "switch", "typedef", "union",
                              "unsigned", "void", "volatile", "while"};

    auto f = find(keyword.begin(),keyword.end(),s);
    if(f==keyword.end()){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    string str;

    do{
        string temp="";
        getline(cin,str);
        for(int i=0; i<str.size() ; i++) {
            if(str[i]=='/' &&str[i+1]=='/'){
                comment++;
                i=0;
                getline(cin,str);
            }
            else if(str[i]=='/' &&str[i+1]=='*'){
                comment++;
                bool flag=false;
                for(; i<str.size() && !flag ; i++){
                    if(str[i-1]=='*' && str[i]=='/'){
                        flag=true;
                        break;
                    }
                    if((i+1)==str.size()){
                        i=0;
                        getline(cin,str);
                    }
                }
            }
            else if(is_separator(str[i])){
              if(temp!="")
              tokens.push_back(temp);
              temp="";
             }
            else if(is_operator(str[i]) && is_operator(str[i+1])){
                if(temp!="")
                    tokens.push_back(temp);
                temp="";
                temp.push_back(str[i]);
                temp.push_back(str[i+1]);
                oprtr.push_back(temp);
                temp="";
                i++;
             }
            else if(is_operator(str[i])){
                if(temp!="")
                    tokens.push_back(temp);
                temp="";
                temp.push_back(str[i]);
                oprtr.push_back(temp);
                temp="";
            }
            else {
                temp += str[i];
          }
        }
    }
    while(str!="$");

    for(string it : tokens){
        if(is_keyword(it)){
            key.push_back(it);
        }
        else if(is_constant(it)){
            constant.push_back(it);
        }
        else{
            variable.push_back(it);
        }
    }

    cout<<"Identifier : ";
    for(string it : variable){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"keywords : ";
    for(string it : key){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Operators : ";
    for(string it : oprtr){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Constants : ";
    for(string it : constant){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Special characters : ";
    for(string it : special){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Comments : "<<comment;
    cout<<endl;
}
