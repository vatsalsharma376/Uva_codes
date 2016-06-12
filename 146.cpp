#include <bits/stdc++.h>
using namespace std;

int main() {
char s[59];
    while(1){
        cin>>s;
        if(s[0]=='#') break;
        char l=strlen(s);
        if(next_permutation(s,s+l)){
            cout<<s<<endl;
            
        }
        else {
            cout<<"No Successor"<<endl;
        }
    }
    return 0;
}
