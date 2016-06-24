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
    
     

int main(){  
    int t=IN();
    
    while(t--){
        int n;
        n=IN();
        //if(!n) return 0;
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++) {
            v[i]=IN();
            sum+=v[i];
        }
        if(sum%2!=0){
            cout<<"No\n";
            continue;
        }
        sort(v.rbegin(),v.rend());
        if(n==1){
            if(v[0]!=0) {
                cout<<"No\n";
            continue;
            }
        }
        bool flag = true;
        for(int k=0; k<n; k++)
        {
            int sumdi = 0;
            for(int i=0; i<k; i++)
                sumdi = sumdi + v[i];
            int prok = k * (k-1);
            int summin = 0;
            for(int j=k; j<n; j++)
                summin = summin + min(v[j],k);
            int tot = prok + summin;
            if(sumdi>tot)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;  
}
