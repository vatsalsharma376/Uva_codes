#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new printf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;

int main(){
    int n;
    cout<<"PERFECTION OUTPUT\n";
    while(cin>>n and n){
        int sum=0;
        int ind=0;
        if(n<=9) ind=4;
        else if(n>9 and n<100) ind=3;
        else if(n>99 and n<1000) ind=2;
        else if(n>999 and n<10000) ind=1;
        else ind=0;
        ff(ind) cout<<" ";
        for(int i=1;i<=(n/2);i++) 
        if(n%i==0) sum+=i;
        cout<<n<<"  ";
        if(n==sum) cout<<"PERFECT\n";
        else if(sum<n) cout<<"DEFICIENT\n";
        else cout<<"ABUNDANT\n";
        
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
