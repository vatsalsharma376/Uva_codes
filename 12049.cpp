#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    map<int,int> f;
    map<int,int>::iterator it;
    int n,m;
    cin>>n>>m;
    while(n--){
    	int k;
    	cin>>k;
    	f[k]++;
    }
    while(m--){
    	int k;
    	cin>>k;
    	f[k]--;
    }
    int min=0;
    for(it=f.begin();it!=f.end();it++){
    	min+=abs(it->second);
    }
    cout<<min<<endl;
    }
    return 0;
}
