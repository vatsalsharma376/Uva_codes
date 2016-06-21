#include<bits/stdc++.h>     // RANK 315 TIME:: 0.010 seconds :P
using namespace std;
#define ll long long 
#define vi vector<int> 
#define pb push_back
#define ff(x,y) for(int i=x;i<y;i++)
#define ffr(x,y) for(int i=x;i<=y;i++)     
#define getcx getchar_unlocked
#define putcx putchar_unlocked            
#define MX INT_MAX
unsigned long long int IN () {
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
void oupx(unsigned long long int x){
    char s[20];
    short i = 0;
    do{
        s[i++] = x % 10 + '0';
        x /= 10;
    }while(x);
    --i;
    while(i > -1)putcx(s[i--]);
}

//using namespace std;

//typedef vector<int> vi;

int main()
{
    int p=0;
    int n;
    while(true){
        n=IN();
        if(!n) return 0;
        //cout<<"Case "<<++p<<":\n";
        printf("Case %d:\n",++p);
        int lis[n];
        for(int i=0;i<n;i++) lis[i]=IN();
        int m=IN(),q;
        while(m--){
            
            q=IN();
            //cout<<"Closest sum to "<<q<<" is ";
            printf("Closest sum to %d is ",q);
            int mi=429496725;
            int ans=0;
            int ab=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ab=abs(lis[i]+lis[j]-q);
                    if(mi>ab){
                        mi=ab;
                        ans=lis[i]+lis[j];
                    }
                    
                }
            }
            //cout<<ans<<".\n";
            oupx(ans);
            printf(".\n");
        }
    }
	return 0;
}
