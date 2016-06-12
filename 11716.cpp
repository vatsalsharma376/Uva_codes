
#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new printf("\n")
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())

using namespace std;

int main(){
    
    int t;
    cin>>t;
    getchar();
    string s;

    tt(t){
    	getline(cin,s);
    	double sz;
    	int szi;
    	sz=sqrt(s.length());
    	szi=sqrt(s.length());
    	if(sz!=sz1){
    		cout<<"INVALID\n";
    		continue;
    	}
    	int mat[szi][szi];
    	int p=0;
    	for(int i=0;i<szi;i++){
    		for(int j=0;j<szi;j++){
    			mat[i][j]=s[p];
    			++p;
    		}
    	}

    	for(int i=0;i<szi;i++){
    		for(int j=0;j<szi;j++){
    			cout<<mat[i][j]<<" ";
    		}
    		printf("\n");
    	}
    }

    return 0;
}
