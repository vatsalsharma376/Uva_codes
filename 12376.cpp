#include <bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked
#define putcx putchar_unlocked
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
    //ios_base::sync_with_stdio(0);
    short tc,n,s,e,k,x,g[105];
    int i,m,l[105];
    long a;
    tc=IN();
    for(k=1;k<=tc;++k){
        n=IN(); m=IN();
        for(i=0;i<n;++i){
            l[i]=IN();
            g[i]=-1;
        }
        while(m--){
            s=IN(); e=IN();
            if(g[s]==-1)g[s]=e;
            else if(l[e]>l[g[s]])g[s]=e;
        }
        a=s=0;
        while(g[s]!=-1){
            s=g[s];
            a+=l[s];
        }
        //cout<<"Case "<<k<<": "<<a<<' '<<s<<'\n';
        printf("Case %d: %d %d\n",k,a,s);
    }
}
