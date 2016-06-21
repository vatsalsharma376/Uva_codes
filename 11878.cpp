#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)     
#define getcx getchar_unlocked
#define putcx putchar_unlocked            
#define MX INT_MAX
unsigned long long int IN () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getcx();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getcx();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getcx();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
void oupx(unsigned long long int x){
    char s[20];
    short i = 0;
    do{
        s[i++] = x % 10 + '0';
        x /= 10;
    }while(x);
    --i;
    while(i > -1)putcx(s[i--]);
}

//using namespace std;

//typedef vector<int> vi;

int main()
{
    int ans=0;
    string s;
    while(cin>>s){
        int enda=0;
        char op;
        string as=""; // a is first
        for(int i=0;i<s.size();i++){
            if(s[i]!='-' and s[i]!='+'){
                as+=s[i];
            } 
            else {
                op=s[i];
                enda=i+1;
                break;
            }
        }
        string bs="";
        for(int i=enda;i<s.size();i++){
            if(s[i]!='=') bs+=s[i];
            else{
                enda=i+1;
                break;
            }
        }
        string cs="";
        for(int i=enda;i<s.size();i++){
            cs+=s[i];
        }
        if(cs=="?"){
            continue;
        }
        int ra=stoi(as),rb=stoi(bs),rc=stoi(cs);
        if(op=='+'){
            if(ra+rb==rc) ++ans;
            
        }
        else{
            if(ra-rb==rc) ++ans;
        }
        //cout<<as<<" "<<bs<<" "<<cs<<endl;
        
    }
    cout<<ans<<endl;
	return 0;
}
