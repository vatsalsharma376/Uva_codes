#include<bits/stdc++.h>
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

int count(int n) {
    char s[12];
    sprintf(s, "%d", n);
    int i, sum = 0;
    for(i = 0; s[i]; i++)
        sum += s[i]-'0';
    return sum;
}
int C(int n) {
    int i, ans;
    int digits1 = count(n), digits2 = 0, flag = 1;
    ans = n;
    for(i = 2; i <= (int)sqrt(n); i++) {
        if(n%i == 0) {
            int time = 0;
            while(n%i == 0) {
                time++;
                n /= i;
            }
            digits2 += time*count(i);
            flag = 0;
        }
    }
    if(n != 1)
        digits2 += count(n);
    if(digits1 == digits2 && flag == 0) {
        oupx(ans);
        puts("");
        return 1;
    }
    return 0;
}
int main() {
    int i;
    int T, n;
    T=IN();
    while(T--) {
        n=IN();
        for(i = n+1; ; i++)
            if(C(i) == 1)
                break;
    }
    return 0;
}
