#include <bits/stdc++.h>
using namespace std;

int main()
{  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        string str;
        cin>>str;
        //cout<<str<<endl;
        map<string,int>mymap;
        map<string,int>::iterator it;
        for(int i=0;i<str.length()-n+1;i++) mymap[str.substr(i,n)]++;
        int max=-999999;
        string res="";
        for(it=mymap.begin();it!=mymap.end();it++)
        {
            if((*it).second>max){ res=(*it).first;max=(*it).second; }
        }
        cout<<res<<"\n";
    }
    return 0;
}
