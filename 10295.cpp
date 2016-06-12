#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;
    map<string,int> a;
    while(n--){
        string m;
        int k;
        cin>>m;
        cin>>k;
        a[m]=k;
    }
    string w;
    int total;
    for(int j=0;j<t;j++){
        total=0;
        while(cin>>w and w!=".") total+=a[w];
        cout<<total<<endl;
    }
    return 0;
}
