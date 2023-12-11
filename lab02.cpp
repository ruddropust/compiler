
#include<bits/stdc++.h>

using namespace std;
int comment=0;
int n_letters=0;
int main(){
    string str;
    bool multiline=false;
    do{
        getline(cin,str);
        for(int i=0; i<str.size()  ; i++) {
            if(str[i]=='/' &&str[i+1]=='/'){
                comment++;
                i+=2;
                while(i<str.size()) {
                    if(str[i]!=' ')
                       n_letters++;
                    i++;
                }
                i=0;
                getline(cin,str);
            }
            else if(str[i]=='/' &&str[i+1]=='*'){
                    comment++;
                    for(; str[i-1]!='*' || str[i]!='/'  ; i++){
                    if(str[i]!=' ')
                        n_letters++;
                    if((i+1)==str.size()){
                        i=0;
                        multiline=true;
                        getline(cin,str);
                    }
                }
                n_letters-=3;
            }
        }
    } while (str!="$");
    cout<<"Comment type : ";
    if(multiline){
        cout<<"Multiline\n";
    }
    else if(comment==0)        cout<<"No Comment\n";

    else{
        cout<<"Singleline\n";
    }
    cout<<"Number of comments : "<<comment;
    cout<<"\nNumber of letters : "<<n_letters;

    return 0;
}
