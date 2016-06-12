#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(cin>>s){
		list<char> a;
		list<char>::iterator it = a.begin();
		for(int i=0;i<s.size();i++){
			if(s[i]=='[') it=a.begin();
			else if(s[i]==']') it=a.end();
			else a.insert(it,s[i]);
		}
		for(it=a.begin();it!=a.end();it++){
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}
