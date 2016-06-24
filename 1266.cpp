#include <bits/stdc++.h>
#define getcx getchar_unlocked
#define putcx putchar_unlocked
    using namespace std;
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
    
     
int fill(int i,int j,int n){
    int k=floor(n/2);
    int ans=(i+j-1+k)%n;
    int ans1=(i+(2*j)-2)%n;
    int final=(n*ans)+ans1+1;
    return final;
    
}
int sum(int n){
    return (((n*n)+1)/2)*n;
}
int dig(int n){
    string k=to_string(n);
    return k.size();
}
int main(){  
    int n;
    bool flag=false;
    while(scanf("%d",&n)==1){
        if(flag) cout<<"\n";
        flag=true;
        int mat[n][n];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mat[i-1][j-1]=fill(i,j,n);
            }
        }
        cout<<"n="<<n<<", sum="<<sum(n)<<endl;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){     
                cout<<setw(dig(n * n)+1)<<mat[i][j];
            }
            cout<<"\n";
        }
        
        
    }

 return 0;  
}
