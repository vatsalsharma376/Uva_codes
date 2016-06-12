#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
int x1=-1,x2;
	 while(cin>>s){
        x1=-1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z') x2=2;
            else if(s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V') x2=1;
            else if(s[i]=='D'||s[i]=='T') x2=3;
            else if(s[i]=='M'||s[i]=='N') x2=5;
            else if(s[i]=='L') x2=4;
            else if(s[i]=='R') x2=6;
            else x2=-1;
            
            if(x2!=x1 && x2!=-1) cout<<x2;
            
            x1=x2;
        }
        cout<<endl;        
    }
}
