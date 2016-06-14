#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)
#define getcx getchar_unlocked
#define pcx putchar_unlocked
#define MX INT_MAX
//int gcd(int a,int b){ if(a==0) return 0; return gcd(b%a,a);}
int IN () {
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


int main(){
    int n;
    while(true){
        
        n=IN();
        if(!n) break;
        deque<int> lis;
        printf("Discarded cards:");
        for(int i=1;i<=n;i++){
            lis.push_back(i);
        }
        int t=0,k=0;
        string s="";
        
        while(lis.size()!=1){
            k=lis.front();
            s+=to_string(k);
            s+=", ";
            lis.pop_front();
            t=lis.front();
            lis.pop_front();
            lis.push_back(t);
        }
         if(s.size()) cout<<" ";
        cout<<s.substr(0,s.size()-2)<<"\n";
        printf("Remaining card: ");
        printf("%d\n",lis.front());
    }
}
