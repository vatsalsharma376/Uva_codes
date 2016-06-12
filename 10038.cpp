#include <bits/stdc++.h>
using namespace std;

int main() {
     int n;
     while(cin>>n){
        vector<int> a;
        vector<int> dif;
        int k;
        while(n--){
            cin>>k;
            
            a.push_back(k);
        }
        for(int i=0;i<a.size()-1;i++){
            dif.push_back(abs(a[i]-a[i+1]));
            
        }
        sort(dif.begin(),dif.end());
        bool flag=true;
        for(int i=0;i<dif.size();i++){
            
            if(dif[i]!=i+1) {
                flag=false;
                break;
            }
        }
        if(flag) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
     }
    return 0;
}
