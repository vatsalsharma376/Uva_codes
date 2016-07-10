#include <bits/stdc++.h>
using namespace std;
#define getcx getchar_unlocked
#define putcx putchar_unlocked
long int IN () {
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


int coins[102];
int d[102][50005];

int main()
{
	int T=IN();
	
	for(int t=0;t<T;t++)
	{
		int m=IN();
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			coins[i]=IN();
			sum += coins[i];
		}
		coins[0] = 0;
		int mm = sum/2;
		for(int i=0;i<=mm;i++)
		{
			d[0][i] = 0;
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<=mm;j++)
			{
				if( coins[i] <= j )
				{
					d[i][j] = max( d[i-1][j] , d[i-1][j-coins[i]] + coins[i] );
				}
				else
				{
					d[i][j] = d[i-1][j];
				}
			}
		}
		oup(sum-2*d[m][mm]);
		puts("");
	}
	return 0;
}
