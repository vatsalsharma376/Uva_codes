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


int N, Case = 0, ans[20] = {1};
bool isPrime(int a)         //2,3,5,7,11,13,17,19,23,29,31,37,41}
{
    if(a==2 or a==3 or a==5 or a==7 or a==11 or a==13 or a==17 or a==19 or a==23 or a==31 or a==37 or a==41) return true;
    return false;
}
void backtracking(int L, bool visit[])
{
    if (L == N) {
        if (!isPrime(ans[N-1] + 1))
            return;
        printf("1");
        for (int i = 1; i < N; ++i)
            printf(" %d", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (visit[i]) continue;
        if (isPrime(i + ans[L - 1])) {
            visit[i] = 1;
            ans[L] = i;

            backtracking(L + 1, visit);

            visit[i] = 0;
        }
    }
}
int main()
{
    while (scanf("%d", &N) != EOF) {
        if (Case++) putchar('\n');
        printf("Case %d:\n", Case);
        bool visit[20] = {0};
        backtracking(1, visit);
    }
}
