#include <bits/stdc++.h>
// Vatsal Sharma
// Rank 9
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define si set<int>                      
#define msi map<string, int>
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;
vector<int> parent,r;

vector<pair<int,pair<int,int> > >grp;
int par (int v) {
    return (v == parent[v])?  v : (parent[v] = par(parent[v]));
}
void uni(int a,int b){
    a=par(a);
    b=par(b);       // no rank compression
    
    if(a!=b){
        if(r[a]>r[b]) {r[a]+=r[b]; parent[b]=a; }
        else {r[b]+=r[a]; parent[a]=b;}
    }
}
/*
int joint(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        if(r[x] > r[y])
            r[x] += r[y], p[y] = x;
        else
            r[y] += r[x], p[x] = y;
        return 1;
    }
    return 0;
}
*/
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
    return a.first>b.first;
}
//vector<ii> result;
 int IN () {                                       // REMEMBER TO CHANGE DATATYPE
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
template<class ty>void oup(ty x) {
        char s[20];
        short i=0;
        do{
            s[i++]=x%10+'0';
            x/=10;
        }while(x);
        --i;
        while(i>-1)putcx(s[i--]);
}
int main(){
        int n,m;
        //ios_base::sync_with_stdio(0);
        //cin.tie(0);
        string ass="";
        int t;
        cin>>t;
        while(t--){
        	n=IN(); m=IN();
        
        parent.resize(n);
        r.resize(n);
        ff(n) parent[i]=i,r[i]=1;
        grp.clear();
        ll int xx=0;
        ff(m){
            int x,y,w;
            x=IN(); y=IN(); w=IN(); 
            --x;
            --y;
            grp.pb(make_pair(w,make_pair(x,y)));    // undirected graph
            grp.pb(make_pair(w,make_pair(y,x)));
            xx+=w;
        }
        sort(grp.begin(),grp.end(),cmp);
        ll int cost=0,ans=0;
        ff(grp.size()){
            int x=grp[i].second.first;
            int y=grp[i].second.second;
            int l=grp[i].first;
            if(par(x)!=par(y)){
                ++cost;
               // result.pb(make_pair(x,y));  // answers
                xx-=l;
                uni(x,y);
            }
        
        }
        cout<<xx<<endl;
        }
        
    return 0;
}
