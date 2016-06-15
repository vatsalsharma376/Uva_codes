#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)
#define getcx getchar_unlocked
#define pcx putchar_unlocked
#define MX INT_MAX
//int gcd(int a,int b){ if(a==0) return 0; return gcd(b%a,a);}
int IN () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getcx();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getcx();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getcx();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
bool chk(int i,int j ,int n ,int m){
    if(i<0 or j<0 or i>=n or j>=m) return false;
    return true;
}
int main(){
    
    int n,m,ins;
    while(true){
        int dir=0;
        n=IN(); m=IN(); ins=IN();       // North-- 0   South --- 1    East----2      West --- 3 
        if(!n or !m) return 0;
        char mat[n][m];
        int curi=0,curj=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                //cout<<mat[i][j];
                if(isalpha(mat[i][j])){
                    curi=i; curj=j;
                    if(mat[i][j]=='N') dir=0;
                    else if(mat[i][j]=='S') dir=1;
                    else if(mat[i][j]=='L') dir=2;
                    else if(mat[i][j]=='O') dir=3;
                    //mat[i][j]='.';
                }
            }
            //cout<<endl;
        }
        //cout<<curi<<" "<<curj<<endl;
        getcx();
        string str;
        getline(cin,str);
        //cout<<str<<endl;
        int ans=0;
        for(int i=0;i<ins;i++){
            
            if(str[i]=='D'){
                // TURN 90 degrees to right
                if(dir==0) dir=2;
                else if(dir==1) dir=3;
                else if(dir==2) dir=1;
                else if(dir==3) dir=0;
                
            }
            else if(str[i]=='E'){
                //cout<<dir<<endl;
                // TURN 90 degrees to left
                if(dir==0) dir=3;
                else if(dir==1) dir=2;
                else if(dir==2) dir=0;
                else if(dir==3) dir=1;
                //cout<<dir<<endl;
            }
            else {
                // MOVE FORWARD
                //if(!chk(curi,curj,n,m) or mat[curi][curj]=='#') curi=curi;
                
                    if(dir==0){
                        --curi;
                        if(!chk(curi,curj,n,m) or mat[curi][curj]=='#') ++curi;
                        if(mat[curi][curj]=='*') {
                            ++ans;
                            mat[curi][curj]='.';
                        }
                        
                    }
                    else if(dir==1){
                        //cout<<dir<<endl;
                        ++curi;
                        if(!chk(curi,curj,n,m) or mat[curi][curj]=='#') --curi;
                        if(mat[curi][curj]=='*') {
                            ++ans;
                            mat[curi][curj]='.';
                        }
                        
                    }
                    else if(dir==2){
                        ++curj;
                        if(!chk(curi,curj,n,m) or mat[curi][curj]=='#') --curj;
                        if(mat[curi][curj]=='*') {
                            ++ans;
                           mat[curi][curj]='.';
                        }
                        
                    }
                    else {
                        --curj;
                        if(!chk(curi,curj,n,m) or mat[curi][curj]=='#') ++curj;
                        if(mat[curi][curj]=='*') {
                            ++ans;
                            mat[curi][curj]='.';
                        }
                        
                    }
                
                }
            //cout<<dir<<endl;
        }
        //cout<<curi<<" "<<curj<<endl;
        printf("%d\n",ans);
        
        
    }
    return 0;
}
