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
int gcd(int a,int b){ if(a==0) return 0; return gcd(b%a,a);}
int readInt () {
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

//bool prime[1000000];

int seta[200010];
int num[200010];
void setit(int p);
void unio(int x,int y);
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    t=readInt();
    while(t--){
        int p;
        p=readInt();
        map<string,int> lis;
        setit(2*p);
        string f1,f2;
        int j=0;
        while(p--){
            cin>>f1>>f2;
            if(!lis[f1]) lis[f1] = ++j;
            if(!lis[f2]) lis[f2] = ++j;
            unio(lis[f1],lis[f2]);
        }
    }
}
void setit(int p){
    ffr(0,p) {
        seta[i]=i;
        num[i]=1;
    }
}
int par(int x){
    if(seta[x]==x) return x;
    else return seta[x] = par(seta[x]);
}
void unio(int x,int y){
    x=par(x);
    y=par(y);
    if(x!=y){
        seta[x]=y;
        num[y]+=num[x];
    }
    cout<<num[y]<<"\n";
}
