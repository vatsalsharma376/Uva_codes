    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        string s;
        map<string,string> k;
        while(getline(cin,s)){
            if(s.length()==0) break;
            stringstream ss(s);
            string a,b;
            ss>>a>>b;
            k[b]=a;
        }
        string m;
        while(getline(cin,m)){
            if(k[m]=="") cout<<"eh"<<endl;
            else cout<<k[m]<<endl;
        }
        return 0;
    }
