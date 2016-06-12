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

//bool prime[1000000];
int par[50003];
//int seta[50010];

int ans=0;
int parent(int k){
    if(par[k]==k) return k;
    else return par[k]=parent(par[k]);
}
void unio(int x,int y){
    x=parent(x);
    y=parent(y);
    if(x!=y) ++ans;
    par[y]=x;
    par[x]=x;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n,m;
    int cas=1;
    while(true){
        n=IN();
        m=IN();
        if(!n and !m) break;
        ans=0;
        printf("Case %d: ",cas++);
        ffr(0,n) par[i]=i;
        int i,j;
        //map<int,int> pres;
        while(m--){
            i=IN();
          //  ++pres[i];
            j=IN();
        //    ++pres[j];
            unio(i,j);
        }
       
        printf("%d\n",n-ans);
    }
    
}
