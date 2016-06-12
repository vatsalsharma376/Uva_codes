#include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	int t,n;
    	cin>>t;
    	getchar();
    	getchar();
    	int p=t;
    	while(t--){
    	map<string,int> a;//no of tree
    	set<string> k;//list of trees
    		string s1;
    	set<string>::iterator it;
    		n=0;
    		while(getline(cin,s1)){
    			if(s1.length()==0) {break;}
    			a[s1]++;
    			++n;
    			k.insert(s1);
    		}
    		for(it=k.begin();it!=k.end();it++){
    			cout<<*it<<" ";
    			printf("%.4f\n",100.00*a[*it]/n);
    		}
    		--p;
    		
    		if(p!=0)cout<<"\n";
    	}	
    }
