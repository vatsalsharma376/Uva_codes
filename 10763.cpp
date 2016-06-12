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
 
int floyd(vector<vector<int> > &p,vector<vi >& path, int e){
	for(int k=0;k<e;k++){
		for(int i=0;i<e;i++){
			for(int j=0;j<e;j++){
				if(p[i][k]+p[k][j]<p[i][j]){
				     p[i][j]=p[i][k]+p[k][j]; 
				     path[i][j] = path[k][j];
				}
			}
		}
	}
	return e;
}

int fp(vector<vector<int> >& path,int s,int destination){
    //cout<<destination<<" ";
   
    if(s==destination) cout<< (char) ('A' + destination);                                                                                            
	else {                                          // oh
		fp(path,s,path[s][destination]);                             
		cout <<" " << (char) ('A' + destination);             
	}
	return destination;
}
int main(){
    int m,n; //m--vertices n--edges
    cin>>m>>n;              
    vector<vector<int> > d(m,vector<int>(26,(int)1e9));  
    vector<vector<int> > path(m,vector<int>(26,-1));
    //Mapping characters with numbers a-1 b-2 c-3 4-5
    tt(n){
    	char a,b;
    	int cost;
    	cin>>a>>b>>cost;
     	int x=a-'A',y=b-'A';     
    	d[x][y]=cost;       
    	d[y][x]=cost;
    	path[x][y]=x; 
    	path[y][x]=y;
    }
    floyd(d,path, m);  
    int q;
    cin>>q;
    tt(q){
    	char l,m;
    	cin>>l>>m;
    	
    	int start=l-'A',dest=m-'A';
    	
        fp(path,start,dest); 
        cout << "\n";
    }
    return 0;
}
