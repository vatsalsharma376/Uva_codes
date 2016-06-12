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
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;
/*
Sample  Input

1

3
2

Sample   Output

1
22
333
22
1

1
22
333
22
1

*/
int main(){
    int t;
    cin>>t;
    tt(t){
        int w,f;
        cin>>w>>f;
        tt(f){
            for(int i=1;i<=w;i++){
                for(int j=1;j<=i;j++){
                    cout<<i;
                }
                printf("\n");
            }
            for(int i=w-1;i>=1;i--){
                for(int j=1;j<=i;j++){
                    cout<<i;
                }
               printf("\n");
            }
           if(t or f) printf("\n");
        }
       
    }
    return 0;
}
