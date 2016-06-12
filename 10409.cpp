#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int ta;
	while(1){
		cin>>ta;
		if(ta==0) break;
		int t,n,w,top,b,s,e;
		string av;
		while(t--){
			cin>>av;
			t=1;
			n=2;
			w=3;
			b=7-t;
			s=7-n;
			e=7-w;
			if(av[0]=='n') { top=7-n; s=7-t; n=t; t=top;}
			if(av[0]=='s') { top=7-s; s=t; n=7-s; t=top;}
			if(av[0]=='e') { top=7-e; w=7-t; e=t; t=top;}
			if(av[0]=='w') { top=7-w; w=t; e=7-w; t=top;}
			
			}
			cout<<top<<endl;
	}
	return 0;
}
