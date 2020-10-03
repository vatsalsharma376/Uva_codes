//Author::Vatsal Sharma
// CLass 9
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define in(x) insert(x)
#define tt(t) while(t--)

int main(){
	int t;
	cin>>t;
	tt(t){
		
		multiset<int> green,blue;
		int b,sg,sb;
		cin>>b>>sg>>sb;
		while(sg--){
			int x;
			cin>>x;
			green.in(x);
		}
		while(sb--){
			int x;
			cin>>x;
			blue.in(x);
		}
		while(!green.empty() and !blue.empty()) {
			std::vector<int> gl,bl; //those who returned power
			int fit=min(b,(int)min(green.size(),blue.size()));
			tt(fit){
				auto it=green.end();
				auto it1=blue.end();
				--it;
				--it1;
				int gs=*it,bs=*it1;
				green.erase(it);
				blue.erase(it1);
				if(gs>bs){
					gl.pb(gs-bs);
				}
				else if(bs>gs){
					bl.pb(bs-gs);
				}
				
			}
			for(auto i:gl) green.insert(i);
				for(auto i:bl) blue.in(i);
		}
		if(green.empty() && !blue.empty()){
			cout<<"blue wins\n";
				for(multiset<int>::reverse_iterator it3=blue.rbegin(); it3!=blue.rend(); it3++)
		cout << *it3 << '\n';
		}
		else if(!green.empty() and blue.empty()){
			cout<<"green wins\n";
			for(multiset<int>::reverse_iterator it4=green.rbegin(); it4!=green.rend(); it4++)
		cout << *it4 << '\n';
		}
		else cout<<"green and blue died\n";
		
	}
}
