//Author::Vatsal Sharma
// CLass 9
#include <bits/stdc++.h>
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define new cout<<endl

using namespace std;
int main(){
        int n;
        while(1){
        	cin>>n;
        	int ad2a=1;
        	bool ad=true;
        	if(!n) break;
        	int a=0,b=0;
        	while(n){
        		
        			if(ad) a+=ad2a;
        			else b+=ad2a;
        			
        			ad=!ad;
        		
        		ad2a*=2;
        		n/=2;
        		
        	}
        cout<<a<<" "<<b<<endl;
        }
        
}
