#include <bits/stdc++.h>    //RANK 9 TIME:0s I know its pretty bad ;)
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
template<class ty>void oup(ty x) {
        char s[20];
        short i=0;
        do{
            s[i++]=x%10+'0';
            x/=10;
        }while(x);
        --i;
        while(i>-1)putcx(s[i--]);
}
int main() {
    int n, cnt;
    while(true) {
        n=IN();
        if(!n) return 0;
        char m[10000] = {};
        cnt = 0;
        while(m[n] == 0) {
            cnt++;
            m[n] = 1;
            n = n*n;
            n /= 100;
            n %= 10000;
        }
        oup(cnt);
        puts("");
    }
    return 0;
}
