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
/*int IN () {
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
}*/
int queen[8]; int path[8];
bool valid(int r, int c) {
    for(int j = 0; j < r; j++) {
        if(c == path[j]) return false;
        if(abs(r - j) == abs(c - path[j])) return false;
    }
    return true;
}
int solve(int m){
    if(m==8) return 0;
    int ans=999999;
    for(int i=0;i<8;i++){
        if(valid(m,i)){
            path[m]=i;
            ans=min(ans,i==queen[m]?solve(m+1):1+solve(m+1));
        }
    }
    return ans;
}
int main()
{
   // ios_base::sync_with_stdio(false);
    //cin.tie(0);
    string s;
        while(scanf("%d",&queen[0])==1){
            getline(cin,s);
            int i=1;
            stringstream ss(s);
            while(ss>>queen[i]){
                ++i;
            }
            cout<<solve(0)<<endl;  
            
            
        }
    
}
